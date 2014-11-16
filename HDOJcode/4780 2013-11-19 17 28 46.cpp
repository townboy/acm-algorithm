******************************
    Author : townboy
    Submit time : 2013-11-19 17:28:46
    Judge Status : Accepted
    HDOJ Runid : 9623778
    Problem id : 4780
    Exe.time : 390MS
    Exe.memory : 888K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

#define maxn 400
#define maxe 50000

typedef long long LL;
int tt[110][2];
int c[110][110], d[110][110], e[110][110], f[110][110];
int nn ,mm ,kk;

LL mincost ,dist[maxn];
int net[maxn], size, maxflow ;
int n , pre[maxn], pe[maxn];
bool hash[maxn];
queue<int> q;

#define INF 0x3f3f3f3fLL

struct xx {
    int v ,next;
    int cap;
    int cost;
    xx() {}
    xx (int v,int next ,int cap, int cost) 
        : v(v), next(next), cap(cap), cost (cost) {}
};
xx edge[maxe];

void init() {
    size = 0;
    memset(net, -1, sizeof(net));
}

void add(int u,int v ,int cap,int cost) {
    edge[size] = xx(v ,net[u], cap, cost);
    net[u] = size ++;
    edge[size] = xx(u, net[v], 0, -cost);
    net[v] = size ++;
}

int spfa(int s,int t) {
    while(!q.empty() ) 
        q.pop();
    memset(hash, 0, sizeof(hash));
    memset(pre, -1, sizeof(pre));
    for(int i = 1;i <= n;i++)
        dist[i] = INF;
    dist[s] = 0;
    hash[s] = 1;
    q.push(s);
    while(!q.empty() ) {
        int u = q.front();
        q.pop();
        hash[u] = 0;
        for(int i = net[u]; i != -1;i = edge[i].next) {
            int v = edge[i].v;
            if(edge[i].cap && dist[v] > dist[u] + edge[i].cost) {
                dist[v] = dist[u] + edge[i].cost;
                pre[v] = u;
                pe[v] = i;
                if(0 == hash[v]) {
                    hash[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    if(-1 == pre[t])
        return 0;
    return 1;
}

void mcmf(int s,int t) {
    maxflow = 0;
    mincost = 0;
    while(1 == spfa(s,t) ) {
        int aug = INF;
        for(int v = t;v != s; v = pre[v])
            aug = min(aug, edge[pe[v]].cap);
        maxflow += aug;
        mincost += dist[t] * aug;
        for(int v = t;v != s;v = pre[v]) {
            edge[pe[v]].cap -= aug;
            edge[pe[v]^1].cap += aug;
        }
    }
}

void read() {
    for(int i = 1 ;i <= nn; i++) 
        scanf("%d%d",&tt[i][0], &tt[i][1]);
    for(int i = 1 ;i <= nn; i++) 
        for(int f = 1;f <= mm;f++)
            scanf("%d",&c[i][f]);
    for(int i = 1 ;i <= nn; i++) 
        for(int f = 1;f <= mm;f++)
            scanf("%d",&d[i][f]);
    for(int i = 1;i <= nn;i ++)
        for(int f = 1;f <= nn;f++)
            scanf("%d",&e[i][f]);
    for(int i = 1;i <= nn;i++)
        for(int g = 1;g <= nn;g++)
            scanf("%d",&f[i][g]);
}

int fun1(int x,int y) {
    if(c[y][x] >= tt[y][1])
        return -1;
    int ret = d[y][x];
    if(c[y][x] > tt[y][0])
        ret += kk * (c[y][x] - tt[y][0]);
    return ret;
}

int fun2(int x,int y) {
    int end = tt[x][1] + e[x][y];
    if(end >= tt[y][1])
        return -1;
    int cost = f[x][y];
    if(end >= tt[y][0])
        cost += kk * (end - tt[y][0]);
    return cost;
}

int cost[110][110];

int getid(int x) {
    return mm + x;
}

LL solve() {
    init();
    n = mm + 2 * nn + 2;
    int s = n - 1;
    int t = n;

    for(int i = 1;i <= nn ;i++)
        for(int f = 1;f <= nn;f++)
            if(i != f)
                cost[i][f] = fun2(i,f);
            else 
                cost[i][f] = -1;

    for(int i = 1;i <= nn ;i++)
        add(getid(i) , getid(i) + nn, 1, -INF);

    for(int i = 1;i <= mm; i++) {
        add(s, i, 1, 0);
        add(i, t, 1, 0);
        for(int f = 1;f <= nn; f++) {
            int ret = fun1(i, f);
            if(-1 == ret)
                continue;
            add(i, getid(f), 1, ret);
        }
    }

    for(int i = 1;i <= nn; i++) {
        for(int f = 1;f <= nn; f++) {
            if(-1 == cost[i][f])
                continue;
            add(getid(i) + nn, getid(f), 1, cost[i][f]);
        }
        add(getid(i) + nn ,t ,1, 0);
    }

    mcmf(s, t);
    mincost += nn * INF;
    if(mincost < INF)
        return mincost;
    return -1;
}

int main() {
    while(cin >> nn >> mm >> kk ,nn + mm + kk) {
        read();
        cout << solve() << endl;
    }
    return 0;
}


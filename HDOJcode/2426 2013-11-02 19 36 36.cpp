******************************
    Author : townboy
    Submit time : 2013-11-02 19:36:36
    Judge Status : Accepted
    HDOJ Runid : 9484111
    Problem id : 2426
    Exe.time : 828MS
    Exe.memory : 720K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <vector>

using namespace std;

#define maxn 1100
#define maxe 110000

int net[maxn],size, maxflow, mincost;
int n ,dist[maxn], pre[maxn], pe[maxn];
bool hash[maxn];
queue<int>q;

struct xx {
    int v, next;
    int cap;
    int cost;
    xx () {}
    xx (int v,int next,int cap,int cost)
        : v(v), next (next) , cap(cap), cost(cost) {}
};
struct xx edge[maxe];

void init() {
    size = 0;
    memset(net,-1,sizeof(net));
}

void add(int u,int  v,int cap,int cost) {
    edge[size] = xx(v, net[u],cap,cost);
    net[u] = size ++;
    edge[size] = xx (u,net[v],0,-cost);
    net[v] = size ++;
}

#define INF 0x3f3f3f3f

int spfa(int s,int t) {
    while(!q.empty()) q.pop();
    memset(hash,0,sizeof(hash));
    memset(pre,-1,sizeof(pre));

    for(int i = 1;i <= n;i++)
        dist[i] = INF;
    dist[s] = 0;
    hash[s] = 1;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        hash[u] = 0;
        for(int i = net[u];i != -1;i = edge[i].next) {
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
    while(1 == spfa(s,t)) {
        int aug = INF;
        for(int v = t;v != s ;v = pre[v])
            aug = min(aug,edge[pe[v]].cap );
        maxflow += aug;
        mincost += dist[t] * aug;
        for(int v = t;v != s;v = pre[v]) {
            edge[pe[v]].cap -= aug;
            edge[pe[v]^1].cap += aug;
        }
    }
}

int nn ,mm ,ee;

void read() {
    n = nn + mm + 2;
    int s = n - 1;
    int t = n;
    int u ,v, w;
    for(int i = 0;i < ee;i++) {
        scanf("%d%d%d",&u,&v,&w);
        u ++ ;
        v ++ ;
        if(w >= 0)
            add(u,nn + v, 1, -w);
    }
    for(int i = 1;i <= nn;i++) 
        add(s, i, 1, 0);
    for(int i = nn + 1;i <= nn + mm ;i++)
        add(i, t, 1, 0);
}

int solve() {
    mcmf( n - 1, n);
    if(nn != maxflow)
        return -1;
    return -mincost;
}

int main() {
    int cas = 0;
    while(cin >> nn >> mm >> ee) {
        init();
        read();
        cas ++;
        printf("Case %d: ",cas);
        cout << solve() << endl;
    }
    return 0;
}


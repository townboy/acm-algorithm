******************************
    Author : townboy
    Submit time : 2013-10-31 09:18:05
    Judge Status : Accepted
    HDOJ Runid : 9461801
    Problem id : 3718
    Exe.time : 62MS
    Exe.memory : 400K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;

#define INF 0x3f3f3f3f
#define maxn 100
#define maxe 10000

int net[maxn],size, maxflow,mincost;
int n ,dist[maxn], pre[maxn],pe[maxn];
bool hash[maxn];
queue<int> q;

struct xx {
    int v ,next;
    int cap;
    int cost;
    xx() {}
    xx(int v,int next,int cap,int cost)
        : v(v),next(next),cap(cap),cost(cost) {}
};
struct xx edge[maxe];

void mcmf_init() {
    size = 0;
    memset(net, -1,sizeof(net));
}

void add(int u,int v,int cap,int cost) {
    edge[size] = xx(v,net[u],cap,cost);
    net[u] = size ++;
    edge[size] = xx(u,net[v],0,-cost);
    net[v] = size ++;
}

int spfa(int s,int t) {
    while(! q.empty() ) q.pop();
    memset(hash,0,sizeof(hash));
    memset(pre,-1,sizeof(pre));
    for(int i = 1;i <= n;i++) dist[i] = INF;
    dist[s] = 0;
    hash[s] = 1;
    q.push(s);
    while( ! q.empty()) {
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
        for(int v = t;v != s;v = pre[v])
            aug = min(aug, edge[pe[v]].cap);
        maxflow += aug;
        mincost += dist[t] * aug;
        for(int v = t;v != s;v = pre[v]) {
            edge[pe[v]].cap -= aug;
            edge[pe[v]^1].cap += aug;
        }
    }
}

int nn , mm ,kk;
int A[10010], B[10010];
int val[26][26];

void debug() {
    for(int i = 0;i < 26;i++) {
        for(int f = 0 ;f < 26;f++)
            cout << val[i][f] <<  " ";
        cout << endl;
    }
}

int main() {
    char ch[5];
    int cas, tt;
    cin >> cas;
    for(int i = 0 ;i < cas;i++ ) {
        cin >> nn >> kk >> mm;
        for(int f = 0 ;f < nn;f++) {
            scanf("%s",ch);
            A[f] = ch[0] - 'A';
        }

        for(int f = 0 ;f < mm;f++) {

            for(int g = 0 ;g < nn; g++) {
                scanf("%s",ch);
                B[g] = ch[0] - 'A';
            }

            memset(val, 0, sizeof(val));
            for(int g = 0 ;g < nn; g++)
                val[A[g]][B[g]] ++;

            n = 2 + 26 * 2;
            mcmf_init();
            int s = n - 1;
            int t = n;
            for(int g = 1;g <= 26;g++) {
                add(s, g, 1, 0);
                add(26 + g , t, 1, 0);
            }
            for(int g = 1;g <= 26;g++)
                for(int h = 1;h <= 26;h ++)
                    add(g,26 + h, 1, - val[g-1][h-1]);
            mcmf(s, t);
            printf("%.4lf\n", - mincost / (double) nn);
        }
    }
    return 0;
}


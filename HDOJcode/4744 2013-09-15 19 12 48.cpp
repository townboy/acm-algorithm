******************************
    Author : townboy
    Submit time : 2013-09-15 19:12:48
    Judge Status : Accepted
    HDOJ Runid : 9174693
    Problem id : 4744
    Exe.time : 906MS
    Exe.memory : 632K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<algorithm>
#include<memory.h>
#include<iostream>
#include<math.h>
#include<queue>

using namespace std;

#define maxn 210
#define maxm 100000
#define INF 0x3f3f3f3f
const int inf = 0x7fffffff;

struct MaxFlow
{
    int size, n;
    int st, en, maxflow, mincost;
    bool vis[maxn];
    int net[maxn], pre[maxn], cur[maxn], dis[maxn];
    std::queue <int> Q;
    struct EDGE
    {
        int v, cap, cost, next;
        EDGE(){}
        EDGE(int a, int b, int c, int d)
        {
            v = a, cap = b, cost = c, next = d;
        }
    }E[maxm<<1];
    void init(int _n)
    {
        n = _n, size = 0;
        memset(net, -1, sizeof(net));
    }
    void add_edge(int u, int v, int cap, int cost)
    {
        E[size] = EDGE(v, cap, cost, net[u]);
        net[u] = size++;
        E[size] = EDGE(u, 0, -cost, net[v]);
        net[v] = size++;
    }
    bool adjust()
    {
        int v, min = inf;
        for(int i = 0; i <= n; i++)
        {
            if(!vis[i])
                continue;
            for(int j = net[i]; v = E[j].v, j != -1; j = E[j].next)
                if(E[j].cap)
                    if(!vis[v] && dis[v]-dis[i]+E[j].cost < min)
                        min = dis[v] - dis[i] + E[j].cost;
        }
        if(min == inf)
            return false;
        for(int i = 0; i <= n; i++)
            if(vis[i])
                cur[i] = net[i], vis[i] = false, dis[i] += min;
        return true;
    }
    int augment(int i, int flow)
    {
        if(i == en)
        {
            mincost += dis[st] * flow;
            maxflow += flow;
            return flow;
        }
        vis[i] = true;
        for(int j = cur[i], v; v = E[j].v, j != -1; j = E[j].next)
        {
            if(!E[j].cap)
                continue;
            if(vis[v] || dis[v]+E[j].cost != dis[i])
                continue;
            int delta = augment(v, std::min(flow, E[j].cap));
            if(delta)
            {
                E[j].cap -= delta;
                E[j^1].cap += delta;
                cur[i] = j;
                return delta;
            }
        }
        return 0;
    }
    void spfa()
    {
        int u, v;
        for(int i = 0; i <= n; i++)
            vis[i] = false, dis[i] = inf;
        dis[st] = 0;
        Q.push(st);
        vis[st] = true;
        while(!Q.empty())
        {
            u = Q.front(), Q.pop();
            vis[u] = false;
            for(int i = net[u]; v = E[i].v, i != -1; i = E[i].next)
            {
                if(!E[i].cap || dis[v] <= dis[u] + E[i].cost)
                    continue;
                dis[v] = dis[u] + E[i].cost;
                if(!vis[v])
                {
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
        for(int i = 0; i <= n; i++)
            dis[i] = dis[en] - dis[i];
    }
    int zkw(int s, int t)
    {
        st = s, en = t;
        spfa();
        mincost = maxflow = 0;
        for(int i = 0; i <= n; i++)
            vis[i] = false, cur[i] = net[i];
        do
        {
            while(augment(st, inf))
                memset(vis, false, sizeof(vis));
        }while(adjust());
        return mincost;
    }
};
MaxFlow townboy;

int pos[110][3];
int w[110];
int nn;
int sum ;

void read() {
    sum = 0;
    for(int i = 1;i <= nn;i++) {
        for(int f = 0; f < 3;f++)
            scanf("%d",&pos[i][f]);
        scanf("%d",w+i);
        sum += w[i];
    }
}

int G[110][110];

int dis(int x,int y) {
    int sum = 0;
    for(int i = 0;i < 3;i++) 
        sum += (pos[x][i] - pos[y][i])*(pos[x][i] - pos[y][i]);
    return (int)sqrt((double)sum);
}

void yu() {
    for(int i = 1;i <= nn;i++)
        for(int f = i+1;f <= nn;f++)
            G[i][f] = G[f][i] = dis(i,f);
}

int solve() {
    int s = 2*nn+1;
    int t = 2*nn+2;
    yu();
    townboy.init(2*nn+2);
    for(int i = 1;i <= nn;i++)
        for(int f = 1;f <= nn;f++) {
            if(i == f)
                continue;
            townboy.add_edge(i,f+nn,INF,G[i][f]);
        }
    for(int i = 1;i <= nn;i++) {
        townboy.add_edge(s,i,w[i],0);
        townboy.add_edge(i+nn,t,w[i],0);
    }
    return townboy.zkw(s,t);
}

bool check() {
    int maxx = 0;
    for(int i = 1;i <= nn;i++)
        maxx = max(w[i],maxx);
    if(2*maxx > sum)
        return true;
    return false;
}

int main() {
    while(scanf("%d",&nn) , nn) {
        read();
        if(true == check()) {
            puts("-1");
            continue;
        }
        printf("%d\n",solve());
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2014-05-18 23:15:31
    Judge Status : Accepted
    HDOJ Runid : 10765132
    Problem id : 3987
    Exe.time : 31MS
    Exe.memory : 2688K
    https://github.com/townboy
******************************


#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int N = 1005;
const int INF = 1<<30;

struct Edge
{
    int v,next,cap;
}edge[200010];

int head[N],cnt;

void addedge(int u,int v,int w1,int w2)
{
    u --;
    v --;
    edge[cnt].v = v;
    edge[cnt].cap = w1;
    edge[cnt].next = head[u];
    head[u] = cnt++;
    edge[cnt].v = u;
    edge[cnt].cap = w2;
    edge[cnt].next = head[v];
    head[v] = cnt++;
}

void read(int &ret)
{
    char c;
    do
    {
        c = getchar();
    }
    while(c<'0'||c>'9');
    ret = c - '0';
    while((c=getchar())>='0'&&c<='9')
        ret = ret*10 + c - '0';
}

void init()
{
    cnt = 0;
    memset(head,-1,sizeof(head));
}

int SAP(int s,int t,int n)
{
    int pre[N],dis[N],gap[N],cur[N];
    int u,v,f;
    int aug = -1;
    int maxflow = 0;
    memcpy(cur,head,sizeof(head));
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    u = pre[s] = s;
    gap[0] = n;
    while(dis[s] < n)
    {
        loop:
            for(int &i = cur[u]; i+1; i = edge[i].next)
            {
                v = edge[i].v;
                f = edge[i].cap;
                if(f&&dis[u]==dis[v]+1)
                {
                    if(aug==-1||aug>f)
                        aug = f;
                    pre[v] = u;
                    u = v;
                    if(v==t)
                    {
                        maxflow += aug;
                        for(u = pre[u]; v!=s; v = u, u = pre[u])
                        {
                            edge[cur[u]].cap -= aug;
                            edge[cur[u]^1].cap += aug;
                        }
                        aug = -1;
                    }
                    goto loop;
                }
            }
            int mindis = n;
            for(int i = head[u]; i+1; i = edge[i].next)
            {
                v = edge[i].v;
                if(edge[i].cap&&mindis>dis[v])
                {
                    cur[u] = i;
                    mindis = dis[v];
                }
            }
            if(--gap[dis[u]]==0)
                break;
            gap[dis[u] = mindis+1]++;
            u = pre[u];
    }
    return maxflow;
}

bool dir[100010];

int main()
{
    int _,n,m,u,v,w,c,s,t;
    read(_);
    for(int cas = 1; cas <= _; cas++)
    {
        read(n);
        read(m);
        init();
        for(int i = 0; i < m; i++)
        {
            read(u);
            read(v);
            read(w);
            read(c);
            dir[i] = c;
            u++;
            v++;
            if(c)
                addedge(u,v,w,w);
            else
                addedge(u,v,w,0);
        }
        s = 1;
        t = n;
        SAP(s - 1,t - 1,t);
        for(int i = 0; i < cnt; i += 2)
        {
            if(dir[i/2])
            {
                if(!edge[i].cap||!edge[i+1].cap)
                    edge[i].cap = edge[i+1].cap = 1;
                else
                    edge[i].cap = edge[i+1].cap = INF;
            }
            else
            {
                if(!edge[i].cap)
                    edge[i].cap = 1;
                else
                    edge[i].cap = INF;
                edge[i+1].cap = 0;
            }
        }
        int ans = SAP(s - 1,t - 1,t);
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}

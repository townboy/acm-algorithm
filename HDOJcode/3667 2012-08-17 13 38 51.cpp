******************************
    Author : townboy
    Submit time : 2012-08-17 13:38:51
    Judge Status : Accepted
    HDOJ Runid : 6585822
    Problem id : 3667
    Exe.time : 468MS
    Exe.memory : 748K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<queue>
#include<algorithm>
using namespace std;

#define INF 0x7fffffff
#define maxn 150
#define maxe 60000

int net[maxn],size,maxflow,mincost;
int n,k;//µãÊý 
int dist[maxn];
int pre[maxn];
int pe[maxn];
bool hash[maxn];
queue<int>q;
    
struct xx
{
    int v,next;
    int cap;
    int cost;
};
struct xx edge[maxe];

void chu()
{
    size=0;
    memset(net,-1,sizeof(net));
}

void add(int u,int v,int cap,int cost)
{
    edge[size].v=v;
    edge[size].cap=cap;
    edge[size].cost=cost;
    edge[size].next=net[u];
    net[u]=size++;
    
    edge[size].v=u;
    edge[size].cap=0;
    edge[size].cost=-cost;
    edge[size].next=net[v];
    net[v]=size++;
}

int spfa(int s,int t)
{
    int i,u,v;
    while(!q.empty()) 
    {
        q.pop();
    }
    memset(hash,0,sizeof(hash));
    memset(pre,-1,sizeof(pre));
    for(i=1;i<=n;i++) 
    {
        dist[i]=INF;
    }
    dist[s]=0;
    hash[s]=1;
    q.push(s);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        hash[u]=0;
        for(i=net[u];i!=-1;i=edge[i].next)
        {
            v=edge[i].v;
            if(edge[i].cap && dist[v]>dist[u]+edge[i].cost)
            {
                dist[v]=dist[u]+edge[i].cost;
                pre[v]=u; 
                pe[v]=i;
                if(0 == hash[v])
                {
                    hash[v]=1;
                    q.push(v);
                }
            }
        }
    }
    if(-1 == pre[t]) 
    {
        return 0;
    }
    return 1;
}

void mcmf(int s,int t)
{
    int i,aug,v;
    maxflow=0;
    mincost=0;
    while(1 == spfa(s,t))
    {
        aug=INF;
        for(v=t;v!=s;v=pre[v])
        {
            aug=min(aug,edge[pe[v]].cap);
        }
        maxflow+=aug;
        mincost+=dist[t]*aug;
        if(maxflow == k)
        {
            break;
        }
        for(v=t;v!=s;v=pre[v])
        {
            edge[pe[v]].cap-=aug;
            edge[pe[v]^1].cap+=aug;
        }
    }
}

void bulid(int u,int v,int a,int c)
{
    int i;
    for(i=1;i<=c;i++)
    {
        add(u,v,1,a*(2*i-1));    
    }
}

int main()
{
    int nn,u,v,a,c,s,t,m,i;
    while(scanf("%d%d%d",&nn,&m,&k)!=EOF)
    {
        chu();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&u,&v,&a,&c);
            bulid(u,v,a,c);
        }
        n=nn;
        s=1;
        t=n;
        mcmf(s,t);
        if(maxflow < k)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",mincost);
        }
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-08-19 19:40:12
    Judge Status : Accepted
    HDOJ Runid : 6607355
    Problem id : 2485
    Exe.time : 15MS
    Exe.memory : 372K
    https://github.com/townboy
******************************


////////////////////O£¨VE^2£©
//  Èç¹ûÒªÇó×î´ó·ÑÓÃµÄ»° Ö»ÐèÔÚ¼Ó±ßµÄÊ±ºò¼Ó-µÄ±ß  Êä³öÊ±Êä³ö-ans¼´¿É

#include<stdio.h>
#include<memory.h>
#include<queue>
#include<algorithm>
using namespace std;

#define INF 0x7fffffff
#define maxn 110
#define maxe 11000

int net[maxn],size,maxflow,mincost;
int n;//µãÊý 
int dist[maxn];
int pre[maxn];
int pe[maxn];
bool hash[maxn];
queue<int>q;

int k;
    
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
    while(1 == spfa(s,t) && dist[t]<=k)
    {
        aug=INF;
        for(v=t;v!=s;v=pre[v])
        {
            aug=min(aug,edge[pe[v]].cap);
        }
        maxflow+=aug;
        mincost+=dist[t]*aug;
        for(v=t;v!=s;v=pre[v])
        {
            edge[pe[v]].cap-=aug;
            edge[pe[v]^1].cap+=aug;
        }
    }
}

int main()
{
    int u,v,i,m,nn,s,t;
    while(scanf("%d%d%d",&nn,&m,&k),nn+m+k)
    {
        chu();
        n=2*nn;
        s=nn+1;
        t=nn;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            add(u+nn,v,INF,1);
        }
        for(i=1;i<=nn;i++)
        {
            add(i,i+nn,1,0);
        }
        mcmf(s,t);
        printf("%d\n",maxflow);
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-08-18 21:34:34
    Judge Status : Accepted
    HDOJ Runid : 6600849
    Problem id : 2448
    Exe.time : 625MS
    Exe.memory : 2160K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<queue>
#include<algorithm>
using namespace std;

#define INF 0x7fffffff
#define maxn 400
#define maxe 2100000

int net[maxn],size,maxflow,mincost;
int n;//µãÊý 
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
        for(v=t;v!=s;v=pre[v])
        {
            edge[pe[v]].cap-=aug;
            edge[pe[v]^1].cap+=aug;
        }
    }
}

int main()
{
    int nn,mm,i,x,u,v,len,k,p,s,t;
    while(scanf("%d%d%d%d",&nn,&mm,&k,&p)!=EOF)
    {
        chu();
        n=nn+mm+2;
        s=nn+mm+1;
        t=nn+mm+2;
        
        for(i=1;i<=nn;i++)
        {
            scanf("%d",&x);
            add(s,x,1,0);    
        }
        for(i=0;i<k;i++)
        {
            scanf("%d%d%d",&u,&v,&len);
            add(u,v,INF,len);
            add(v,u,INF,len);
        }    
        for(i=0;i<p;i++)
        {
            scanf("%d%d%d",&u,&v,&len);
            u+=mm;
            add(v,u,1,len);
        }
        for(i=mm+1;i<=nn+mm;i++)
        {
            add(i,t,1,0);
        }
        
        mcmf(s,t);
        printf("%d\n",mincost);
    }
    return 0;
}
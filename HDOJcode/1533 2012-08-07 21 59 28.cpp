******************************
    Author : townboy
    Submit time : 2012-08-07 21:59:28
    Judge Status : Accepted
    HDOJ Runid : 6475212
    Problem id : 1533
    Exe.time : 437MS
    Exe.memory : 660K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<queue>
#include<algorithm>
using namespace std;

#define INF 0x7fffffff
#define maxn 500
#define maxe 110000

char map[110][110];
int net[maxn],size,maxflow,mincost,id[110][110];
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

struct node 
{
    int x;
    int y;
};
struct node que[250];

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

void debug()
{
    int i,f;
    for(i=0;i<size;i++)
    {
        printf("%d %d %d\n",edge[i].v,edge[i].cost,edge[i].cap); 
    } 
    printf("\n"); 
} 

void build(int nn,int mm)
{
    int i,f,ji=0,g,u,v,cost; 
    for(i=1;i<=nn;i++)
    {
        for(f=1;f<=mm;f++)
        {
            if('H' == map[i][f])
            {
                ji++;                            
                que[ji].x=i;
                que[ji].y=f;
                id[i][f]=ji; 
            }
        }
    }
    u=ji;
    for(i=1;i<=nn;i++)
    {
        for(f=1;f<=mm;f++)
        {
            if('m' == map[i][f])
            {
                u++;            
                for(g=1;g<=ji;g++)
                {
                    v=id[que[g].x][que[g].y];
                    cost=abs(i-que[g].x)+abs(f-que[g].y); 
                    add(v,u,1,cost);
                }
            }            
        }
    }
    for(i=1;i<=ji;i++)
    {
        add(2*ji+1,i,1,0);
        add(i+ji,2*ji+2,1,0); 
    }
    n=2*ji+2; 
    mcmf(2*ji+1,2*ji+2);    
}

int main()
{
    int i,f,nn,mm,ji;
    while(scanf("%d%d",&nn,&mm),0 != nn+mm)
    {
        getchar();
        chu();
        ji=0;
        for(i=1;i<=nn;i++)
        {
            for(f=1;f<=mm;f++)
            {
                scanf("%c",&map[i][f]);    
                if('.' != map[i][f])
                {
                    ji++;
                }
            }
            getchar();
        }
        build(nn,mm);
        printf("%d\n",mincost);
    }
    return 0;
}
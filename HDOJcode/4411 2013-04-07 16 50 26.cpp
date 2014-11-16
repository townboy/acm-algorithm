******************************
    Author : townboy
    Submit time : 2013-04-07 16:50:26
    Judge Status : Accepted
    HDOJ Runid : 8022408
    Problem id : 4411
    Exe.time : 46MS
    Exe.memory : 484K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<queue>
#include<algorithm>
using namespace std;

#define INF 0x3f3f3f3f
#define maxn 1100
#define maxe 1100000

int k,nn,m;
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

int mcmf(int s,int t)
{    
    int ans=INF;
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
        ans=min(ans,mincost+100000*nn);
        for(v=t;v!=s;v=pre[v])
        {
            edge[pe[v]].cap-=aug;
            edge[pe[v]^1].cap+=aug;
        }
        if(k == maxflow)
            break;
    }
    return ans;
}

int map[105][105];

void debug()
{
    int i,f;
    for(i=0;i<=nn;i++)
    {
        for(f=0;f<=nn;f++)
            printf("%d ",map[i][f]);
        printf("\n");
    }
    printf("==== debug ===== \n");
}

void floyd()
{
    int i,f,g;
    for(g=0;g<=nn;g++)
        for(i=0;i<=nn;i++)
            for(f=0;f<=nn;f++)
                map[i][f]=min(map[i][g]+map[g][f],map[i][f]);
}

void init()
{
    memset(map,0x3f,sizeof(map));
}

void build()
{
    int ans,s,t,f,i;
    chu();
    n=2*nn+2;
    s=n-1;
    t=n;
    for(i=1;i<=nn;i++)
        add(s,i,INF,map[0][i]);
    for(i=1;i<=nn;i++)
        add(i,i+nn,1,-100000);
    for(i=1;i<=nn;i++)
        add(i+nn,t,INF,map[0][i]);
    for(i=1;i<=nn;i++)
        for(f=i+1;f<=nn;f++)
            add(i+nn,f,INF,map[i][f]);
    ans=mcmf(s,t);
    printf("%d\n",ans);
}

int main()
{
    int u,v,len;
    int i;
    while(scanf("%d%d%d",&nn,&m,&k),nn+m+k)
    {
        init();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&len);
            map[u][v]=min(map[u][v],len);
            map[v][u]=map[u][v];
        }
        floyd();
        build();
    }
    return 0;
}
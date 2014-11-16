******************************
    Author : townboy
    Submit time : 2012-08-08 14:16:29
    Judge Status : Accepted
    HDOJ Runid : 6480765
    Problem id : 2686
    Exe.time : 0MS
    Exe.memory : 392K
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
#define maxn 2000
#define maxe 11000

int map[40][40],nn;
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

void debug()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        printf("%d ",dist[i]);
    } 
    puts(""); 
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

int turn(int x,int y)
{
    return 2*((x-1)*nn+y); 
}

void build()
{
    int i,f,u,v;
    for(i=1;i<=nn;i++)
    {
        for(f=1;f<=nn;f++)
        {
            v=turn(i,f)-1;
            if(i-1>0 && f>0)
            {
                u=turn(i-1,f);
                add(u,v,1,-map[i][f]);
            }
            if(i>0 && f-1>0)
            {
                u=turn(i,f-1);
                add(u,v,1,-map[i][f]);
            }
            if((1 == i&& 1 == f)||(nn == i && nn == f))
            {
                add(v,v+1,2,0); 
                continue; 
            } 
            add(v,v+1,1,0);
        }    
    }
    n=2*nn*nn+2; 
    add(2*nn*nn+1,1,2,-map[1][1]);
    add(2*nn*nn,2*nn*nn+2,2,0); 
    mcmf(2*nn*nn+1,2*nn*nn+2);
}

int main()
{
    int i,f;
    while(scanf("%d",&nn)!=EOF)
    {
        chu();
        for(i=1;i<=nn;i++)
        {
            for(f=1;f<=nn;f++)
            {
                scanf("%d",&map[i][f]);    
            }
        }
        build();
        printf("%d\n",-mincost-(map[1][1]+map[nn][nn]));
    }
    return 0;
}
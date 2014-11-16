******************************
    Author : townboy
    Submit time : 2012-08-16 21:27:50
    Judge Status : Accepted
    HDOJ Runid : 6579871
    Problem id : 3395
    Exe.time : 187MS
    Exe.memory : 432K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;

#define INF 0x7fffffff
#define maxn 220
#define maxe 30000

int net[maxn],size,maxflow,mincost;
int n;//µãÊý 
int dist[maxn];
int pre[maxn];
int pe[maxn];
bool hash[maxn];
queue<int>q;

int map[110]; 
    
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
    int tem,i,f,val,len,s,t,nn;
    char ch[110];
    while(scanf("%d",&nn),nn)
    {
        chu();
        n=2*nn+3;
        s=2*nn+1;
        t=2*nn+2;
        tem=2*nn+3;
        for(i=1;i<=nn;i++)
        {
            scanf("%d",&val);
            add(s,i,1,0);
            add(i+nn,t,1,0);
            add(i,tem,1,0);
            map[i]=val;
        }
        add(tem,t,INF,0);
        for(i=1;i<=nn;i++)
        {
            scanf("%s",ch);
            len=strlen(ch);
            for(f=0;f<len;f++)
            {
                if('1' == ch[f])
                {
                    add(i,f+1+nn,1,-(map[i]^map[f+1]));
                }
            }
        }
        mcmf(s,t);
        printf("%d\n",-mincost);
    }
    return 0;
}
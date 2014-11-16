******************************
    Author : townboy
    Submit time : 2013-04-12 23:25:11
    Judge Status : Accepted
    HDOJ Runid : 8068440
    Problem id : 4280
    Exe.time : 4234MS
    Exe.memory : 8916K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<queue>
#include<iostream>
#define maxn 100010
#define maxe 2100000
#define INF 0x3f3f3f3f

using namespace std;

int n,m,s,t;
int size,net[maxn];
int gap[maxn];//gapÓÅ»¯ 
int dist[maxn];//¾àÀë±êºÅ 
int pre[maxn];//Ç°Çý 
int curedge[maxn];//µ±Ç°»¡ 
int hash[maxn];

struct node
{
    int v,next;
    int cap;
    int flow;
};
struct node edge[maxe];

void init()
{
    size=0;
    memset(net,-1,sizeof(net));
}

void add(int u,int v,int cap)
{
    edge[size].v = v;
    edge[size].cap = cap;
    edge[size].flow = 0;
    edge[size].next = net[u];
    net[u] = size;
    ++size;

    edge[size].v = u;
    edge[size].cap = 0;
    edge[size].flow = 0;
    edge[size].next = net[v];
    net[v] = size;
    ++size;
}

struct node2 
{
    int id,dis;
    friend bool operator < (node2 a,node2 b){
        return a.dis > b.dis;
    }
};
struct node2 tem,ru;

void bfs()
{
    priority_queue<node2>que;
    int i,u,dis;
    memset(dist,0x3f,sizeof(dist));
    memset(hash,0,sizeof(hash));
    tem.id=t;
    tem.dis=0;
    que.push(tem);
    while(!que.empty())
    {
        tem=que.top(),que.pop();
        u=tem.id,dis=tem.dis;
        if(1 == hash[u])    continue;
        dist[u]=dis;
        hash[u]=1;
        for(i=net[u];i!=-1;i=edge[i].next)
        {
            if(0 == edge[i].cap)    continue;
            if(1 == hash[edge[i].v])    continue;
            ru.id=edge[i].v,ru.dis=dis+1;
            que.push(ru);
        }
    }
    for(i=0;i<=n;i++)
        gap[min(n+1,dist[i])]++;
}

int isap()
{
    int curflow,u,temp,neck,i;
    int maxflow;
    memset(gap,0,sizeof(gap));
    memset(pre,-1,sizeof(pre));
    memset(dist,0,sizeof(dist));
    for(i=1;i<=n;i++) 
        curedge[i]=net[i];//½«µ±Ç°»¡³õÊ¼»°³ÉÁÚ½Ó±íµÄµÚÒ»Ìõ±ß 
    bfs();
    maxflow=0;
    u=s;
    while(dist[s] < n)
    {
        if(u==t)
        {        //ÕÒµ½Ò»ÌõÔö¹ãÂ· 
            curflow=INF;
            for(i=s;i!=t;i=edge[curedge[i]].v)    //ÑØ×ÅÔö¹ãÂ·ÕÒµ½×îÐ¡Ôö¹ãÁ÷Á¿ 
                if(curflow > edge[curedge[i]].cap)
                {
                    neck=i;
                    curflow=edge[curedge[i]].cap;
                }
            for(i=s;i!=t;i=edge[curedge[i]].v)
            {    //¸üÐÂ 
                temp=curedge[i];
                edge[temp].cap-=curflow;
                edge[temp].flow+=curflow;
                temp^=1;
                edge[temp].cap+=curflow;
                edge[temp].flow-=curflow;
            }
            maxflow+=curflow;
            u=neck;//ÏÂ´ÎÖ±½Ó´Ó¹Ø¼ü±ßµÄu¿ªÊ¼ÐÂÒ»ÂÖµÄÔö¹ã 
        }
        for(i=curedge[u];i!=-1;i=edge[i].next)//ÕÒµ½Ò»ÌõÔÊÐí»¡ 
            if(edge[i].cap>0 && dist[u]==dist[edge[i].v]+1)    break;
        if(i!=-1)    //Èç¹ûÕÒµ½ ½«uÖ¸Ïòv 
        {
            curedge[u]=i;
            pre[edge[i].v]=u;
            u=edge[i].v;
        }
        else
        {        //ÕÒ²»µ½ 
            if(0 == --gap[dist[u]])    break;//³öÏÖ¶Ï²ã
            curedge[u] = net[u];//°Ñµ±Ç°»¡ÖØÐÂÉèÎªÁÚ½Ó±íÖÐÂú×ãÒªÇóµÄµÚÒ»Ìõ»¡
            for(temp=n,i=net[u];i!=-1;i=edge[i].next)
                if(edge[i].cap > 0)
                    temp=temp<dist[edge[i].v]?temp:dist[edge[i].v];
            dist[u]=temp+1;//½«Õâ¸öµãµÄ¾àÀë±êºÅÉèÎªÓÉËü³ö·¢µÄËùÓÐ»¡µÄÖÕµãµÄ¾àÀë±êºÅµÄ×îÐ¡Öµ¼Ó1
            gap[dist[u]]++;
            if(u != s)
                u=pre[u];
        }
    }
    return maxflow;
}

int main()
{
    int east,west;
    int u,v,cap;
    int i,cas,f;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        init();
        scanf("%d%d",&n,&m);
        s=t=1;
        west=INF;
        east=-INF;
        for(f=1;f<=n;f++)
        {
            scanf("%d%d",&u,&v);
            if(u < west)
                west=u,s=f;
            if(u > east)
                east=u,t=f;
        }
        for(f=0;f<m;f++)
        {
            scanf("%d%d%d",&u,&v,&cap);
            add(u,v,cap);
            add(v,u,cap);
        }
        printf("%d\n",isap());
    }
}
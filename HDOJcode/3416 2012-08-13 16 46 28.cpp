******************************
    Author : townboy
    Submit time : 2012-08-13 16:46:28
    Judge Status : Accepted
    HDOJ Runid : 6541778
    Problem id : 3416
    Exe.time : 93MS
    Exe.memory : 4632K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<queue>
#define maxn 1100
#define maxe 2100000
#define INF 0x7fffffff
using namespace std;

int n,m,s,t,nn,road;
int size,net[maxn];
int gap[maxn];//gapÓÅ»¯ 
int dist[maxn];//¾àÀë±êºÅ 
int pre[maxn];//Ç°Çý 
int curedge[maxn];//µ±Ç°»¡ 

int len[110000],next[110000],first[1100],id[110000];
int dis[1100];

struct node
{
    int v,next;
    int cap;
    int flow;
};
struct node edge[maxe];

void chu()
{
    road=0;
    size=0;
    memset(net,-1,sizeof(net));
    memset(first,-1,sizeof(first));
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

int isap()
{
    int curflow,u,temp,neck,i;
    int maxflow;
    memset(gap,0,sizeof(gap));
    memset(pre,-1,sizeof(pre));
    memset(dist,0,sizeof(dist));
    for(i=1;i<=n;i++) 
    {
        curedge[i]=net[i];//½«µ±Ç°»¡³õÊ¼»°³ÉÁÚ½Ó±íµÄµÚÒ»Ìõ±ß 
    }
    gap[0]=n;    //gap[nv]=nv; ´í
    maxflow=0;
    u=s;
    while(dist[s] < n)
    {
        if(u==t)
        {        //ÕÒµ½Ò»ÌõÔö¹ãÂ· 
            curflow=INF;
            for(i=s;i!=t;i=edge[curedge[i]].v)
            {    //ÑØ×ÅÔö¹ãÂ·ÕÒµ½×îÐ¡Ôö¹ãÁ÷Á¿ 
                if(curflow > edge[curedge[i]].cap)
                {
                    neck=i;
                    curflow=edge[curedge[i]].cap;
                }
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
        {
            if(edge[i].cap>0 && dist[u]==dist[edge[i].v]+1)
            {
                break;
            }
        }
        if(i!=-1)    //Èç¹ûÕÒµ½ ½«uÖ¸Ïòv 
        {
            curedge[u]=i;
            pre[edge[i].v]=u;
            u=edge[i].v;
        }
        else
        {        //ÕÒ²»µ½ 
            if(0 == --gap[dist[u]]) 
            {
                break;//³öÏÖ¶Ï²ã
            }
            curedge[u] = net[u];//°Ñµ±Ç°»¡ÖØÐÂÉèÎªÁÚ½Ó±íÖÐÂú×ãÒªÇóµÄµÚÒ»Ìõ»¡
            for(temp=n,i=net[u];i!=-1;i=edge[i].next)
            {
                if(edge[i].cap > 0)
                {
                    temp=temp<dist[edge[i].v]?temp:dist[edge[i].v];
                }
            }
            dist[u]=temp+1;//½«Õâ¸öµãµÄ¾àÀë±êºÅÉèÎªÓÉËü³ö·¢µÄËùÓÐ»¡µÄÖÕµãµÄ¾àÀë±êºÅµÄ×îÐ¡Öµ¼Ó1
            gap[dist[u]]++;
            if(u != s)
            {    
                u=pre[u];
            }
        }
    }
    return maxflow;
}

void spfa()
{
    int hash[1100]; 
    int tem,i,u,v;
    queue<int>q;
    for(i=1;i<=nn;i++)
    {
        hash[i]=0; 
        dis[i]=INF;
    }
    dis[s]=0;
    q.push(s);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        hash[u]=0; 
        tem=first[u];    
        while(-1 != tem)
        {
            v=id[tem];
            if(dis[u]+len[tem] < dis[v])
            {
                dis[v]=dis[u]+len[tem]; 
                if(0 == hash[v])
                {
                    hash[v]=1;
                    q.push(v); 
                }
            }
            tem=next[tem]; 
        }
    }
}

void build()
{
    int i,tem,v; 
    n=nn; 
    for(i=1;i<=nn;i++)
    {
        tem=first[i];
        while(-1 != tem)
        {
            v=id[tem]; 
            if(dis[v]-dis[i] == len[tem])
            {
                add(i,v,1); 
            }
            tem=next[tem];
        }
    } 
}

void debug()
{
    int i;
    for(i=1;i<=nn;i++)
    {
        printf("%d ",dis[i]); 
    } 
    printf("\n"); 
} 

int main()
{
    int dis,i,f,num,u,v;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        chu();
        scanf("%d%d",&nn,&m);
        for(f=0;f<m;f++)
        {
            scanf("%d%d%d",&u,&v,&dis);
            len[road]=dis;
            next[road]=first[u];
            first[u]=road;        
            id[road]=v;
            road++;
        }
        scanf("%d%d",&s,&t);
        spfa();
        build();        
        printf("%d\n",isap());
    }
    return 0;
}
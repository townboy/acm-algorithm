******************************
    Author : townboy
    Submit time : 2012-08-18 20:08:57
    Judge Status : Accepted
    HDOJ Runid : 6600121
    Problem id : 2883
    Exe.time : 31MS
    Exe.memory : 316K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#define maxn 1100
#define maxe 1100000
#define INF 0x7fffffff

int n,s,t;
int size,net[maxn];
int gap[maxn];//gapÓÅ»¯ 
int dist[maxn];//¾àÀë±êºÅ 
int pre[maxn];//Ç°Çý 
int curedge[maxn];//µ±Ç°»¡ 

int id[440],nn,m;

struct xx
{
    int v,next;
    int cap;
    int flow;
};
struct xx edge[maxe];

struct node 
{
    int s;
    int t;
    int sum;
};
struct node order[440];

void chu()
{
    size=0;
    memset(net,-1,sizeof(net));
}

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
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

void build()
{
    int i,f;
    n=3*nn+2;
    s=3*nn+1;
    t=3*nn+2;

    for(i=1;i<=nn;i++)
    {
        add(s,i,order[i].sum);
        for(f=1;f<=2*nn;f++)
        {
            if(id[f] == order[i].s)
            {
                 break;
            }
        }
        for(;;f++)
        {
            if(id[f] == order[i].t)
            {
                break;    
            }
            add(i,f+nn,INF);
        }
    }
    for(i=1;i<2*nn;i++)
    {
        add(i+nn,t,(id[i+1]-id[i])*m);
    }
}

int main()
{
    int i,a,b,sum;
    while(scanf("%d%d",&nn,&m)!=EOF)
    {
        chu();
        sum=0;
        for(i=1;i<=nn;i++)
        {
            scanf("%d%d%d%d",&order[i].s,&a,&order[i].t,&b);
            order[i].sum=a*b;
            sum+=a*b;
            id[i]=order[i].s;
            id[i+nn]=order[i].t;
        }
        qsort(&id[1],2*nn,sizeof(id[0]),cmp);
        
        build();
        if(sum == isap())
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-08-01 22:06:28
    Judge Status : Accepted
    HDOJ Runid : 6405053
    Problem id : 3549
    Exe.time : 62MS
    Exe.memory : 296K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#define MAXN 20
#define MAXE 2100
#define INF 0x7fffffff

int n,m,s,t;
int size,net[MAXN];

struct node
{
    int v,next;
    int cap;
    int flow;
};
struct node edge[MAXE];

void chu()
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

int gap[MAXN];//gapÓÅ»¯ 
int dist[MAXN];//¾àÀë±êºÅ 
int pre[MAXN];//Ç°Çý 
int curedge[MAXN];//µ±Ç°»¡ 

int isap(){
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

int main()
{
    int i,f,num,u,v,w;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&n,&m);
        chu();
        s=1;
        t=n;
        for(f=0;f<m;f++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
        }
        printf("Case %d: %d\n",i+1,isap());
    }
}
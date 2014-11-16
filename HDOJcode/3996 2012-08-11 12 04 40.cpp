******************************
    Author : townboy
    Submit time : 2012-08-11 12:04:40
    Judge Status : Accepted
    HDOJ Runid : 6517405
    Problem id : 3996
    Exe.time : 62MS
    Exe.memory : 1456K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#define maxn 2600
#define maxe 300000
#define INF (__int64)1<<60

int n,m,s,t,ji;
int size,net[maxn];
int gap[maxn];//gapÓÅ»¯ 
int dist[maxn];//¾àÀë±êºÅ 
int pre[maxn];//Ç°Çý 
int curedge[maxn];//µ±Ç°»¡ 

int id[110][30];

struct node
{
    int v,next;
    __int64 cap;
    __int64 flow;
};
struct node edge[maxe];

void chu()
{
    size=0;
    memset(id,0,sizeof(id));
    memset(net,-1,sizeof(net));
    ji=2;
    s=1;
    t=2;
}

void add(int u,int v,__int64 cap)
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

__int64 isap()
{
    int u,temp,neck,i;
    __int64 maxflow,curflow;
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
    __int64 sum,x,y,val;
    int i,f,g,layout,gold,a,b,h,k,num;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        chu();
        sum=0;
        scanf("%d",&layout);
        for(f=1;f<=layout;f++)
        {
            scanf("%d",&gold);
            for(g=1;g<=gold;g++)
            {
                ji++;
                id[f][g]=ji;
                scanf("%I64d%I64d%d",&x,&y,&k);
                val=y-x;
                if(0 < val)
                {
                    add(s,id[f][g],val);
                    sum+=val;
                }
                if(0 > val)
                {
                    add(id[f][g],t,-val);
                } 
                for(h=0;h<k;h++)
                {
                    scanf("%d%d",&a,&b);
                    add(id[f][g],id[a][b],INF);
                }
            }    
        }
        n=ji;
        printf("Case #%d: %I64d\n",i+1,sum-isap());
    }
    return 0;
}
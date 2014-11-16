******************************
    Author : townboy
    Submit time : 2012-08-03 01:02:41
    Judge Status : Accepted
    HDOJ Runid : 6419644
    Problem id : 4183
    Exe.time : 0MS
    Exe.memory : 300K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#define maxn 310
#define maxe 1000000
#define INF 0x7fffffff

struct xx
{
    double color;
    int x;
    int y;
    int rad;
};
struct xx que[310];

int n,s,t;
int size,net[maxn];
int gap[maxn];//gapÓÅ»¯ 
int dist[maxn];//¾àÀë±êºÅ 
int pre[maxn];//Ç°Çý 
int curedge[maxn];//µ±Ç°»¡ 

struct node
{
    int v,next;
    int cap;
    int flow;
};
struct node edge[maxe];

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

int main()
{
    int num,i,f,g;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        chu();
        for(f=1;f<=n;f++)
        {
            scanf("%lf%d%d%d",&que[f].color,&que[f].x,&que[f].y,&que[f].rad);
            for(g=1;g<=f;g++)
            {
                if((que[f].rad+que[g].rad)*(que[f].rad+que[g].rad) < (que[f].x-que[g].x)*(que[f].x-que[g].x)+(que[f].y-que[g].y)*(que[f].y-que[g].y) )
                {
                    continue;
                }
                if(que[f].color < que[g].color)
                {
                    add(f,g,1);
                }
                if(que[f].color > que[g].color)
                {
                    add(g,f,1);
                }
            }    
            if(400 == que[f].color)
            {
                s=f;
            }
            if(789 == que[f].color)
            {
                t=f;
            }
        }
        if(isap() >= 2)
        {
            printf("Game is VALID\n");
        }
        else
        {
            printf("Game is NOT VALID\n");
        }
    }
    return 0;
}
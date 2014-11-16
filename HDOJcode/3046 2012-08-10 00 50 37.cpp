******************************
    Author : townboy
    Submit time : 2012-08-10 00:50:37
    Judge Status : Accepted
    HDOJ Runid : 6502421
    Problem id : 3046
    Exe.time : 62MS
    Exe.memory : 3284K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#define maxn 41000
#define maxe 200000
#define INF 0x7fffffff

int n,m,s,t,nn,mm,map[210][210];
int size,net[maxn];
int gap[maxn];//gapÓÅ»¯ 
int dist[maxn];//¾àÀë±êºÅ 
int pre[maxn];//Ç°Çý 
int curedge[maxn];//µ±Ç°»¡ 

int dir[4][2]={0,-1,0,1,1,0,-1,0};

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

int turn(int x,int y)
{
    return (x-1)*mm+y;
}

void debug()
{
    int i,f;
    for(i=1;i<=nn;i++)
    {
        for(f=1;f<=mm;f++)
        {
            printf("%d ",map[i][f]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int i,f,u,v,g,nx,ny,cas=0;
    while(scanf("%d%d",&nn,&mm)!=EOF)
    {
        chu();
        n=nn*mm+2;
        for(i=1;i<=nn;i++)
        {
            for(f=1;f<=mm;f++)
            {
                scanf("%d",&map[i][f]);
                if(2 == map[i][f])
                {
                    add(nn*mm+1,turn(i,f),INF);
                }
                if(1 == map[i][f])
                {
                    add(turn(i,f),nn*mm+2,INF);
                }
                u=turn(i,f);        
                for(g=0;g<4;g++)
                {
                    nx=i+dir[g][0];
                    ny=f+dir[g][1];
                    if(nx < 1 || nx> nn || ny> mm || ny < 1)
                    {
                        continue;    
                    }
                    v=turn(nx,ny);
                    add(u,v,1);
                }
            }
        }
        s=nn*mm+1;
        t=nn*mm+2;
        cas++;
        printf("Case %d:\n",cas);
        printf("%d\n",isap());
    }
    return 0;
}
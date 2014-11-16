******************************
    Author : townboy
    Submit time : 2012-08-17 22:21:20
    Judge Status : Accepted
    HDOJ Runid : 6592834
    Problem id : 2732
    Exe.time : 0MS
    Exe.memory : 560K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define maxn 1000
#define maxe 2100000
#define INF 0x7fffffff

int n,m,s,t,nn;
int size,net[maxn];
int gap[maxn];//gapÓÅ»¯
int dist[maxn];//¾àÀë±êºÅ
int pre[maxn];//Ç°Çý
int curedge[maxn];//µ±Ç°»¡

int id[30][30],d;
char ch[30],pillar[30][30];

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
    memset(id,0,sizeof(id));
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

void build(int x,int y)
{
    int i,f,flag=0;
    for(i=x-d;i<=x+d;i++)
    {
        for(f=y-d;f<=y+d;f++)
        {    
            if(abs(i-x)+abs(f-y) > d)
            {
                continue;
            }
            if(0 == abs(i-x)+abs(f-y))
            {
                continue;
            }
            if(i < 1 || i > nn || f < 0 || f >= m)
            {
                if(0 == flag)
                {
                    add(id[x][y]+1,t,INF);
                    flag=1;            
                }
            }
            if('0' != pillar[i][f])
            {
                add(id[x][y]+1,id[i][f],INF);
            }
        }
    }
}

void debug()
{
    int i,f;
    for(i=1;i<=nn;i++)
    {
        for(f=0;f<m;f++)
        {
            printf("%d ",id[i][f]);
        }
        printf("\n");        
    }
}

int main()
{
    int ji,i,f,g,num,sum,ans;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        chu();
        sum=0;
        scanf("%d%d",&nn,&d);
        getchar();
    
        ji=3;
        s=1;
        t=2;
    
        for(f=1;f<=nn;f++)
        {
            gets(pillar[f]);
            m=strlen(pillar[f]);
            for(g=0;g<m;g++)
            {
                if('0' != pillar[f][g])
                {
                    id[f][g]=ji;
                    ji+=2;
                    add(id[f][g],id[f][g]+1,pillar[f][g]-'0');
                }
            }
        }
        n=ji;
    
        for(f=1;f<=nn;f++)
        {    
            gets(ch);    
            for(g=0;g<m;g++)
            {
                if('L' == ch[g])
                {
                    add(s,id[f][g],1);                
                    sum++;
                }
                if('0' != pillar[f][g])
                {
                    build(f,g);
                }
            }
        }
            
        ans=sum-isap();
        if(0 == ans)
        {
            printf("Case #%d: no lizard was left behind.\n",i+1);
        }
        else if(1 == ans)
        {
            printf("Case #%d: %d lizard was left behind.\n",i+1,ans);
        }
        else
        {
            printf("Case #%d: %d lizards were left behind.\n",i+1,ans);
        }    
    }
    return 0;
}
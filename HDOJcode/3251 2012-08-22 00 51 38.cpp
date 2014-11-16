******************************
    Author : townboy
    Submit time : 2012-08-22 00:51:38
    Judge Status : Accepted
    HDOJ Runid : 6627638
    Problem id : 3251
    Exe.time : 718MS
    Exe.memory : 3360K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#define maxn 1100
#define maxe 210000
#define INF 0x7fffffff

int n,s,t;
int size,net[maxn];
int gap[maxn];//gapÓÅ»¯ 
int dist[maxn];//¾àÀë±êºÅ 
int pre[maxn];//Ç°Çý 
int curedge[maxn];//µ±Ç°»¡ 

int nn,mm,ff,hash[2100],order[110000];

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
    memset(hash,0,sizeof(hash));
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

void dfs(int x)
{
    int tem;
    if(1 == hash[x])
    {    
        return ;
    }
    hash[x]=1;
    tem=net[x];
    while(-1 != tem)
    {
        if(0 == edge[tem].cap)
        {
            tem=edge[tem].next;
            continue;    
        }
        dfs(edge[tem].v);
        tem=edge[tem].next;
    }
}

void print()
{
    int tem,i,sum=0;
    for(i=1;i<=nn;i++)
    {
        tem=net[i];
        while(-1 != tem)
        {
            if(1 == (1&tem))
            {
                tem=edge[tem].next;
                continue;
            }
            if(tem/2+1 > mm)
            {
                tem=edge[tem].next;
                continue;
            }
            if(1 == hash[i] && 0 == hash[edge[tem].v])
            {
                order[sum]=tem/2+1;
                sum++;
            }
            tem=edge[tem].next;
        }
    }
    printf("%d",sum);
    for(i=0;i<sum;i++)
    {
        printf(" %d",order[i]);
    }
    printf("\n");
}

int main()
{
    int val,i,f,num,u,v,len,sum;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d%d",&nn,&mm,&ff);
        chu();
        
        n=nn+1;
        s=1;
        t=n;
        
        for(f=0;f<mm;f++)
        {    
            scanf("%d%d%d",&u,&v,&len);
            add(u,v,len);
        }
        sum=0;
        for(f=0;f<ff;f++)
        {
            scanf("%d%d",&u,&val);
            add(u,t,val);
            sum+=val;
        }
        printf("Case %d: %d\n",i+1,sum-isap());    
        dfs(1);
        print();
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-08-13 15:07:49
    Judge Status : Accepted
    HDOJ Runid : 6539517
    Problem id : 3277
    Exe.time : 890MS
    Exe.memory : 1780K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#define maxn 800
#define maxe 200000
#define INF 0x7fffffff

int n,s,t,nn,k;
int size,net[maxn];
int gap[maxn];//gapÓÅ»¯ 
int dist[maxn];//¾àÀë±êºÅ 
int pre[maxn];//Ç°Çý 
int curedge[maxn];//µ±Ç°»¡ 

int qul[260][260],set[260];

struct node
{
    int v,next;
    int cap;
    int flow;
};
struct node edge[maxe];

void chu()
{
    int i,f;
    for(i=1;i<=nn;i++)
    {
        set[i]=i;
        for(f=1;f<=nn;f++)
        {
            qul[i][f]=1;
        }
    }
}

void inti()
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

void merge(int a,int b)
{
    set[a]=b;
}

int find(int x)
{
    return x==set[x]?x:set[x]=find(set[x]);
}

void fun()
{
    int i,f;
    for(i=1;i<=nn;i++)
    {
        for(f=1;f<=nn;f++)
        {
            qul[set[i]][f]&=qul[i][f];
        }
    }
}

void build(int mid)
{
    int i,f;
    n=3*nn+2;
    s=3*nn+1;
    t=3*nn+2;
    for(i=1;i<=nn;i++)
    {
        add(s,i,mid);
        add(i+2*nn,t,mid);
        add(i,i+nn,k);
        for(f=1;f<=nn;f++)
        {
            if(0 == qul[set[i]][f])
            {
                add(i,f+2*nn,1);
            }
            else
            {
                add(i+nn,f+2*nn,1);
            }            
        }
    }
}

int bs()
{
    int l,r,mid;
    l=0;
    r=nn+1;
    while(l != r-1)
    {
        mid=(l+r)>>1;
        inti();
        build(mid);
        if(mid*nn == isap())
        {
            l=mid;    
        }
        else
        {
            r=mid;
        }    
    }
    return l;
}

void debug()
{
    int i,f;
    for(i=1;i<=nn;i++)
    {
        for(f=1;f<=nn;f++)
        {
            printf("%d ",qul[i][f]);    
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int num,i,ff,f,m,u,v;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d%d%d",&nn,&m,&k,&ff);
        chu();
        for(f=0;f<m;f++)
        {
            scanf("%d%d",&u,&v);
            qul[u][v]=0;
        }
        for(f=0;f<ff;f++)
        {
            scanf("%d%d",&u,&v);
            merge(find(u),find(v));
        }
        fun();
        printf("%d\n",bs());
    }
    return 0;
}
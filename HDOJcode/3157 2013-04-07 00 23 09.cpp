******************************
    Author : townboy
    Submit time : 2013-04-07 00:23:09
    Judge Status : Accepted
    HDOJ Runid : 8019205
    Problem id : 3157
    Exe.time : 15MS
    Exe.memory : 268K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#define maxn 1000
#define maxe 2100000
#define INF 0x3f3f3f3f

int n,s,t;
int size,net[maxn];
int gap[maxn];//gapÓÅ»¯ 
int dist[maxn];//¾àÀë±êºÅ 
int pre[maxn];//Ç°Çý 
int curedge[maxn];//µ±Ç°»¡ 

int nn,m;

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

int turn(char tem[3])
{
    if('+' == tem[0])
        return nn+1;
    if('-' == tem[0])
        return nn+2;
    if(0 == tem[1])
        return tem[0]-'0';
    return (tem[0]-'0')*10+tem[1]-'0';
}

int lim[210],in[55],out[55];
int uu[210],vv[210];

int abs(int x)
{
    return x>0?x:-x;
}

int check(int tem)
{
    int i,sum=0;
    chu();
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    s=nn+3;
    t=nn+4;
    n=t;
    for(i=0;i<m;i++)
    {
        add(uu[i],vv[i],INF);
        out[uu[i]]+=lim[i];
        in[vv[i]]+=lim[i];
    }
    add(nn+2,nn+1,tem);
    for(i=1;i<=nn+2;i++)
    {
        if(in[i] < out[i])
            add(i,t,abs(in[i]-out[i]));
        else
            add(s,i,abs(in[i]-out[i]));
        sum+=abs(in[i]-out[i]);
    }
    sum/=2;
    if(sum == isap())
        return 1;
    return 0;
}

int er()
{
    int l=-1,r=50000,mid;
    while(l != r-1)
    {
        mid=(l+r)/2;
        if(1 == check(mid))
            r=mid;
        else 
            l=mid;
    }
    return r;
}

void debug()
{
    int i;
    for(i=0;i<m;i++)
        printf("%d %d %d\n",uu[i],vv[i],lim[i]);
    printf("\n");
}

int main()
{
    char pos[3],neg[3];
    int tem,start,end;
    int i,ans,u,v;
    while(scanf("%d%d",&nn,&m),nn+m)
    {
        chu();
        for(i=0;i<m;i++)
        {
            scanf("%s%s%d",pos,neg,&tem);
            u=turn(pos);
            v=turn(neg);
            uu[i]=u;
            vv[i]=v;
            lim[i]=tem;
        }
        ans=er();
        if(50000 == ans)
            printf("impossible\n");
        else
            printf("%d\n",ans);
    }
    return 0;    
}
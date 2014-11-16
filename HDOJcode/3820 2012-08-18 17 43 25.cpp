******************************
    Author : townboy
    Submit time : 2012-08-18 17:43:25
    Judge Status : Accepted
    HDOJ Runid : 6599280
    Problem id : 3820
    Exe.time : 31MS
    Exe.memory : 916K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#define maxn 6000
#define maxe 500000
#define INF 0x7fffffff

int n,m,s,t;
int size,net[maxn];
int gap[maxn];//gapÓÅ»¯ 
int dist[maxn];//¾àÀë±êºÅ 
int pre[maxn];//Ç°Çý 
int curedge[maxn];//µ±Ç°»¡ 

int nn,mm,id[55][55],gold[55][55],sil[55][55];
int gg,ss,dir[4][2]={0,1,0,-1,1,0,-1,0};

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

void build()
{
    int i,f,k,nx,ny;
    n=2*nn*mm+2;
    s=2*nn*mm+1;
    t=2*nn*mm+2;
    for(i=1;i<=nn;i++)
    {
        for(f=1;f<=mm;f++)
        {
            if(1 == (1&(i+f)))
            {
                add(s,id[i][f],gold[i][f]);
                add(id[i][f]+nn*mm,t,sil[i][f]);    
                add(id[i][f],id[i][f]+nn*mm,INF);
                for(k=0;k<4;k++)
                {
                    nx=i+dir[k][0];
                    ny=f+dir[k][1];
                    if(nx < 1 || nx > nn || ny < 1 || ny > mm)
                    {
                        continue;
                    }
                    add(id[i][f],id[nx][ny]+nn*mm,gg);    
                }
            }
            else
            {
                add(s,id[i][f],sil[i][f]);
                add(id[i][f]+nn*mm,t,gold[i][f]);
                add(id[i][f],id[i][f]+nn*mm,INF);
                for(k=0;k<4;k++)
                {
                    nx=i+dir[k][0];
                    ny=f+dir[k][1];
                    if(nx < 1 || nx > nn || ny < 1 || ny > mm)
                    {
                        continue;
                    }
                    add(id[i][f],id[nx][ny]+nn*mm,ss);    
                }
            }    
        }
    }
}

void debug()
{
    int i,f;
    for(i=1;i<=nn;i++)
    {
        for(f=1;f<=mm;f++)
        {
            printf("%d ",sil[i][f]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int num,f,i,k,sum;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d%d%d",&nn,&mm,&gg,&ss);
        chu();
        sum=0; 
        for(f=1;f<=nn;f++)
        {
            for(k=1;k<=mm;k++)
            {
                scanf("%d",&gold[f][k]);
                sum+=gold[f][k]; 
                id[f][k]=turn(f,k);
            }
        }
        for(f=1;f<=nn;f++)
        {
            for(k=1;k<=mm;k++)
            {
                scanf("%d",&sil[f][k]);
                sum+=sil[f][k]; 
            }
        }
        build();    
        printf("Case %d: %d\n",i+1,sum-isap());
    }
    return 0;
}
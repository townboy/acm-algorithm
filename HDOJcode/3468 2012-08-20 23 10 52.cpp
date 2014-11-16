******************************
    Author : townboy
    Submit time : 2012-08-20 23:10:52
    Judge Status : Accepted
    HDOJ Runid : 6618409
    Problem id : 3468
    Exe.time : 250MS
    Exe.memory : 820K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<queue>
#define maxn 11000
#define maxe 2100000
#define INF 10000000
using namespace std;

int n,m,s,t;
int size,net[maxn];
int gap[maxn];//gapÓÅ»¯ 
int dist[maxn];//¾àÀë±êºÅ 
int pre[maxn];//Ç°Çý 
int curedge[maxn];//µ±Ç°»¡ 

int nn,mm,order[60][2],maxx;
char map[110][110],dir[4][2]={0,1,0,-1,1,0,-1,0};
int distz[110][110],distf[110][110],minn,flag;

struct xx
{
    int v,next;
    int cap;
    int flow;
};
struct xx edge[maxe];

void chu()
{
    size=0;
    memset(net,-1,sizeof(net));
    maxx=-1;
    flag=0;
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

struct node 
{
    int x;
    int y;
    int t;
};
struct node tem,ru;

void bfs(int x)
{
    int i,f;
    queue<node>q;
    memset(distz,0,sizeof(distz));
    memset(distf,0,sizeof(distf));    
    for(i=1;i<=nn;i++)
    {
        for(f=1;f<=mm;f++)
        {
            distf[i][f]=distz[i][f]=INF;
        }
    }
    minn=-1;
    ru.x=order[x-1][0];
    ru.y=order[x-1][1];
    ru.t=0;
    distz[ru.x][ru.y]=0;
    q.push(ru);
    while(!q.empty())
    {
        tem=q.front();
        q.pop();
        if(tem.x == order[x][0] && tem.y == order[x][1])
        {
            minn=tem.t;
            break;
        }
        for(i=0;i<4;i++)
        {
            ru.x=tem.x+dir[i][0];
            ru.y=tem.y+dir[i][1];
            ru.t=tem.t+1;
            if('#' == map[ru.x][ru.y])
            {
                continue;    
            }
            if(tem.t + 1 < distz[ru.x][ru.y])
            {
                distz[ru.x][ru.y]=ru.t;
                q.push(ru);
            }
        }
    }
    if(-1 == minn)
    {
        flag=1;
    }
    while(!q.empty())
    {
        q.pop();
    }    
    
    ru.x=order[x][0];
    ru.y=order[x][1];
    ru.t=0;
    distf[ru.x][ru.y]=0;
    q.push(ru);
    while(!q.empty())
    {
        tem=q.front();
        q.pop();
        if(tem.x == order[x-1][0] && tem.y == order[x-1][1])
        {
            break;
        }
        for(i=0;i<4;i++)
        {
            ru.x=tem.x+dir[i][0];
            ru.y=tem.y+dir[i][1];
            ru.t=tem.t+1;
            if('#' == map[ru.x][ru.y])
            {
                continue;    
            }
            if(tem.t + 1 < distf[ru.x][ru.y])
            {
                distf[ru.x][ru.y]=ru.t;
                q.push(ru);
            }
        }
    }
}

void build(int x)
{
    int i,f;
    for(i=1;i<=nn;i++)
    {
        for(f=1;f<=mm;f++)
        {
            if('*' != map[i][f])
            {
                continue;
            }
            if(distz[i][f] + distf[i][f] == minn)
            {
                add(nn*mm+x,turn(i,f),1);
            }
        }    
    }
}

void debug()
{
    int i,f;
    for(i=0;i<maxx;i++)
    {
        printf("%d %d \n",order[i][0],order[i][1]);
    }
}

int main()
{
    int i,f;
    while(scanf("%d%d",&nn,&mm)!=EOF)
    {
        getchar();
        chu();
        for(i=1;i<=nn;i++)
        {
            for(f=1;f<=mm;f++)
            {
                scanf("%c",&map[i][f]);
                if(map[i][f]>='a' && map[i][f] <='z')
                {
                    order[map[i][f]-'a'+26][0]=i;
                    order[map[i][f]-'a'+26][1]=f;        
                    maxx=max(maxx,map[i][f]-'a'+26);
                }
                if(map[i][f]>='A' && map[i][f] <='Z')
                {
                    order[map[i][f]-'A'][0]=i;
                    order[map[i][f]-'A'][1]=f;        
                    maxx=max(maxx,map[i][f]-'A');    
                }
            }
            getchar();
        }
        
        n=nn*mm+maxx+2;
        s=n-1;
        t=n;
        for(i=1;i<=maxx;i++)
        {
            bfs(i);
            build(i);
            add(s,nn*mm+i,1);
        }
        for(i=1;i<=nn;i++)
        {
            for(f=1;f<=mm;f++)
            {
                if('*' == map[i][f])
                {
                    add(turn(i,f),t,1);
                }
            }
        }
        if(1 == flag)
        {
            printf("-1\n");
            continue;
        }
        printf("%d\n",isap());
    }
    return 0;
}
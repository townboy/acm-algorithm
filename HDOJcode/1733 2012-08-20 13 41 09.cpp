******************************
    Author : townboy
    Submit time : 2012-08-20 13:41:09
    Judge Status : Accepted
    HDOJ Runid : 6612569
    Problem id : 1733
    Exe.time : 468MS
    Exe.memory : 9460K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#define maxn 170000
#define maxe 1500000
#define INF 0x7fffffff

int n,s,t;
int size,net[maxn];
int gap[maxn];//gapÓÅ»¯ 
int dist[maxn];//¾àÀë±êºÅ 
int pre[maxn];//Ç°Çý 
int curedge[maxn];//µ±Ç°»¡ 

char map[20][20];
int nn,mm,dir[5][2]={0,1,0,-1,1,0,-1,0,0,0};
int hash[20][20],sum;

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

void debug()
{
    int i,f;
    for(i=1;i<=nn;i++)
    {
        for(f=1;f<=mm;f++)
        {
            printf("%c",map[i][f]);
        }
        printf("\n");
    }
    printf("\n");
}

int turn(int t,int x,int y)
{
    return nn*mm*(t-1)+(x-1)*mm+y;
}

void build(int time)
{
    int i,f,g,h,zeng=nn*mm*(time+1),nx,ny;
    n=nn*mm*(time+1)*2+2;
    s=n-1;
    t=n;
    for(i=1;i<=time+1;i++)
    {
        for(f=1;f<=nn;f++)
        {
            for(g=1;g<=mm;g++)
            {
                add(turn(i,f,g),turn(i,f,g)+zeng,1);
                if('@' == map[f][g])
                {
                    add(turn(i,f,g)+zeng,t,1);
                }
            }
        }
        
        if(time+1 == i)
        {
            continue;
        }
            
        for(f=1;f<=nn;f++)
        {
            for(g=1;g<=mm;g++)
            {
                if('#' == map[f][g])
                {
                    continue;
                }
                for(h=0;h<5;h++)
                {
                    nx=f+dir[h][0];
                    ny=g+dir[h][1];
                    if(nx < 1 || nx > nn || ny < 1 || ny >mm)
                    {
                        continue;
                    }
                    add(turn(i,f,g)+zeng,turn(i+1,nx,ny),1);                
                }
            }
        }    
    }
    
    for(f=1;f<=nn;f++)
    {
        for(g=1;g<=mm;g++)
        {
            if('X' == map[f][g])
            {
                add(s,turn(1,f,g),1);
            }
        }
    }
}

int bs(int sum)
{
    int ans,l=0,r=270,mid;
    while(l != r-1)
    {
        mid=(l+r)>>1;
        chu();
        build(mid);
        if(sum == isap())
        {
            r=mid;
        }
        else
        {
            l=mid;
        }
    }
    return r;
}

void dfs(int x,int y)
{
    int i,nx,ny;
    if(1 == hash[x][y])
    {
        return ;
    }
    if('#' == map[x][y])
    {
        return ;
    }
    hash[x][y]=1;
    if('X' == map[x][y])
    {
        sum++;
    }
    for(i=0;i<4;i++)
    {
        nx=x+dir[i][0];
        ny=y+dir[i][1];
        if(nx < 1 || nx > nn || ny < 1 || ny > mm)
        {
            continue;
        }
        if(1 == hash[nx][ny])
        {
            continue;
        }
        dfs(nx,ny);
    }        
}

int check(int ans)
{
    int i,f;
    sum=0;
    memset(hash,0,sizeof(hash));
    for(i=1;i<=nn;i++)
    {
        for(f=1;f<=mm;f++)
        {
            if('@' == map[i][f])
            {    
                dfs(i,f);
            }
        }
    }
    
    if(ans != sum)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int i,f,sum,ans;
    while(scanf("%d%d",&nn,&mm)!=EOF)
    {
        sum=0;
        getchar();
        for(i=1;i<=nn;i++)
        {
            for(f=1;f<=mm;f++)
            {
                scanf("%c",&map[i][f]);
                if('X' == map[i][f])
                {
                    sum++;
                }
            }
            getchar();
        }
        
        if(1 == check(sum))
        {
            printf("-1\n");
            continue;
        }
        
//        debug();
        ans=bs(sum);
        printf("%d\n",ans);
    }
    return 0;
}
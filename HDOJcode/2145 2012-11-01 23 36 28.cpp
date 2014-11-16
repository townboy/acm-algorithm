******************************
    Author : townboy
    Submit time : 2012-11-01 23:36:28
    Judge Status : Accepted
    HDOJ Runid : 7062891
    Problem id : 2145
    Exe.time : 109MS
    Exe.memory : 364K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<vector>
#include<memory.h>
#define INF 0x7fffffff

using namespace std;

int dis[310],hash[310];
int n,m,k,s,speed[310],start[310];

struct node 
{
    int v;
    int len;
};
struct node ru;
vector<node>q[310];

struct xx
{
    int dis;
    int speed;    
    int id;
};
struct xx que[310];

int cmp(const void *a,const void *b)
{
    if((double)(*(struct xx*)a).dis/(*(struct xx*)a).speed == (double)(*(struct xx*)b).dis/(*(struct xx*)b).speed)
    {
        if((*(struct xx*)a).dis == (*(struct xx*)b).dis)
        {
            return (*(struct xx*)a).id > (*(struct xx*)b).id ? -1 : 1;        
        }
        return (*(struct xx*)a).dis > (*(struct xx*)b).dis ? -1 : 1;
    }
    return (double)(*(struct xx*)a).dis/(*(struct xx*)a).speed > (double)(*(struct xx*)b).dis/(*(struct xx*)b).speed ? 1 : -1;     
}

void add(int u,int v,int len)
{
    ru.v=v;
    ru.len=len;
    q[u].push_back(ru);        
}

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        q[i].clear();    
        dis[i]=INF;
    }
    memset(hash,0,sizeof(hash));
}

void spfa()
{
    int i,tem,size,v,len;
    queue<int>que;

    dis[s]=0;
    que.push(s);
    
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        hash[tem]=0;
        
        size=q[tem].size();
        for(i=0;i<size;i++)
        {    
            v=q[tem][i].v;
            len=q[tem][i].len;
            if(dis[v] > dis[tem]+len)
            {
                dis[v]=dis[tem]+len;
                if(0 == hash[v])
                {
                    hash[v]=1;
                    que.push(v);
                }
            }
        }
    }
}

void debug()
{
    int i;
    for(i=1;i<=n;i++)
    {
        printf("%d ",dis[i]);
    }
    printf("\n");
}

int main()
{
    int u,v,len;
    int i,f;
    while(scanf("%d%d%d",&n,&k,&m)!=EOF)
    {
        chu();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&len);
            add(v,u,len);
        }
        scanf("%d",&s);
        for(i=1;i<=k;i++)
        {
            scanf("%d",&start[i]);    
        }
        for(i=1;i<=k;i++)
        {
            scanf("%d",&speed[i]);
        }
        spfa();
        for(i=1;i<=k;i++)
        {
            que[i-1].id=i;
            que[i-1].speed=speed[i];
            que[i-1].dis=dis[start[i]];    
        }
                
        qsort(que,k,sizeof(que[0]),cmp);
        if(INF == que[0].dis)
        {
            printf("No one\n");    
            continue;
        }
        printf("%d\n",que[0].id);
    }
    return 0;
}
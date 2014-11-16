******************************
    Author : townboy
    Submit time : 2012-11-13 00:11:47
    Judge Status : Accepted
    HDOJ Runid : 7145348
    Problem id : 1688
    Exe.time : 31MS
    Exe.memory : 508K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<vector>
#include<memory.h>
#define INF 0x7fffffff

using namespace std;

struct node 
{
    int v;
    int len; 
};
struct node edge_ru;

int dp[1100][2],dis[1100];
int n,m,s,t,hash[1100][2];
vector<node>q[1100];

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        q[i].clear();        
        dis[i]=INF;
    }
    memset(dp,0,sizeof(dp));
    memset(hash,0,sizeof(hash));
}

void add(int u,int v,int len)
{
    edge_ru.len=len;
    edge_ru.v=v;
    q[u].push_back(edge_ru);
}

struct xx
{
    int v;
    int flag;
    int val;
    friend bool operator < (xx a,xx b)
    {
        return a.val > b.val;
    }
};
struct xx ru;

void bfs()
{
    int i,size,flag,len,tem,v;
    priority_queue<xx>que;

    dp[s][0]=1;
    dis[s]=0;
    memset(hash,0,sizeof(hash));
    ru.v=s;
    ru.flag=0;
    ru.val=0;
    que.push(ru);
    
    while(!que.empty())
    {
        tem=que.top().v;
        flag=que.top().flag;
        que.pop();
        if(1 == hash[tem][flag])
        {
            continue;
        }
        hash[tem][flag]=1;
        if(0 == dp[tem][flag])
        {
            continue;
        }
        
        size=q[tem].size();
        for(i=0;i<size;i++)
        {
            v=q[tem][i].v;
            len=q[tem][i].len;
            if(dis[v]-1 > dis[tem]+flag+len)
            {
                dis[v]=dis[tem]+flag+len;
                dp[v][0]=dp[tem][flag];
                dp[v][1]=0;
                ru.flag=0;
                ru.v=v;
                ru.val=dis[v];
                que.push(ru);
            }
            else if(dis[v]-1 == dis[tem]+flag+len)
            {
                dis[v]=dis[tem]+flag+len;
                dp[v][1]=dp[v][0];
                dp[v][0]=dp[tem][flag];
                ru.flag=0;
                ru.v=v;
                ru.val=dis[v];
                que.push(ru);                

                ru.flag=1;
                ru.v=v;
                ru.val=dis[v]+1;
                que.push(ru);
            }        
            else if(dis[v] == dis[tem]+flag+len)
            {
                dp[v][0]+=dp[tem][flag];
            }
            else if(dis[v]+1 == dis[tem]+flag+len)
            {
                dp[v][1]+=dp[tem][flag];
                if(dp[v][1] == dp[tem][flag])
                {
                    ru.v=v;
                    ru.flag=1;
                    ru.val=dis[v]+1;
                    que.push(ru);
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
        printf("%d %d\n",dp[i][0],dp[i][1]);
    }
}

int main()
{
    int u,v,len;
    int cas,i,f;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d",&n,&m);
        chu();
        for(f=0;f<m;f++)
        {
            scanf("%d%d%d",&u,&v,&len);
            add(u,v,len);    
        }
        scanf("%d%d",&s,&t);
        bfs();
        printf("%d\n",dp[t][0]+dp[t][1]);
    }
    return 0;
}
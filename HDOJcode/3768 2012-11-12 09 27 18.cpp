******************************
    Author : townboy
    Submit time : 2012-11-12 09:27:18
    Judge Status : Accepted
    HDOJ Runid : 7137675
    Problem id : 3768
    Exe.time : 218MS
    Exe.memory : 4980K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<vector>
#include<memory.h>
#define INF 1000000

using namespace std;

struct node 
{
    int v;
    int len;
};
struct node ru;

vector<node>q[110000];
int n,m,k,ji,map[15][15];
int id[15],hash[110000];
int dis[110000],dp[15][1100];
int M;

void add(int u,int v,int len)
{
    ru.len=len;
    ru.v=v;
    q[u].push_back(ru);
    ru.v=u;
    q[v].push_back(ru);    
}

void name(int x)
{
    if(1 == hash[x] || 0 == x)
    {
        return ;
    }
    hash[x]=1;
    id[++ji]=x;        
}

void chu()
{
    int i,f;
    for(i=0;i<n;i++)
    {
        q[i].clear();
    }
    ji=0;
    memset(hash,0,sizeof(hash));
    for(i=0;i<15;i++)
    {
        for(f=0;f<15;f++)
        {
            map[i][f]=INF;
        }
    }
}

void spfa(int start)
{
    int tem,i,size,len,v;
    queue<int>que;
    for(i=0;i<n;i++)
    {
        dis[i]=INF;
    }
    dis[start]=0;
    memset(hash,0,sizeof(hash));
        
    que.push(start);
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

void spfa_tem()
{
    int len;
    int newstate,state,f,i,tem,hash[15][1100];
    queue<int>que;
    
    for(i=0;i<=ji;i++)
    {    
        for(f=0;f<=M;f++)
        {
            dp[i][f]=INF;
        }
    }
    dp[0][0]=0;
    memset(hash,0,sizeof(hash));
    que.push(0);
    que.push(0);
    
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        state=que.front();
        que.pop();
        hash[tem][state]=0;
    
        for(i=0;i<=ji;i++)
        {
            len=map[tem][i];
            newstate=state|(1<<(i-1));
            if(dp[i][newstate] > dp[tem][state]+len)
            {
                dp[i][newstate] = dp[tem][state]+len;    
                if(0 == hash[i][newstate])
                {
                    hash[i][newstate]=1;
                    que.push(i);
                    que.push(newstate);    
                }
            }
        }
    }
}

int main()
{
    int u,v,len,tem,tab;
    int i,cas,f,g;
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
        scanf("%d",&k);
        for(f=0;f<k;f++)
        {
            scanf("%d",&tab);
            name(tab);
        }            
        
        M=(1<<ji)-1;
        
        id[0]=0;
        spfa(0);
        for(f=0;f<=ji;f++)
        {
            map[0][f]=dis[id[f]];
        }
        
        for(f=1;f<=ji;f++)
        {
            spfa(id[f]);
            for(g=0;g<=ji;g++)
            {
                map[f][g]=dis[id[g]];
            }
        }            
        
        spfa_tem();
        printf("%d\n",dp[0][M]);
    }
    return 0;
}
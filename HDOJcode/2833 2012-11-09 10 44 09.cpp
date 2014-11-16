******************************
    Author : townboy
    Submit time : 2012-11-09 10:44:09
    Judge Status : Accepted
    HDOJ Runid : 7118220
    Problem id : 2833
    Exe.time : 0MS
    Exe.memory : 332K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<iostream> 
#include<vector>
#include<memory.h>
#define INF 0x7fffffff

using namespace std;

struct node 
{
    int v;
    int len; 
}; 
struct node ru;

int sun[310],tang[310],dp[310][3];
int s1,s2,t1,t2,hash[310];
int n,m,dis[310],hashtem[310][3];
vector<node>q[310];

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        q[i].clear(); 
    } 
} 

void add(int u,int v,int len)
{
    ru.len=len;
    ru.v=v;
    q[u].push_back(ru);
    ru.v=u;
    q[v].push_back(ru);    
}

void spfa(int s)
{
    int i,tem,size,v,len;
    queue<int>que;
    
    memset(hash,0,sizeof(hash));
    for(i=1;i<=n;i++)
    {
        dis[i]=INF;
    }
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

int spfa_tem()
{
    int i,size,tem,v,len,state;
    queue<int>que;
    
    memset(hashtem,0,sizeof(hashtem)); 
    memset(dp,-1,sizeof(dp));
    
    dp[t1][1]=0;
    dp[t2][2]=0;
    que.push(t1);
    que.push(1);
    que.push(t2);
    que.push(2);
                
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        state=que.front();
        que.pop();    
    
        hashtem[tem][state]=0;

        if(0 == state)
        {
            size=q[tem].size();
            for(i=0;i<size;i++)
            {
                v=q[tem][i].v;
                len=q[tem][i].len; 
                if(sun[v]==sun[tem]-len && tang[v]==tang[tem]-len) 
                {
                    if(dp[v][0] < dp[tem][0]+1)
                    {
                        dp[v][0]=dp[tem][0]+1;
                        if(0 == hashtem[v][0])
                        {
                            hashtem[v][0]=1;
                            que.push(v);
                            que.push(0);
                        }
                    }                                    
                }
                else if(sun[v]==sun[tem]-len)
                {
                    if(dp[v][1] < dp[tem][0])
                    {
                        dp[v][1]=dp[tem][0];
                        if(0 == hashtem[v][1])
                        {
                            hashtem[v][1]=1;
                            que.push(v);
                            que.push(1);
                        }
                    }                                
                }
                else if(tang[v]==tang[tem]-len)
                {
                    if(dp[v][2] < dp[tem][0])
                    {
                        dp[v][2]=dp[tem][0];
                        if(0 == hashtem[v][2])
                        {
                            hashtem[v][2]=1;
                            que.push(v);
                            que.push(2);
                        }
                    }                                                            
                }
            }
        }    
        else if(1 == state)
        {
            size=q[tem].size();
            for(i=0;i<size;i++)
            {
                v=q[tem][i].v;
                len=q[tem][i].len; 
                if(sun[v]==sun[tem]-len) 
                {
                    if(dp[v][1] < dp[tem][1])
                    {
                        dp[v][1]=dp[tem][1];
                        if(0 == hashtem[v][1])
                        {
                            hashtem[v][1]=1;
                            que.push(v);
                            que.push(1);
                        }
                    }                                    
                }
            }
             if(0 != dp[tem][2] || 0 != dp[tem][1])
            {
                continue;
            }
            if(dp[tem][0] < 1)
            {
                dp[tem][0]=1;
                if(0 == hashtem[tem][0])
                {
                    hashtem[tem][0]=1;
                    que.push(tem);
                    que.push(0);
                }
            }
       }
        else
        {
            size=q[tem].size();
            for(i=0;i<size;i++)
            {
                v=q[tem][i].v;
                len=q[tem][i].len; 
                if(tang[v]==tang[tem]-len) 
                {
                    if(dp[v][2] < dp[tem][2])
                    {
                        dp[v][2]=dp[tem][2];
                        if(0 == hashtem[v][2])
                        {
                            hashtem[v][2]=1;
                            que.push(v);
                            que.push(2);
                        }
                    }                                    
                }
            }
            if(0 != dp[tem][2] || 0 != dp[tem][1])
            {
                continue;
            }
            if(dp[tem][0] < 1)
            {
                dp[tem][0]=1;
                if(0 == hashtem[tem][0])
                {
                    hashtem[tem][0]=1;
                    que.push(tem);
                    que.push(0);
                }
            }
        } 
    }
    return max(dp[s1][0],dp[s1][1]);
} 

int main()
{
    int u,v,len; 
    int i;
    while(scanf("%d%d",&n,&m),n+m)
    {
        chu(); 
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&len); 
            add(u,v,len); 
        }
        scanf("%d%d%d%d",&s1,&t1,&s2,&t2);

        spfa(s1);
        for(i=1;i<=n;i++)
        {
            sun[i]=dis[i];
        }
        spfa(s2);
        for(i=1;i<=n;i++)
        {
            tang[i]=dis[i];
        }
                
        printf("%d\n",spfa_tem());
    } 
    return 0;
}
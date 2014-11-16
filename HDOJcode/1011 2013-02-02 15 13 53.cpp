******************************
    Author : townboy
    Submit time : 2013-02-02 15:13:53
    Judge Status : Accepted
    HDOJ Runid : 7583570
    Problem id : 1011
    Exe.time : 93MS
    Exe.memory : 320K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<vector>
#include<memory.h>
#include<iostream>

using namespace std;

int n,m;
vector<int>map[110];
int poss[110],bugs[110];
int vis[110],dp[110][110];

void chu()
{
    int i,f;
    for(i=1;i<=100;i++)
        map[i].clear();
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));
}

void dfs(int rt)
{
    int yu;
    int f,g,son;
    int i,size=map[rt].size();
    
    for(i=0;i<size;i++)
    {
        son=map[rt][i];
        if(1 == vis[son])
            continue;
        vis[son]=1;
        dfs(son);
        for(f=100;f>=0;f--)
            for(g=f;g>=0;g--)
            {
                yu=f-g;
                dp[rt][f]=max(dp[rt][f],dp[rt][g]+dp[son][yu]);
            }
    } 
    for(i=100;i>=bugs[rt];i--)
        dp[rt][i]=dp[rt][i-bugs[rt]]+poss[rt];
    for(i=bugs[rt]-1;i>=0;i--)
        dp[rt][i]=0;
    dp[rt][0]=0; 
} 

int main()
{
    int s,t;
    int i,maxx;
        
    while(scanf("%d%d",&n,&m),-2 != n+m)
    {
        chu();
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&bugs[i],&poss[i]);
            bugs[i]=(bugs[i]+19)/20;
        }
            
        for(i=0;i<n-1;i++)
        {    
            scanf("%d%d",&s,&t);
            map[s].push_back(t);
            map[t].push_back(s);
        }
    
        if(0 == m)
        {
            printf("0\n");
            continue;
        }
    
        vis[1]=1;
        dfs(1);
        
        maxx=0;
        for(i=0;i<=m;i++)
            maxx=max(maxx,dp[1][i]);
        printf("%d\n",maxx);
    }
    return 0;
}
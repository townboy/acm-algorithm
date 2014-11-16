******************************
    Author : townboy
    Submit time : 2012-09-15 14:59:20
    Judge Status : Accepted
    HDOJ Runid : 6770887
    Problem id : 1530
    Exe.time : 1015MS
    Exe.memory : 256K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
using namespace std;

int map[55][55],vis[55],dp[55];
int tmax,n;

void dfs(int id,int cnt)
{
    int i,tvis[55],able=0,f;
    for(i=id+1;i<=n;i++)
    {
        if(1 == vis[i])
        {
            able++;    
        }    
    }
    if(0 == able)
    {
        if(cnt > tmax)
        {
            tmax=cnt;
        }
        return ;        
    }
    if(able + cnt <= tmax)
    {
        return ;
    }

    for(i=1;i<=n;i++)
    {
        tvis[i]=vis[i];    
    }

    for(i=id+1;i<=n;i++)
    {
        if(0 == tvis[i])
        {
            continue;
        }
        if(cnt + dp[i] <= tmax)
        {    
            continue;
        }
        for(f=i+1;f<=n;f++)
        {
            vis[f]=tvis[f]&map[i][f];
        }
        dfs(i,cnt+1);        
    }
}


int max_clique()
{
    int i,f;
    tmax=1;
    dp[n]=1;
    for(i=n-1;i>=1;i--)
    {
        for(f=1;f<=n;f++)
        {
            vis[f]=map[i][f];
        }
        dfs(i,1);
        dp[i]=tmax;
        if(n == tmax)
        {
            return tmax;
        }
    }
    return tmax;
}

int main()
{
    int i,f;
    while(scanf("%d",&n),n)
    {
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=n;f++)
            {
                scanf("%d",&map[i][f]);
            }
        }
        printf("%d\n",max_clique());
    }
    return 0;
}
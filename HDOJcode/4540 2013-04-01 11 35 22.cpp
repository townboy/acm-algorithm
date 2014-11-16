******************************
    Author : townboy
    Submit time : 2013-04-01 11:35:22
    Judge Status : Accepted
    HDOJ Runid : 7955102
    Problem id : 4540
    Exe.time : 0MS
    Exe.memory : 232K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>

using namespace std;

int pos[25][15];
int dp[25][15];

int abs(int x)
{
    return x>0?x:-x;
}

int main()
{
    int n,m,g;
    int i,f,ans;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
            for(f=0;f<m;f++)
                scanf("%d",&pos[i][f]);
        memset(dp,0x3f,sizeof(dp));
        memset(dp[0],0,sizeof(dp[0]));
        for(i=0;i<n-1;i++)
            for(f=0;f<m;f++)
                for(g=0;g<m;g++)
                    dp[i+1][g]=min(dp[i+1][g],dp[i][f]+abs(pos[i][f]-pos[i+1][g]));
        ans=0x7fffffff;
        for(i=0;i<m;i++)
            ans=min(ans,dp[n-1][i]);
        printf("%d\n",ans);
    }
    return 0;
}
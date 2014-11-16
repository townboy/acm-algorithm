******************************
    Author : townboy
    Submit time : 2012-11-22 16:10:47
    Judge Status : Accepted
    HDOJ Runid : 7224505
    Problem id : 1158
    Exe.time : 171MS
    Exe.memory : 296K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#define INF 0x7fffffff

using namespace std;

int n,hire,sal,fire;
int lim[20],dp[20][120];

void chu()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=0;f<=110;f++)
        {
            dp[i][f]=INF;
        }
    }    
}

int cal(int old,int x)
{
    return old < x ? x*sal+hire*(x-old) : x*sal+fire*(old-x);    
}

void solve()
{
    int i,f,g;
    for(i=lim[1];i<=110;i++)
    {
        dp[1][i]=cal(0,i);
    }    
    for(i=2;i<=n;i++)
    {
        for(f=lim[i];f<=110;f++)
        {
            for(g=lim[i-1];g<=110;g++)
            {
                dp[i][f]=min(dp[i][f],dp[i-1][g]+cal(g,f));
            }
        }
    }
}

void debug()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=11;f++)
        {
            printf("%d ",dp[i][f]);
        }
        printf("\n");
    }
}

int main()
{
    int i,ans;
    while(scanf("%d",&n),0!=n)
    {
        chu();
        scanf("%d%d%d",&hire,&sal,&fire);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&lim[i]);
        }
        solve();        
        ans=lim[n];
        for(i=lim[n];i<=110;i++)
        {
            if(dp[n][i] < dp[n][ans])
            {
                ans=i;
            }
        }
        printf("%d\n",dp[n][ans]);
    }
    return 0;
}
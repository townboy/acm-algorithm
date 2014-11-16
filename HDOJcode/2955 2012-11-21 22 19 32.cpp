******************************
    Author : townboy
    Submit time : 2012-11-21 22:19:32
    Judge Status : Accepted
    HDOJ Runid : 7220532
    Problem id : 2955
    Exe.time : 421MS
    Exe.memory : 384K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>

using namespace std;

double limit,dp[11000];
int n;

void chu()
{
    int i;
    memset(dp,0,sizeof(dp));
    for(i=1;i<=10050;i++)
    {
        dp[i]=1;
    }
    dp[0]=0;
}

void update(int mon,double p)
{
    int i;
    for(i=10000;i>=mon;i--)
    {
        dp[i]=min(dp[i],1-(1-dp[i-mon])*(1-p));
    }
}

int main()
{
    int ans;
    double p;
    int cas,i,f,mon;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%lf%d",&limit,&n);
        chu();
        for(f=1;f<=n;f++)
        {
            scanf("%d%lf",&mon,&p);    
            update(mon,p);
        }
        for(f=0;f<=10000;f++)
        {
            if(dp[f] < limit)
            {
                ans=f;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
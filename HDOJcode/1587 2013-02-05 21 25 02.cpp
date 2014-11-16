******************************
    Author : townboy
    Submit time : 2013-02-05 21:25:02
    Judge Status : Accepted
    HDOJ Runid : 7597201
    Problem id : 1587
    Exe.time : 15MS
    Exe.memory : 640K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>

using namespace std;

int dp[100010];
int n,m;

void chu()
{
    memset(dp,0,sizeof(dp));
}

void fun(int tem)
{
    int i;
    for(i=tem;i<=100000;i++)
        dp[i]=max(dp[i],dp[i-tem]+1);
}

int main()
{
    int i,tem;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        chu();
        for(i=0;i<n;i++)
        {
            scanf("%d",&tem);
            fun(tem);
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}
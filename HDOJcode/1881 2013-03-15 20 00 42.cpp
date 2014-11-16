******************************
    Author : townboy
    Submit time : 2013-03-15 20:00:42
    Judge Status : Accepted
    HDOJ Runid : 7772707
    Problem id : 1881
    Exe.time : 46MS
    Exe.memory : 1440K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

typedef struct
{
    int h,l,t;
}Node;
Node ary[31];
int dp[31][10000];

bool cmp(Node a,Node b)
{
    return a.t < b.t;
}
int max(int a,int b)
{
    return a > b ? a : b;
}
int main()
{
    int n;

    while(scanf("%d",&n) && n >= 0)
    {
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d%d",&ary[i].h,&ary[i].l,&ary[i].t);
        }
        sort(ary+1,ary+n+1,cmp);
        int last = ary[n].t;
        memset(dp,0,sizeof(dp));
        for(int i = 1;i <= n;i++)
        {
            for(int j = ary[i].t;j >=ary[i].l;j--)
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-ary[i].l]+ary[i].h);
            for(int j = ary[i].l-1;j >= 0;j--)
                dp[i][j] = dp[i-1][j];
        }
        int ans=0;
        for(int i=0;i<=last;i++)
            ans=max(ans,dp[n][i]);
        printf("%d\n",ans);
    }
    return 0;
}

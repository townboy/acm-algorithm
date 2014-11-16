******************************
    Author : townboy
    Submit time : 2013-03-15 13:04:52
    Judge Status : Accepted
    HDOJ Runid : 7769451
    Problem id : 1881
    Exe.time : 15MS
    Exe.memory : 236K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct node 
{
    int h,l,t;
};
struct node que[35];
int n,dp[1200];

int cmp(const void *a,const void *b)
{
    return (*(struct node *)a).t-(*(struct node *)b).t;
}

void init()
{
    memset(dp,0,sizeof(dp));
}

void fun(int h,int l,int t)
{
    int i;
    for(i=t;i>=l;i--)
        dp[i]=max(dp[i],dp[i-l]+h);
}

int main()
{
    int i,ans;
    while(scanf("%d",&n),n>=0)
    {
        for(i=0;i<n;i++)
            scanf("%d%d%d",&que[i].h,&que[i].l,&que[i].t);
        qsort(que,n,sizeof(que[0]),cmp);
        init();
        for(i=0;i<n;i++)
            fun(que[i].h,que[i].l,que[i].t);
        ans=0;
        for(i=0;i<=1000;i++)
            ans=max(ans,dp[i]);
        printf("%d\n",ans);
    }
    return 0;
}
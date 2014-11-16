******************************
    Author : townboy
    Submit time : 2012-12-04 18:46:45
    Judge Status : Accepted
    HDOJ Runid : 7328637
    Problem id : 1024
    Exe.time : 953MS
    Exe.memory : 3112K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream> 
#define INF ((__int64)1<<50)

using namespace std;

int m,n; 
__int64 dp[1100000],best[2][1100000];
int val[1100000];

void chu()
{
    best[0][0]=-INF;
    best[1][0]=-INF;
    dp[0]=-INF;
}

__int64 fun()
{
    int now,last,i,f;
    dp[1]=val[1];
    best[1][1]=val[1];

    now=1;
    for(f=2;f<=n;f++)
    {
        dp[f]=max((__int64)val[f],dp[f-1]+val[f]);
        best[now][f]=max(best[now][f-1],dp[f]);
    }
    for(i=2;i<=m;i++)
    {
        now=1&i;
        last=1^now;
        for(f=1;f<=n;f++)
        {
            dp[f]=max(dp[f-1]+val[f],best[last][f-1]+val[f]);
            best[now][f]=max(best[now][f-1],dp[f]);                
        }
    }    
    return best[m&1][n];
}

int main()
{
    int i;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        chu();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&val[i]);
        }
        printf("%I64d\n",fun());
    }
    return 0;
}
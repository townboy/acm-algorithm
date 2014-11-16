******************************
    Author : townboy
    Submit time : 2012-07-01 20:45:26
    Judge Status : Accepted
    HDOJ Runid : 6114607
    Problem id : 2546
    Exe.time : 15MS
    Exe.memory : 204K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int dp[1400],zan[1100],yu;

int cmp(const void*a,const void*b)
{
    return  *(int *)a-*(int *)b;
}

void mul(int x)
{
    int i;
    for(i=5-x+100;i<=yu-x+100;i++)
    {
        dp[i]|=dp[i+x];
    }
}

void chu()
{
    memset(dp,0,sizeof(dp));
    dp[yu+100]=1;    
}

int main()
{
    int n,i;
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&zan[i]);
        }
        scanf("%d",&yu);
        qsort(zan,n,sizeof(zan[0]),cmp);
        chu();
        for(i=0;i<n;i++)
        {
            mul(zan[i]);
        }    
        for(i=0;i<=yu+100;i++)
        {
            if(1 == dp[i])
            {
                printf("%d\n",i-100);
                break;
            }
        }
    }
    return 0;
}
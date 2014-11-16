******************************
    Author : townboy
    Submit time : 2012-10-29 22:08:45
    Judge Status : Accepted
    HDOJ Runid : 7035671
    Problem id : 4450
    Exe.time : 0MS
    Exe.memory : 216K
    https://github.com/townboy
******************************


#include<stdio.h>

int main()
{
    int i,sum,n,k;
    while(scanf("%d",&n),n)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&k);
            sum+=k*k;
        }
        printf("%d\n",sum);
    }
    return 0;
}
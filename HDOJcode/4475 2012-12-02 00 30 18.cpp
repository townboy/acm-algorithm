******************************
    Author : townboy
    Submit time : 2012-12-02 00:30:18
    Judge Status : Accepted
    HDOJ Runid : 7309044
    Problem id : 4475
    Exe.time : 31MS
    Exe.memory : 4204K
    https://github.com/townboy
******************************


#include<stdio.h>

int f[1100000];

void chu()
{
    int i;
    f[1]=2;
    for(i=2;i<=1000003;i++)
    {
        f[i]=(int)((__int64)f[i-1]*i*2%1000003);
    }
}

int main()
{
    int i,cas;
    __int64 n;
    chu();
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%I64d",&n);
        if(n > 1000003)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n",f[n]);
    }
    return 0;
}
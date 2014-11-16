******************************
    Author : townboy
    Submit time : 2013-03-30 23:46:44
    Judge Status : Accepted
    HDOJ Runid : 7941908
    Problem id : 4535
    Exe.time : 0MS
    Exe.memory : 232K
    https://github.com/townboy
******************************


#include<stdio.h>

#define mod 1000000007

__int64 cuo[110];

int main()
{
    int cas,tem,i;
    scanf("%d",&cas);
    cuo[0]=1;
    cuo[1]=0;
    for(i=2;i<=105;i++)
        cuo[i]=(i-1)*(cuo[i-1]+cuo[i-2])%mod;
    for(i=0;i<cas;i++)
    {
        scanf("%d",&tem);
        printf("%I64d\n",cuo[tem]);
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2011-11-10 21:32:17
    Judge Status : Accepted
    HDOJ Runid : 4946274
    Problem id : 2045
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    __int64 a[60];
    int num,i;
    a[1]=3;
    a[2]=6;
    a[3]=6;
    while(scanf("%d",&num)!=EOF)
    {
        for(i=4;i<=num;i++)
        {
            a[i]=2*a[i-2]+a[i-1];
        }
        printf("%I64d\n",a[num]);
    }
return 0;
}
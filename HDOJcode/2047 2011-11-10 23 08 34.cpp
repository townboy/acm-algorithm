******************************
    Author : townboy
    Submit time : 2011-11-10 23:08:34
    Judge Status : Accepted
    HDOJ Runid : 4947210
    Problem id : 2047
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int num,i;
    __int64 a[45],b[45];
    a[1]=2;
    b[1]=1;
    while(scanf("%d",&num)!=EOF)
    {
        for(i=2;i<=num;i++)
        {
            a[i]=(a[i-1]+b[i-1])*2;
            b[i]=a[i-1];
        }
        printf("%I64d\n",a[num]+b[num]);
    }

    
return 0;
}
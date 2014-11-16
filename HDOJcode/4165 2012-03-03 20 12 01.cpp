******************************
    Author : townboy
    Submit time : 2012-03-03 20:12:01
    Judge Status : Accepted
    HDOJ Runid : 5460183
    Problem id : 4165
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int i,x;
    __int64 f[40];
    f[1]=1;
    for(i=2;i<=31;i++)
    {
        f[i]=f[i-1]*(4*i-2)/(i+1);
    }
    while(scanf("%d",&x),x)
    {
        printf("%I64d\n",f[x]);
    }
    return 0;
}
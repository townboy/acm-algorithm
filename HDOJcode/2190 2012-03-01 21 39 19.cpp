******************************
    Author : townboy
    Submit time : 2012-03-01 21:39:19
    Judge Status : Accepted
    HDOJ Runid : 5445791
    Problem id : 2190
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    __int64 f[40];
    int i,x,num;
    f[1]=1;
    f[2]=3;
    for(i=3;i<=35;i++)
    {
        f[i]=f[i-1]+2*f[i-2];
    }
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&x);
        printf("%I64d\n",f[x]);
    }
    return 0;
}
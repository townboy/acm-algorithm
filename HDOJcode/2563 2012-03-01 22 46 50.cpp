******************************
    Author : townboy
    Submit time : 2012-03-01 22:46:50
    Judge Status : Accepted
    HDOJ Runid : 5446635
    Problem id : 2563
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    __int64 f[25];
    int i,num,x;
    f[1]=3;
    f[2]=7;
    for(i=3;i<=22;i++)
    {
        f[i]=2*f[i-1]+f[i-2];
    }
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&x);
        printf("%I64d\n",f[x]);
    }
    return 0;
}

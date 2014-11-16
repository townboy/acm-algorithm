******************************
    Author : townboy
    Submit time : 2011-11-10 21:53:58
    Judge Status : Accepted
    HDOJ Runid : 4946546
    Problem id : 2041
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    __int64 a[50];
    int num,i,x,f;
    a[1]=0;
    a[2]=1;
    a[3]=2;
    scanf("%d",&num);
    for(f=0;f<num;f++)
    {
        scanf("%d",&x);
        for(i=4;i<=x;i++)
        {
            a[i]=a[i-2]+a[i-1];
        }
        printf("%I64d\n",a[x]);
    }
return 0;
}
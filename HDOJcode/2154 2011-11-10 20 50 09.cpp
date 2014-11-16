******************************
    Author : townboy
    Submit time : 2011-11-10 20:50:09
    Judge Status : Accepted
    HDOJ Runid : 4945701
    Problem id : 2154
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int a[1100],num,i;
    a[1]=0;
    a[2]=2;
    while(scanf("%d",&num),num)
    {
        for(i=3;i<=num;i++)
        {
            a[i]=2*a[i-2]+a[i-1];
            a[i]=a[i]%10000;
        }
        printf("%d\n",a[num]);
    }
return 0;
}
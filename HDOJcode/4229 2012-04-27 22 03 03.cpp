******************************
    Author : townboy
    Submit time : 2012-04-27 22:03:03
    Judge Status : Accepted
    HDOJ Runid : 5860344
    Problem id : 4229
    Exe.time : 0MS
    Exe.memory : 220K
    https://github.com/townboy
******************************


#include<stdio.h>

__int64 a[5];

int test()
{
    int i;
    for(i=0;i<3;i++)
    {
        if(a[i] != a[i+1])
        {
            return 0;
        }
    }
    return 1;
}

void turn()
{
    int i;
    a[4]=a[0];
    for(i=0;i<4;i++)
    {
        if(a[i+1]-a[i]>0)
        {
            a[i]=a[i+1]-a[i];
        }
        else
        {
            a[i]=a[i]-a[i+1];
        }
    }
}

int main()
{
    int ji;
    while(scanf("%I64d%I64d%I64d%I64d",&a[0],&a[1],&a[2],&a[3]),!(0==a[0] && 0==a[1] && 0==a[2] && 0==a[3]))
    {
        ji=0;
        while(0==test())
        {
            ji++;
            turn();
        }
        printf("%d\n",ji);
    }
    return 0;
}
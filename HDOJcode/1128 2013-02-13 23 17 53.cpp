******************************
    Author : townboy
    Submit time : 2013-02-13 23:17:53
    Judge Status : Accepted
    HDOJ Runid : 7613713
    Problem id : 1128
    Exe.time : 78MS
    Exe.memory : 4160K
    https://github.com/townboy
******************************


#include<stdio.h>

int hash[1001000];

int fun(int tem)
{
    int sum=tem;
    while(0 != tem)
    {
        sum+=tem%10;
        tem/=10;
    }
    return sum+tem;
}

void chu()
{
    int i;
    for(i=1;i<=1000000;i++)
        hash[fun(i)]=1;
}

int main()
{
    int i;
    chu();
    for(i=1;i<=1000000;i++)
        if(0 == hash[i])
            printf("%d\n",i);
    return 0;
}
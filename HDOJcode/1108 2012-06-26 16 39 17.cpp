******************************
    Author : townboy
    Submit time : 2012-06-26 16:39:17
    Judge Status : Accepted
    HDOJ Runid : 6100622
    Problem id : 1108
    Exe.time : 0MS
    Exe.memory : 224K
    https://github.com/townboy
******************************


#include<stdio.h>

int gcd(int a,int b)
{
    int tem;
    if(a < b)
    {
        tem=a;
        a=b;
        b=tem;
    }
    while(0 != b)
    {
        tem=a%b;
        a=b;
        b=tem;
    }
    return a;
}

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        printf("%d\n",a/gcd(a,b)*b);
    }
    return 0;
}
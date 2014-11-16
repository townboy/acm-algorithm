******************************
    Author : townboy
    Submit time : 2012-06-26 19:28:34
    Judge Status : Accepted
    HDOJ Runid : 6101069
    Problem id : 1722
    Exe.time : 0MS
    Exe.memory : 224K
    https://github.com/townboy
******************************


#include<stdio.h>

int gcd(int da,int xiao)
{    
    int tem;
    if(xiao < da)
    {
        tem=xiao;
        xiao=da;
        da=tem;
    }
    while(0 != xiao)
    {
        tem=da%xiao;
        da=xiao;
        xiao=tem;
    }
    return da;
}

int main()
{
    int p,q;
    while(scanf("%d%d",&p,&q)!=EOF)
    {
        printf("%d\n",p+q-gcd(q,p));
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2013-01-19 22:49:14
    Judge Status : Accepted
    HDOJ Runid : 7518594
    Problem id : 1014
    Exe.time : 0MS
    Exe.memory : 276K
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
    if(0 == b)
    {
        return a;
    }
    return gcd(b,a%b);
}

int main()
{
    int step,mod;
    while(scanf("%d%d",&step,&mod)!=EOF)
    {
        printf("%10d%10d",step,mod);
        if(1 != gcd(step,mod))
            printf("    Bad Choice\n");
        else
            printf("    Good Choice\n");
        printf("\n");
    }
    return 0;
}
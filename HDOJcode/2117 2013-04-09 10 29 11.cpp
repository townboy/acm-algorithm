******************************
    Author : townboy
    Submit time : 2013-04-09 10:29:11
    Judge Status : Accepted
    HDOJ Runid : 8036270
    Problem id : 2117
    Exe.time : 156MS
    Exe.memory : 256K
    https://github.com/townboy
******************************


#include<stdio.h>

int a,b;

int fun()
{
    int big=1;
    while(b > 0)
    {
        b--;
        big*=10;
        big%=(10*a);
    }
    return big/a;
}

int main()
{
    while(scanf("%d%d",&a,&b)!=EOF)
        printf("%d\n",fun());
    return 0;
}
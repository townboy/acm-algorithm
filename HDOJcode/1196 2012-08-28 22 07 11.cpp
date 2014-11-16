******************************
    Author : townboy
    Submit time : 2012-08-28 22:07:11
    Judge Status : Accepted
    HDOJ Runid : 6673409
    Problem id : 1196
    Exe.time : 15MS
    Exe.memory : 248K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int x; 
    while(scanf("%d",&x),x)
    {
        printf("%d\n",x&(-x)); 
    } 
    return 0; 
} 
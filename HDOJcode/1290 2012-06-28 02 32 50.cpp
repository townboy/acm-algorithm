******************************
    Author : townboy
    Submit time : 2012-06-28 02:32:50
    Judge Status : Accepted
    HDOJ Runid : 6104870
    Problem id : 1290
    Exe.time : 15MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int x;
    while(scanf("%d",&x)!=EOF)
    {
        printf("%d\n",(x*x*x+5*x)/6+1);
    }
    return 0;
}
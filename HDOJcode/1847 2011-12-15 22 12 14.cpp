******************************
    Author : townboy
    Submit time : 2011-12-15 22:12:14
    Judge Status : Accepted
    HDOJ Runid : 5169523
    Problem id : 1847
    Exe.time : 0MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int x;
    while(scanf("%d",&x)!=EOF)
    {
        if(0==x%3)
        {
            printf("Cici\n");
        }
        else
        {
            printf("Kiki\n");
        }
    }
return 0;
}
******************************
    Author : townboy
    Submit time : 2011-10-29 02:21:37
    Judge Status : Accepted
    HDOJ Runid : 4845869
    Problem id : 2097
    Exe.time : 15MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main (void)
{ 
    int  n,x,shi,shiliu,shier,i;
    while(scanf("%d",&n),n)
    {
        x=n;
        shi=shiliu=shier=0;
        for(i=0;i<4;i++)
        {
            shi=n%10+shi;
            n=n/10;
        }
        n=x;
        while(n!=0)
        {
            shiliu=n%16+shiliu;
            n=n/16;
        }
        n=x;
        while(n!=0)
        {
            shier=n%12+shier;
            n=n/12;
        }

        if((shi==shiliu)&&(shi==shier))
            printf("%d is a Sky Number.\n",x);
        else
            printf("%d is not a Sky Number.\n",x);




    }
return 0;
}
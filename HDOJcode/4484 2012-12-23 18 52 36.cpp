******************************
    Author : townboy
    Submit time : 2012-12-23 18:52:36
    Judge Status : Accepted
    HDOJ Runid : 7434637
    Problem id : 4484
    Exe.time : 125MS
    Exe.memory : 276K
    https://github.com/townboy
******************************


#include<stdio.h>

int cas,k,n;
int maxx;

int main()
{
    int i;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d",&k,&n);
        maxx=n;
        while(1 != n)
        {
            if(n&1)
                n=n*3+1;
            else
                n>>=1;
            if(n > maxx)
            {
                maxx = n;
            }
        }    
        printf("%d %d\n",k,maxx);
    }
    return 0;
}
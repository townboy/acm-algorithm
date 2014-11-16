******************************
    Author : townboy
    Submit time : 2011-10-30 11:19:51
    Judge Status : Accepted
    HDOJ Runid : 4855506
    Problem id : 2085
    Exe.time : 15MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
   __int64 g[35],d[35];
   int n,max,i;
   max=0;
   g[0]=1;
   d[0]=0;
    while(scanf("%d",&n),n!=-1)
    {  
        if(n<=max)
            printf("%I64d, %I64d\n",g[n],d[n]);

        else
        {
            for(i=max+1;i<=n;i++)
            {
            g[i]=3*g[i-1]+2*d[i-1];
            d[i]=g[i-1]+d[i-1];
            }
            printf("%I64d, %I64d\n",g[n],d[n]);
            max=n;
        }
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-04-07 20:37:51
    Judge Status : Accepted
    HDOJ Runid : 5726705
    Problem id : 4209
    Exe.time : 0MS
    Exe.memory : 204K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int d,p,max,i,n,ji;
    double val;
    ji=0;
    while(scanf("%d",&n),n)
    {
        ji++;
        val=10000000;
        max=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&d,&p);
            if((double)p/(d*d)<val)
            {
                val=(double)p/(d*d);
                max=d;
            }
        }
        printf("Menu %d: %d\n",ji,max);
    }
    return 0;
}
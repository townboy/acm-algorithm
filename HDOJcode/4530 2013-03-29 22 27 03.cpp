******************************
    Author : townboy
    Submit time : 2013-03-29 22:27:03
    Judge Status : Accepted
    HDOJ Runid : 7927082
    Problem id : 4530
    Exe.time : 0MS
    Exe.memory : 240K
    https://github.com/townboy
******************************


#include<stdio.h>

int slow;

int main()
{
    int i,cas,f,q;
    int kind,k;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d",&slow);
        scanf("%d",&q);
        for(f=0;f<q;f++)
        {
            scanf("%d%d",&kind,&k);
            if(1 == kind)
                printf("%d.00\n",k*(60-slow));
            else if(2 == kind)
                printf("%.2lf\n",(double)k*3600/(60-slow));
            else
                printf("%.2lf\n",k*(double)3600*12*60/slow);
        }
    }
    return 0;
}
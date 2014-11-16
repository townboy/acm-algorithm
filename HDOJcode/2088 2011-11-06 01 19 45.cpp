******************************
    Author : townboy
    Submit time : 2011-11-06 01:19:45
    Judge Status : Accepted
    HDOJ Runid : 4910471
    Problem id : 2088
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int num,i,ji,sum,ave,f=0,a[60];
    while(scanf("%d",&num),num)
    {
    
        if(f!=0)
        {
            printf("\n");
        }
        sum=ji=0;
        for(i=0;i<num;i++)
        {
            scanf("%d",&a[i]);
            sum=sum+a[i];
        }
        ave=sum/num;
        for(i=0;i<num;i++)
        {
            if(a[i]>ave)
            {
                ji=ji+(a[i]-ave);
            }
        }
        printf("%d\n",ji);
        f++;
    }
    return 0;
}
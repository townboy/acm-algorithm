******************************
    Author : townboy
    Submit time : 2011-10-16 23:43:39
    Judge Status : Accepted
    HDOJ Runid : 4769640
    Problem id : 2014
    Exe.time : 0MS
    Exe.memory : 200K
    https://github.com/townboy
******************************


#include<stdio.h>
void main()
{
int num,n,min,max,sum,i;
float jg;
    while(scanf("%d",&num)!=EOF)
    {scanf("%d",&n);
    sum=min=max=n;
    
    for(i=1;i<num;i++)
    {
        scanf("%d",&n);
        sum=sum+n;
        if(n<min)
            min=n;
        if(n>max)
            max=n;
    }
    jg=(float)(sum-min-max)/(num-2);
    printf("%.2f\n",jg);
    }
}
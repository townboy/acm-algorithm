******************************
    Author : townboy
    Submit time : 2012-06-29 11:47:21
    Judge Status : Accepted
    HDOJ Runid : 6107268
    Problem id : 1003
    Exe.time : 15MS
    Exe.memory : 588K
    https://github.com/townboy
******************************


#include<stdio.h>

int que[101100];

int main()
{
    int last,i,num,f,max,start,end,k,sum;
scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        if(0 != i)
        {
            printf("\n");
        }
        scanf("%d",&k);
        last=1;
        sum=0;
        max=-1000000;
        
        for(f=1;f<=k;f++)
        {
            scanf("%d",&que[f]);
            if(sum >= 0)
            {
                sum+=que[f];
            }
            else
            {
                sum=que[f];
                last=f;
            }
            if(sum > max)
            {
                start=last;
                end=f;
                max=sum;
            }
        }
        printf("Case %d:\n%d %d %d\n",i+1,max,start,end);
    }
    return 0;
}
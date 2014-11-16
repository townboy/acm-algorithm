******************************
    Author : townboy
    Submit time : 2012-02-19 01:45:00
    Judge Status : Accepted
    HDOJ Runid : 5375699
    Problem id : 4153
    Exe.time : 0MS
    Exe.memory : 204K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int max,ma,n,w,i,ji[25],x,f;
    double sum;
    while(scanf("%d%d",&n,&w),n+w)
    {
        max=0;
        ma=0;
        for(i=0;i<=20;i++)
        {
            ji[i]=0;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            for(f=1;;f++)
            {
                if(x<w*f)
                {
                    ji[f]++;
                    if(f>max)
                    {
                        max=f;
                    }
                    if(ji[f]>ma)
                    {
                        ma=ji[f];
                    }
                    break;
                }
            }
        }
        sum=0.01;
        for(i=1;i<=max;i++)
        {
            sum=sum+(double)(max-i)/(max-1)*(double)ji[i]/ma;
        }  
        printf("%.6lf\n",sum);
    }
    return 0;
}
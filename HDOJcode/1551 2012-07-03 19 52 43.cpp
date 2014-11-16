******************************
    Author : townboy
    Submit time : 2012-07-03 19:52:43
    Judge Status : Accepted
    HDOJ Runid : 6123570
    Problem id : 1551
    Exe.time : 125MS
    Exe.memory : 284K
    https://github.com/townboy
******************************


#include<stdio.h>

int aim,n;
double zan[11000];

int check(double v)
{
    int i,ans=0;
    double yu;
    for(i=0;i<n;i++)
    {
        yu=zan[i];
        while(yu >= v)
        {
            ans++;
            yu-=v;            
        }
    }
    if(ans >= aim)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int i;
    double l,r,mid,sum;
    while(scanf("%d%d",&n,&aim),0 != n+aim)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%lf",&zan[i]);
            sum+=zan[i];
        }    
        l=0;
        r=sum/aim;
        while(r-l > 1e-8)
        {
            mid=(l+r)/2;
            if(1 == check(mid))
            {
                l=mid;
            }
            else
            {
                r=mid;
            }
        }
        if(mid < 0.01)
        {
            printf("0.00\n");
            continue;
        }
        printf("%.2lf\n",mid);
    }
    return 0;
}
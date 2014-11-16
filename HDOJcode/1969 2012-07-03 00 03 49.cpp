******************************
    Author : townboy
    Submit time : 2012-07-03 00:03:49
    Judge Status : Accepted
    HDOJ Runid : 6119689
    Problem id : 1969
    Exe.time : 46MS
    Exe.memory : 284K
    https://github.com/townboy
******************************


#include<math.h>
#include<stdio.h>
#define PI acos(-1.0)

double zan[10000];
int F,n;

int check(double v)
{
    double yu;
    int i,ans=0;
    for(i=0;i<n;i++)
    {
        yu=zan[i]*zan[i]*PI;
        while(yu >= v)
        {
            yu-=v;    
            ans++;    
        }
    }
    if(ans >= F)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int f,i,num;
    double r,l,mid,sum;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&n,&F);
        F++;
        sum=0;
        for(f=0;f<n;f++)
        {
            scanf("%lf\n",&zan[f]);
            sum+=PI*zan[f]*zan[f];
        }
        l=0;
        r=sum/F;
        while(r-l > 1e-6)
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
        printf("%.4lf\n",mid);
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-08-09 20:23:27
    Judge Status : Accepted
    HDOJ Runid : 6499303
    Problem id : 4355
    Exe.time : 734MS
    Exe.memory : 1024K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
#define INF 0x7fffffff
#define eps 1e-7

double x[51000],w[51000];
int n;

double cal(double xx)
{
    int i;
    double sum=0;
    for(i=0;i<n;i++)
    {
        sum+=fabs(x[i]-xx)*(x[i]-xx)*(x[i]-xx)*w[i];
    }
    return sum;
}

double san()
{
    double l,r,ml,mr;
    l=x[0];
    r=x[n-1];
    while(r-l > 1e-4)
    {
        ml=(2*l+r)/3;
        mr=(l+2*r)/3;
        if(cal(ml) > cal(mr))
        {
            l=ml+eps;        
        }
        else 
        {
            r=mr-eps;    
        }
    }
    return cal(l);    
}

int main()
{
    int num,i,f;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        for(f=0;f<n;f++)
        {
            scanf("%lf%lf",&x[f],&w[f]);
        }
        printf("Case #%d: %.0lf\n",i+1,san());
    }
    return 0;
}
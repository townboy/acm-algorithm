******************************
    Author : townboy
    Submit time : 2012-09-12 21:36:42
    Judge Status : Accepted
    HDOJ Runid : 6753293
    Problem id : 3132
    Exe.time : 0MS
    Exe.memory : 268K
    https://github.com/townboy
******************************


#include<stdio.h>

double x[11000],y[11000];

int main()
{
    int i,n;
    double sum;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        scanf("%lf,%lf",&x[0],&y[0]);
        for(i=1;i<n;i++)
        {
            scanf("%lf,%lf",&x[i],&y[i]);
            sum+=(y[i]+y[i-1])*(x[i]-x[i-1])/2;
        }
        printf("%.2lf to %.2lf: %.4lf\n",x[0],x[n-1],sum);
    }
    return 0;
}
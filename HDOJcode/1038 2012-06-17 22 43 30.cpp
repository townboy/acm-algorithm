******************************
    Author : townboy
    Submit time : 2012-06-17 22:43:30
    Judge Status : Accepted
    HDOJ Runid : 6075899
    Problem id : 1038
    Exe.time : 0MS
    Exe.memory : 204K
    https://github.com/townboy
******************************


#include<stdio.h>
#define PI 3.1415927
int main()
{
    double d,q,t;
    int ji=0;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%lf%lf%lf",&d,&q,&t)!=EOF)
    {
        ji++;
        if(0 == q)
        {
            break;
        }
        printf("Trip #%d: ",ji);
        printf("%.2lf %.2lf\n",PI*d*q/5280/12,PI*d*q/5280/12/(t/3600));
    }
    return 0;
}
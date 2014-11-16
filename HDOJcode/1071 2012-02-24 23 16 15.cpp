******************************
    Author : townboy
    Submit time : 2012-02-24 23:16:15
    Judge Status : Accepted
    HDOJ Runid : 5409014
    Problem id : 1071
    Exe.time : 0MS
    Exe.memory : 204K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int i,num,f;
    double x[5],y[5],a,b,c,d,e,res1,res2;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        for(f=1;f<=3;f++)
        {
            scanf("%lf%lf",&x[f],&y[f]);
        }
        a=(y[2]-y[1])/((x[2]-x[1])*(x[2]-x[1]));
        b=-2*a*x[1];
        c=x[1]*x[1]*a+y[1];
        d=(y[3]-y[2])/(x[3]-x[2]);
        e=y[2]-d*x[2];
        res2=(double)1/3*a*x[3]*x[3]*x[3]+(b-d)/2*x[3]*x[3]+(c-e)*x[3];
        res1=(double)1/3*a*x[2]*x[2]*x[2]+(b-d)/2*x[2]*x[2]+(c-e)*x[2];
        printf("%.2lf\n",res2-res1);
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-05-07 23:41:36
    Judge Status : Accepted
    HDOJ Runid : 5912505
    Problem id : 2298
    Exe.time : 0MS
    Exe.memory : 260K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>

#define eps 1e-9
#define PI 3.1415927
double max,x,y,v;

double fun(double z)
{
    double t;
    t=x/(v*cos(z));
    return v*sin(z)*t-4.9*t*t;
}

int san()
{
    double l,r,ml,mr;
    l=0;
    r=PI/2;
    
    while(r-l>eps)
    {
        ml=(2*l+r)/3;
        mr=(l+2*r)/3;
        if( fun(ml) < fun(mr))
        {
            l=ml;    
        }
        else
        {
            r=mr;
        }
    }
    if(fun(l) >= y)
    {
        max=l;
        return 1;
    }
    return 0;
}

double er()
{
    double l,r,mid;
    l=0;
    r=max;

    while(r-l>eps)
    {
        mid=(l+r)/2;
        if(fun(mid) > y)
        {
            r=mid;
        }
        else
        {
            l=mid;
        }
    }
    return l;
}

int main()
{
    int i,num;
//    freopen("D:\\in.txt","r",stdin);
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%lf%lf%lf",&x,&y,&v);
        if(0 == san())
        {
            printf("-1\n");
        }
        else
        {
            printf("%lf\n",er());
        }
    }
    return 0;
}
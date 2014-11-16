******************************
    Author : townboy
    Submit time : 2012-08-21 17:34:01
    Judge Status : Accepted
    HDOJ Runid : 6623520
    Problem id : 4386
    Exe.time : 171MS
    Exe.memory : 500K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
#include<iostream>
#define eps 1e-12
using namespace std;

double tem[4],a,b,c,d;

double hai(double a,double b,double c)
{
    double mid=(a+b+c)/2;     
    return sqrt((mid-a)*(mid-b)*(mid-c)*mid);
}

int cmp(const void*a,const void*b)
{
    if(*(double *)a-*(double *)b > 0)
    {
        return 1;
    }
    return -1;
}

double san()
{
    double l,r,ml,mr;
    r=min(a+b,c+d);
    l=max(fabs(a-b),fabs(c-d));
    if(l > r)
    {
        return -1;
    }
    while(r-l > eps)
    {
        ml=(2*l+r)/3;
        mr=(l+2*r)/3;
        if(hai(ml,a,b)+hai(ml,c,d) > hai(mr,a,b)+hai(mr,c,d))
        {
            r=mr;        
        }
        else
        {
            l=ml;    
        }
    }
    return hai(l,a,b)+hai(l,c,d);
}

void swap(double &a,double &b)
{
    double tem=a;
    a=b;
    b=tem;
}

int main()
{
    int num,i;
    double ans;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        ans=-1;
        printf("Case %d: ",i+1);

        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        tem[0]=a;
        tem[1]=b;
        tem[2]=c;
        tem[3]=d;
        qsort(tem,4,sizeof(tem[0]),cmp);
        if(tem[3] >= tem[0]+tem[1]+tem[2])
        {
            printf("-1\n");
            continue;            
        }
        
        ans=san();
        swap(b,c);
        ans=max(ans,san());
        printf("%.6f\n",ans);
    }
    return 0;
}
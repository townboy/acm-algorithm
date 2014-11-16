******************************
    Author : townboy
    Submit time : 2012-10-11 00:31:34
    Judge Status : Accepted
    HDOJ Runid : 6902038
    Problem id : 2056
    Exe.time : 15MS
    Exe.memory : 216K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
using namespace std;

double xmax1,xmin1,ymin1,ymax1,xmax2,xmin2,ymin2,ymax2;
double x1,x2,x3,x4,y1,y2,y3,y4;

double abss(double x)
{
    return x>0?x:0;
}

int main()
{
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)!=EOF)
    {
        xmin1=min(x1,x2);
        xmax1=max(x1,x2);
        ymin1=min(y1,y2);
        ymax1=max(y1,y2);
        xmin2=min(x3,x4);
        xmax2=max(x3,x4);
        ymin2=min(y3,y4);
        ymax2=max(y3,y4);                        
        printf("%.2lf\n",abss(min(xmax1,xmax2)-max(xmin1,xmin2))*abss(min(ymax1,ymax2)-max(ymin1,ymin2)));
    }
    return 0;
}
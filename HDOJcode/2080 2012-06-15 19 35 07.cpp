******************************
    Author : townboy
    Submit time : 2012-06-15 19:35:07
    Judge Status : Accepted
    HDOJ Runid : 6070327
    Problem id : 2080
    Exe.time : 15MS
    Exe.memory : 212K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
#define PI 3.1415927

double x1,x2,y3,y2;

double cha()
{
    return x1*y2-x2*y3;
}

int main()
{
    double res,mian,b1,b2;
    int num,i;
//    freopen("D:\\in.txt","r",stdin);
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%lf%lf%lf%lf",&x1,&y3,&x2,&y2);
        mian=fabs(cha());
        b1=sqrt(x1*x1+y3*y3);
        b2=sqrt(x2*x2+y2*y2);
        res=fabs(asin(mian/b1/b2)*180/PI);
        if(x1*x2+y2*y3 < 0)
        {
            res=180-res;
        }
        printf("%.2lf\n",res);
    }
    return 0;
}

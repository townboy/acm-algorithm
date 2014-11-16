******************************
    Author : townboy
    Submit time : 2011-12-13 22:11:07
    Judge Status : Accepted
    HDOJ Runid : 5161679
    Problem id : 2289
    Exe.time : 0MS
    Exe.memory : 192K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI acos(-1.0)
int num,i;
double r1,r2,h,v,min,max,m;
double me(double x)
{ 
    double shang,xia;
    shang=(r1+x/h*(r2-r1))*(r1+x/h*(r2-r1))*PI;
    xia=r1*r1*PI;
    return x*(xia+shang+sqrt(shang*xia))/3;
}
int main(void)
{
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%lf%lf%lf%lf",&r1,&r2,&h,&v);
        if(me(h)<v)
        {
            printf("%.6lf\n",h);
        }
        else
        {
            min=0;
            max=h;
            while((max-min)>1e-8)
            {
                m=(min+max)/2;
                if(me(m)<v)
                {
                    min=m;
                }
                else
                {
                    max=m;
                }
            }
            printf("%.6lf\n",m);
        }
    }
return 0;

}
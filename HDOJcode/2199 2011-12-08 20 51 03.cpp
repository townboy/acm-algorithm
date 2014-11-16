******************************
    Author : townboy
    Submit time : 2011-12-08 20:51:03
    Judge Status : Accepted
    HDOJ Runid : 5137085
    Problem id : 2199
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
double me(double x)
{
    return (8*pow(x,4)+7*pow(x,3)+2*pow(x,2)+3*pow(x,1)+6);
}
int main(void)
{
    double left,mid,right,y;
    int i,num;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%lf",&y);
        if((me(100)<y)||(me(0)>y))
        {
            printf("No solution!\n");
        }
        else
        {
            right=100;
            left=0;
            mid=50;
             while(!(fabs(me(mid)-y)<(10e-6)))
             {
                 if(me(mid)<y)
                 {
                     left=mid;
                 }
                 else
                 {
                     right=mid;
                 }
                 mid=(right+left)/2;
             }
             printf("%.4lf\n",mid);
        }
    
    }
return 0;
}
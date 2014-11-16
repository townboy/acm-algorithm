******************************
    Author : townboy
    Submit time : 2011-12-08 21:37:42
    Judge Status : Accepted
    HDOJ Runid : 5137454
    Problem id : 2899
    Exe.time : 0MS
    Exe.memory : 216K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
double y;
double dao(double x)
{
    return (42*pow(x,6)+48*pow(x,5)+21*pow(x,2)+10*x);
}
double me(double x)
{
    return (6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*pow(x,2)-y*x);
}
int main(void)
{
    int num,i;
    double left,right,m;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%lf",&y);
        if(dao(0)>=y)
        {
            printf("%.4lf\n",me(0));
        }
        else if(dao(100)<=y)
        {
            printf("%.4lf\n",me(100));
        }
        else
        {
            left=0;
            right=100;
            while(right-left>10e-6)
            {
                m=(left+right)/2;
                if(dao(m)>y)
                {
                     right=m;
                }
                else
                {
                    left=m;
                }
            }
            printf("%.4lf\n",me(m));
        
        }
    
    
    }



return 0;

}
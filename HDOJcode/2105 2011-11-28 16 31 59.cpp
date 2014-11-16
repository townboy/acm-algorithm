******************************
    Author : townboy
    Submit time : 2011-11-28 16:31:59
    Judge Status : Accepted
    HDOJ Runid : 5072641
    Problem id : 2105
    Exe.time : 62MS
    Exe.memory : 188K
    https://github.com/townboy
******************************



#include<stdio.h>
int main(void)
{
    int num,i;
    double x1,x2,x3,y1,y2,y3;
    while(scanf("%d",&num),num)
    {
        for(i=0;i<num;i++)
        {
             scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
             printf("%.1lf %.1lf\n",(x1+x2+x3)/3,(y1+y2+y3)/3);
        }
    
    }
   
return 0;
}
******************************
    Author : townboy
    Submit time : 2011-10-13 16:59:49
    Judge Status : Accepted
    HDOJ Runid : 4749749
    Problem id : 2003
    Exe.time : 0MS
    Exe.memory : 220K
    https://github.com/townboy
******************************


#include<stdio.h>
void main()
{
    double x;
    while(scanf("%lf",&x)!=EOF)
    {
     if(x<0)
         printf("%.2lf\n",-x);
     else 
       printf("%.2lf\n",x);
    }
}

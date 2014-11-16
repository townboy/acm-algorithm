******************************
    Author : townboy
    Submit time : 2013-02-27 17:26:36
    Judge Status : Accepted
    HDOJ Runid : 7660633
    Problem id : 4438
    Exe.time : 15MS
    Exe.memory : 264K
    https://github.com/townboy
******************************


#include<stdio.h>

int x,y;
double p,q;
double tiger,wolf;

void fun()
{
    tiger=(1-q)*x+q*(p*x+p*y);
    wolf=q*y+(1-q)*(p*x+p*y);
}

int main()
{
    int i,cas;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d%lf%lf",&x,&y,&p,&q);
        fun();
        if(tiger > wolf)
            printf("tiger %.4lf\n",tiger);
        else
            printf("wolf %.4lf\n",wolf);
    }
    return 0;
}
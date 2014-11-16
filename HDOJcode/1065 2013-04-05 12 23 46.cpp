******************************
    Author : townboy
    Submit time : 2013-04-05 12:23:46
    Judge Status : Accepted
    HDOJ Runid : 8004573
    Problem id : 1065
    Exe.time : 78MS
    Exe.memory : 240K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
#define PI 3.1415926

int main()
{
    double x,y,r;
    int ans,i,cas;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%lf%lf",&x,&y);
        r=sqrt(x*x+y*y);
        ans=PI*r*r/100.0;
        printf("Property %d: This property will begin eroding in year %d.\n",i+1,(int)ans+1);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
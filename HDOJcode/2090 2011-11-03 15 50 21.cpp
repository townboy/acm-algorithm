******************************
    Author : townboy
    Submit time : 2011-11-03 15:50:21
    Judge Status : Accepted
    HDOJ Runid : 4888959
    Problem id : 2090
    Exe.time : 0MS
    Exe.memory : 220K
    https://github.com/townboy
******************************


#include<stdio.h>
int main (void)
{
    char ch[100];
    double a,b,sum;
    sum=0;
    while(scanf("%s%lf%lf",ch,&a,&b)!=EOF)
    {
        sum=sum+a*b;
    }
    printf("%.1lf\n",sum);
 return 0;
}
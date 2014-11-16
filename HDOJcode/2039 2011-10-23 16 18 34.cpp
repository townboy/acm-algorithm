******************************
    Author : townboy
    Submit time : 2011-10-23 16:18:34
    Judge Status : Accepted
    HDOJ Runid : 4808921
    Problem id : 2039
    Exe.time : 0MS
    Exe.memory : 200K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int num,i;
    double a,b,c,max;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
    scanf("%lf%lf%lf",&a,&b,&c);
    max=a;
    if(b>max)
        max=b;
    if(c>max)
        max=c;
    if(a+b+c>2*max)
        printf("YES\n");
    else 
        printf("NO\n");
    }

return 0;


}
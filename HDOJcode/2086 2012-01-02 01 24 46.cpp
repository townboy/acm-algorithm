******************************
    Author : townboy
    Submit time : 2012-01-02 01:24:46
    Judge Status : Accepted
    HDOJ Runid : 5224675
    Problem id : 2086
    Exe.time : 78MS
    Exe.memory : 212K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    double x,a[3100],c[3100],me;
    int i,num;
    while(scanf("%d",&num)!=EOF)
    {
        scanf("%lf%lf",&a[0],&me);
        a[1]=0;
        for(i=1;i<=num;i++)
        {
            scanf("%lf",&c[i]);
        }
        for(i=2;i<=num+1;i++)
        {
            a[i]=2*(a[i-1]+c[i-1])-a[i-2];
        }
        x=(me-a[num+1])/(num+1);
        printf("%.2lf\n",x);
    }

return 0;
}
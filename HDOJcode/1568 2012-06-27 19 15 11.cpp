******************************
    Author : townboy
    Submit time : 2012-06-27 19:15:11
    Judge Status : Accepted
    HDOJ Runid : 6104056
    Problem id : 1568
    Exe.time : 0MS
    Exe.memory : 232K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
int main()
{
    double m;
    int x,a[40],i;
    a[0]=0;
    a[1]=1;
    for(i=2;i<=30;i++)
    {
        a[i]=a[i-2]+a[i-1];
    }
    while(scanf("%d",&x)!=EOF)
    {    
        if(x <= 30)
        {
            while(a[x] >= 10000)
            {
                a[x]/=10;
            }
            printf("%d\n",a[x]);
            continue;
        }
        m=log10(1/sqrt(5))+ x*log10( ( 1+sqrt(5) )/2 ) - (int) ( log10(1/sqrt(5))+ x*log10( ( 1+sqrt(5) )/2 ) );
        m=pow(10,m);
        while(m < 1000)
        {
            m*=10;
        }
        x=m;
        printf("%d\n",x);
    }
    return 0;
}
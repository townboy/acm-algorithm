******************************
    Author : townboy
    Submit time : 2012-07-03 21:11:26
    Judge Status : Accepted
    HDOJ Runid : 6124088
    Problem id : 2438
    Exe.time : 0MS
    Exe.memory : 212K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
#define PI acos(-1.0)

double x,y,l,d;

double fun(double sita)
{
    return (d/cos(sita)+l*sin(sita)-x)/tan(sita);
}

int main()
{
    int i;
    double right,left,midl,midr;
    while(scanf("%lf%lf%lf%lf",&x,&y,&l,&d)!=EOF)
    {
        left=0;
        right=PI/2;
        while(right-left > 1e-10)
        {
            midl=(2*left+right)/3;
            midr=(left+right*2)/3;
            if(fun(midl)>fun(midr))
            {
                right=midr;    
            }
            else
            {
                left=midl;
            }
        }
        if(fun(midl) > y)
        {
            printf("no\n");
        }
        else
        {    
            printf("yes\n");
        }
    }
    return 0;
}
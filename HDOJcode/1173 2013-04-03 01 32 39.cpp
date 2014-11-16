******************************
    Author : townboy
    Submit time : 2013-04-03 01:32:39
    Judge Status : Accepted
    HDOJ Runid : 7973505
    Problem id : 1173
    Exe.time : 265MS
    Exe.memory : 1824K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<algorithm>

using namespace std;

double x[1000010],y[1000010];

int main()
{
    int i,n;
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;i++)
            scanf("%lf%lf",x+i,y+i);
        sort(x,x+n);
        sort(y,y+n);
        printf("%.2lf %.2lf\n",x[n/2],y[n/2]);
    }
    return 0;
}
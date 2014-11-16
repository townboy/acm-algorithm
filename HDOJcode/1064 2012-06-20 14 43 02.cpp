******************************
    Author : townboy
    Submit time : 2012-06-20 14:43:02
    Judge Status : Accepted
    HDOJ Runid : 6084546
    Problem id : 1064
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    double sum,x;
    int i;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%lf",&x)!=EOF)
    {
        sum=x;
        for(i=0;i<11;i++)
        {
            scanf("%lf",&x);
            sum+=x;
        }
        printf("$%.2lf\n",sum/12);
    }
    return 0;
}

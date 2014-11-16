******************************
    Author : townboy
    Submit time : 2011-10-23 23:45:01
    Judge Status : Accepted
    HDOJ Runid : 4812308
    Problem id : 2035
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int a,b,sum,i;
    while(scanf("%d%d",&a,&b),!(a==0&&b==0))
    {   
        sum=1;
        for(i=0;i<b;i++)
        {
            sum=sum*a;
            sum=sum%1000;
        }
    printf("%d\n",sum);
    }
return 0;
}
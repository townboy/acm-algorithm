******************************
    Author : townboy
    Submit time : 2011-11-28 17:06:10
    Judge Status : Accepted
    HDOJ Runid : 5072934
    Problem id : 2156
    Exe.time : 281MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int num,i;
    double sum;
    while(scanf("%d",&num),num)
    {
        sum=0;
        for(i=0;i<num;i++)
        {
            sum=sum+(double)(num-i)/(i+1);
        }
        printf("%.2lf\n",2*sum-num);
    
    }


return 0;
}
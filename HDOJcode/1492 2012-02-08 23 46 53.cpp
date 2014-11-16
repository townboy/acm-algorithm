******************************
    Author : townboy
    Submit time : 2012-02-08 23:46:53
    Judge Status : Accepted
    HDOJ Runid : 5331433
    Problem id : 1492
    Exe.time : 31MS
    Exe.memory : 144K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    __int64 num,div[4]={2,3,5,7},sum,ji[4],i;
    while(scanf("%I64d",&num),num)
    {
        for(i=0;i<4;i++)
        {
            ji[i]=0;
            while(0==num%div[i])
            {
                ji[i]++;
                num=num/div[i];
            }
        }
        sum=1;
        for(i=0;i<4;i++)
        {
            sum=sum*(ji[i]+1);
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
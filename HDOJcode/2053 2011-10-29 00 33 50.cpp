******************************
    Author : townboy
    Submit time : 2011-10-29 00:33:50
    Judge Status : Accepted
    HDOJ Runid : 4845574
    Problem id : 2053
    Exe.time : 78MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main (void)
{
    int num,i,sum;
    while(scanf("%d",&num)!=EOF)
    {
        sum=0;
        for(i=1;i<=num;i++)
        {
            if(num%i==0)
                sum++;
        }
        printf("%d\n",sum%2);
    }

   return 0;

}
******************************
    Author : townboy
    Submit time : 2011-12-27 21:29:07
    Judge Status : Accepted
    HDOJ Runid : 5211801
    Problem id : 2178
    Exe.time : 0MS
    Exe.memory : 200K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int num,sum,i,f,x;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        sum=1;
        scanf("%d",&x);
        for(f=0;f<x;f++)
        {
            sum=sum*2;
        }
        printf("%d\n",sum-1);
    }
return 0;
}
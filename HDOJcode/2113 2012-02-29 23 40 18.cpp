******************************
    Author : townboy
    Submit time : 2012-02-29 23:40:18
    Judge Status : Accepted
    HDOJ Runid : 5439913
    Problem id : 2113
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int num,sum,x,ji;
    ji=0;
    while(scanf("%d",&num)!=EOF)
    {
        ji++;
        sum=0;
        while(0!=num)
        {
            if(0==(x=num%10)%2)
            {
                sum=sum+x;
            }
            num=num/10;
        }
        if(1!=ji)
        {
            printf("\n%d\n",sum);    
        }
        else
        {
            printf("%d\n",sum);
        }
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2011-11-21 21:23:01
    Judge Status : Accepted
    HDOJ Runid : 5029807
    Problem id : 1197
    Exe.time : 0MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
int test1(int x)
{
    int sum;
    while(x!=0)
    {
        sum=sum+x%10;
        x=x/10;
    }
    return sum;
}

int test2(int x)
{
    int sum;
    while(x!=0)
    {
        sum=sum+x%12;
        x=x/12;
    }
    return sum;
}

int test3(int x)
{
    int sum;
    while(x!=0)
    {
        sum=sum+x%16;
        x=x/16;
    }
    return sum;
}

int main(void)
{
    int i,s1,s2,s3;
    for(i=1000;i<=9999;i++)
    {
        s1=test1(i);
        s2=test2(i);
        s3=test3(i);
        if((s1==s2)&&(s2==s3))
        {
            printf("%d\n",i);
        }
    }
    return 0;
}

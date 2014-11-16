******************************
    Author : townboy
    Submit time : 2012-01-04 23:36:25
    Judge Status : Accepted
    HDOJ Runid : 5230129
    Problem id : 4151
    Exe.time : 734MS
    Exe.memory : 9948K
    https://github.com/townboy
******************************


#include<stdio.h>
char a[10010000];
int me(int x)
{
    int i,tem;
    char zan[10];
    for(i=0;i<10;i++)
    {
        zan[i]=0;
    }
    while(x!=0)
    {
        tem=x%10;
        if(1==zan[tem])
        {
            return 0;
        }
        zan[tem]=1;
        x=x/10;
    }
    return 1;
}
int main(void)
{
    int i,f,num,sum,ji;
    sum=0;
    a[1]=0;
    for(i=1;i<=9;i++)
    {
        sum++;
        a[i]=1;
    }
    for(i=1;i<1000001;i++)
    {
        if(0==a[i])
        {
            for(f=0;f<10;f++)
            {
                a[10*i+f]=0;
            }
        }
        else
        {
            for(f=0;f<10;f++)
            {
                if(1==me(10*i+f))
                {
                    a[10*i+f]=1;
                    sum++;
                }
                else
                {
                    a[10*i+f]=0;
                }
            }
        }
    }
    while(scanf("%d",&num)!=EOF)
    {
        ji=0;
        for(i=1;i<num;i++)
        {
            if(1==a[i])
            {
                ji++;
            }
        }
        printf("%d\n",ji);
    }
return 0;
}
******************************
    Author : townboy
    Submit time : 2012-01-04 23:53:57
    Judge Status : Accepted
    HDOJ Runid : 5230148
    Problem id : 4151
    Exe.time : 765MS
    Exe.memory : 9948K
    https://github.com/townboy
******************************


#include<stdio.h>
char a[10010000];
int main(void)
{
    int i,f,num,sum,ji,g,x;
    char zan[10];
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
                for(g=0;g<10;g++)
                {
                    zan[g]=0;
                }
                x=i;
                while(x!=0)
                {
                    zan[x%10]=1;
                    x=x/10;
                }
                for(g=0;g<10;g++)
                {
                    if(1==zan[g])
                    {
                        a[10*i+g]=0;
                    }
                    else
                    {
                        a[10*i+g]=1;
                    }
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
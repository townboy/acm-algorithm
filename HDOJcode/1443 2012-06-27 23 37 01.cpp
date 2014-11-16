******************************
    Author : townboy
    Submit time : 2012-06-27 23:37:01
    Judge Status : Accepted
    HDOJ Runid : 6104760
    Problem id : 1443
    Exe.time : 281MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>

int hash[30],a[30];

void change(int now,int yu)
{
    int i;
    for(i=now;i<yu-1;i++)
    {
        hash[i]=hash[i+1];
    }
}

int check(int k,int m)
{
    int yu=2*k,bad=k,i,now;
    for(i=0;i<2*k;i++)
    {
        hash[i]=i+1;
    }
    now=0;
    while(0 != bad)
    {
        now+=m-1;
        now=now%yu;
        if(hash[now] > k)
        {
            change(now,yu);
            bad--;
            yu--;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int i,m,x;
    for(i=1;i<14;i++)
    {
        for(m=1;;m++)
        {
            if(1 == check(i,m))
            {
                a[i]=m;
                break;
            }
        }
    }
    while(scanf("%d",&x),0 != x)
    {
        printf("%d\n",a[x]);
    }
    return 0;
}
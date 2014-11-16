******************************
    Author : townboy
    Submit time : 2012-07-01 14:47:15
    Judge Status : Accepted
    HDOJ Runid : 6113322
    Problem id : 1059
    Exe.time : 546MS
    Exe.memory : 488K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<memory.h>

int dp[75000],a[10];

void chu()
{
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    memset(a,0,sizeof(a));
}

void mul(int i)
{
    int f;
    for(f=70000;f>=0;f--)
    {
        if(f-i < 0)
        {
            return ;
        }    
        dp[f]+=dp[f-i];
    }
}

int main()
{
    int i,f,k;
    int sum,ji=0;
    while(scanf("%d",&a[0])!=EOF)
    {
        ji++;
        sum=a[0];
        chu();
        for(i=1;i<=5;i++)
        {    
            scanf("%d",&a[i]);
            sum+=a[i]*(i+1);
        }
        if(0 == sum)
        {
            break;
        }    
        if(1 == (1&sum))
        {
            printf("Collection #%d:\nCan't be divided.\n\n",ji);
            continue;
        }
        for(i=0;i<6;i++)
        {
            k=1;
            while(a[i] - k > 0)
            {
                a[i]-=k;
                mul(k*(i+1));
                k*=2;
            }
            mul(a[i]*(i+1));
        }
        
        if(0 != dp[sum/2])
        {
            printf("Collection #%d:\nCan be divided.\n\n",ji);
        }
        else
        {
            printf("Collection #%d:\nCan't be divided.\n\n",ji);
        }
    }
    return 0;
}
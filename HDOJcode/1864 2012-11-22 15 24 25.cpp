******************************
    Author : townboy
    Submit time : 2012-11-22 15:24:25
    Judge Status : Accepted
    HDOJ Runid : 7224036
    Problem id : 1864
    Exe.time : 234MS
    Exe.memory : 20272K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int n,limit;
int dp[5100000];

void chu()
{
    memset(dp,0,sizeof(dp));
    dp[0]=1;
}

void update(int val)
{
    int i;
    for(i=limit;i>=val;i--)
        if(1 == dp[i-val])
            dp[i]=1;
}

int main()
{
    double zan;
    char flag,k;
    double num,sum,asum,bsum,csum;
    int i,f,p,kk;
    while(scanf("%lf%d",&zan,&n),n!=0)
    {
        limit=zan*100+0.01;
        chu();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&p);
            
            asum=bsum=csum=sum=0;
            kk=1;
            
            for(f=0;f<p;f++)
            {
                scanf("%c%c%c%lf",&k,&flag,&k,&num);
                if('A' == flag)
                    asum+=num;
                else if('B' == flag)
                    bsum+=num;
                else if('C' == flag)
                    csum+=num;
                else
                    kk=-1;
                sum+=num;
            }
            if(-1 == kk || sum > 1000 || asum>600 || bsum>600 || csum>600)
                continue;
            update((int)(sum*100+0.01));
        }
        for(i=limit;i>=0;i--)
            if(1 == dp[i])
            {
                printf("%.2lf\n",i/100.0);        
                break;
            }
    }
    return 0;
}
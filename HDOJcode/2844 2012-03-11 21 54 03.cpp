******************************
    Author : townboy
    Submit time : 2012-03-11 21:54:03
    Judge Status : Accepted
    HDOJ Runid : 5527201
    Problem id : 2844
    Exe.time : 656MS
    Exe.memory : 616K
    https://github.com/townboy
******************************


#include<stdio.h>
int vall[10000],ji,dp[200000];
void find(int n,int val)
{
    int i,sum,zan;
    sum=1;
    zan=1;
    for(i=0;;i++)
    {
        vall[ji]=val*zan;
        ji++;
        zan=zan*2;
        sum=sum+zan;
        if(sum>n)
        {
            break;    
        }
        else if(sum==n)
        {
            vall[ji]=val*zan;
            ji++;
            return ;
        }
    }
    vall[ji]=val*(n-(sum-zan));
    ji++;
}
int main()
{
    int n,m,val[200],num[200],i,f,sum,pr;
    while(scanf("%d%d",&n,&m),!(0==n&&0==m))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&val[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
        }
        ji=0;
        for(i=0;i<n;i++)
        {
            if(1==num[i])
            {
                vall[ji]=num[i]*val[i];
                ji++;
            }
            else
            {
                find(num[i],val[i]);        
            }
        }
        for(i=0;i<=m;i++)
        {
            dp[i]=0;
        }
        for(i=0;i<ji;i++)
        {
            for(f=m;f>=0;f--)
            {
                if(f<vall[i])
                {
                    break;
                }
                if(dp[f-vall[i]]+vall[i]>dp[f])
                {
                    dp[f]=dp[f-vall[i]]+vall[i];
                }
            }
        }
        pr=0;
        for(i=1;i<=m;i++)
        {
            if(dp[i]==i)
            {
                pr++;
            }
        }
        printf("%d\n",pr);
    }
    return 0;
}
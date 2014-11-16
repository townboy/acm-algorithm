******************************
    Author : townboy
    Submit time : 2012-03-11 20:20:31
    Judge Status : Accepted
    HDOJ Runid : 5526047
    Problem id : 1171
    Exe.time : 46MS
    Exe.memory : 476K
    https://github.com/townboy
******************************


#include<stdio.h>
int dp[500000],val[100000];
int find(int n)
{
    int i,sum;
    sum=1;
    for(i=0;;i++)
    {
        if(sum-1>n)
        {
            break;
        }
        sum=sum*2;
    }
    return i-1;
}
int main()
{
    int n,i,f,v,sum,ji,zan,vall,numm,k;
    while(scanf("%d",&n),n>0)
    {
        sum=0;
        ji=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&vall,&numm);
            sum=sum+vall*numm;
            if(1!=numm)
            {
                k=find(numm);
                zan=1;
                for(f=0;f<k;f++)
                {
                    val[ji]=zan*vall;
                    zan=zan*2;
                    ji++;
                }
                if(0!=numm-zan+1)
                {
                    val[ji]=(numm-zan+1)*vall;
                    ji++;
                }
            }
            else
            {
                val[ji]=vall;
                ji++;
            }
        }
        v=sum/2;
        for(i=0;i<=v;i++)
        {
            dp[i]=0;
        }
        for(i=0;i<ji;i++)
        {
            for(f=v;f>=0;f--)
            {
                if(f<val[i])
                {
                    break;
                }
                if(dp[f-val[i]]+val[i]>dp[f])
                {
                    dp[f]=dp[f-val[i]]+val[i];
                }
            }
        }
        printf("%d %d\n",sum-dp[v],dp[v]);
    }
    return 0;
}
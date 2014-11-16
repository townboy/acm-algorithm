******************************
    Author : townboy
    Submit time : 2012-07-03 19:06:59
    Judge Status : Accepted
    HDOJ Runid : 6123361
    Problem id : 3732
    Exe.time : 156MS
    Exe.memory : 236K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int sc,dp[11000],n,jilu[15][15];

void chu()
{
    memset(jilu,0,sizeof(jilu));
    memset(dp,0,sizeof(dp));    
}

void mul(int w,int c)
{
    int i;
    for(i=sc;i>=c;i--)
    {
        dp[i]=dp[i]>dp[i-c]+w?dp[i]:dp[i-c]+w;
    }
}

int main()
{
    char ch[1000];
    int c,w,i,k,f;
    while(scanf("%d%d",&n,&sc)!=EOF)
    {
        chu();
        for(i=0;i<n;i++)
        {
            scanf("%s%d%d",ch,&w,&c);
            jilu[w][c]++;    
        }
        for(i=0;i<=10;i++)
        {
            for(f=0;f<=10;f++)
            {
                k=1;
                while(jilu[i][f] > k)
                {
                    jilu[i][f]-=k;
                    mul(k*i,k*f);
                    k*=2;        
                }
                mul(jilu[i][f]*i,jilu[i][f]*f);
            }
        }
        printf("%d\n",dp[sc]);
    }
    return 0;
}
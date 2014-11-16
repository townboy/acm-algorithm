******************************
    Author : townboy
    Submit time : 2012-07-01 16:29:01
    Judge Status : Accepted
    HDOJ Runid : 6113773
    Problem id : 2191
    Exe.time : 0MS
    Exe.memory : 388K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int dp[50000],n;

void mul(int c,int w)
{
    int i;
    for(i=n;i>=0;i--)
    {
        if(i-c  < 0)
        {
            return ;
        }    
        if(dp[i] < dp[i-c]+w)
        {
            dp[i]=dp[i-c]+w;
        }
    }
}

void chu()
{
    memset(dp,0,sizeof(dp));
}

int main()
{
    int num,m,p,h,c,k,i,f;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&n,&m);
        chu();
        for(f=0;f<m;f++)
        {
            scanf("%d%d%d",&p,&h,&c);
            k=1;
            while(c-k > 0)
            {
                c-=k;
                mul(p*k,h*k);
                k*=2;
            }
            mul(p*c,h*c);
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}

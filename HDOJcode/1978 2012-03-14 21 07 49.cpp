******************************
    Author : townboy
    Submit time : 2012-03-14 21:07:49
    Judge Status : Accepted
    HDOJ Runid : 5548639
    Problem id : 1978
    Exe.time : 203MS
    Exe.memory : 316K
    https://github.com/townboy
******************************


#include<stdio.h>

int m,n,val[120][120],dp[120][120];

void chu(int m,int n)
{
    int i,f;
    for(i=1;i<=m;i++)
    {
        for(f=1;f<=n;f++)
        {
            dp[i][f]=-1;
        }
    }
    dp[m][n]=1;
}

int dfs(int x,int y)
{
    int sum,i,f;
    if(-1==dp[x][y])
    {
        sum=0;
        for(i=x;i<=x+val[x][y];i++)
        {
            for(f=y;(i+f)-(x+y)<=val[x][y];f++)
            {
                if(x==i&&f==y)
                {
                    continue;
                }
                if(i>m||f>n)
                {
                    continue;
                }
                sum=sum+dfs(i,f);
            }
        }
        dp[x][y]=sum%10000;
    }
    return dp[x][y];
}

int main()
{
    int num,i,f,g,sum;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&m,&n);
        chu(m,n);
        for(f=1;f<=m;f++)
        {
            for(g=1;g<=n;g++)
            {
                scanf("%d",&val[f][g]);
            }
        }
        sum=dfs(1,1);
        printf("%d\n",sum);
    }
    return 0;
}

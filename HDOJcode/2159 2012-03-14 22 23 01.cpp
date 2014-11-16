******************************
    Author : townboy
    Submit time : 2012-03-14 22:23:01
    Judge Status : Accepted
    HDOJ Runid : 5549593
    Problem id : 2159
    Exe.time : 78MS
    Exe.memory : 312K
    https://github.com/townboy
******************************


#include<stdio.h>

int maxx(int a,int b)
{
    return a>b?a:b;
}

int dp[200][200];

int main()
{
    int max,j,r,k,s,i,f,g,jin[120],ren[120];
    while(scanf("%d%d%d%d",&j,&r,&k,&s)!=EOF)
    {
        for(i=0;i<k;i++)
        {
            scanf("%d%d",&jin[i],&ren[i]);
        }
        for(i=0;i<=j+25;i++)
        {
            for(f=0;f<=s;f++)
            {
                dp[i][f]=-10000000;
            }
        }
        dp[0][0]=r;
        for(i=0;i<k;i++)
        {
            for(f=0;f<=j+22;f++)
            {
                for(g=0;g<=s;g++)
                {
                    if(g-1>=0&&f-jin[i]>=0)
                    {
                        dp[f][g]=maxx(dp[f][g],dp[f-jin[i]][g-1]-ren[i]);
                    }
                }
            }
        }
        max=-10000000;
        for(i=j;i<=j+21;i++)
        {
            for(f=0;f<=s;f++)
            {
                if(dp[i][f]>max)
                {
                    max=dp[i][f];
                }
            }
        }
        if(max<0)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",max);
        }
    }
    return 0;
}
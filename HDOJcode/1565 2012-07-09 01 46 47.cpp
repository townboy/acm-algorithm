******************************
    Author : townboy
    Submit time : 2012-07-09 01:46:47
    Judge Status : Accepted
    HDOJ Runid : 6157067
    Problem id : 1565
    Exe.time : 875MS
    Exe.memory : 8888K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int dp[2][1100000];
int map[25][25],law[30000];

void chu()
{
    memset(dp,0,sizeof(dp));
}

int laww(int x)
{
    int flag=0;
    while(0 != x)
    {
        if(1 == (1&x))
        {
            if(1 == flag)
            {
                return 0;
            }
            else
            {
                flag=1;    
            }
        }
        else
        {
            flag=0;
        }
        x>>=1;
    }
    return 1;
}

int summ(int i,int state)
{
    int sum=0,ji=0;
    while(0 != state)
    {
        sum+=(1&state)*map[i][ji++];
        state>>=1;    
    }    
    return sum;
}

int check(int x,int y)
{
    if(0 == (x&y))
    {
        return 1;
    }
    return 0;
}

int main()
{
    int zen;
    int i,f,g,ji,n,right,maxx;
    ji=0;
    for(i=0;i<1024*1024;i++)
    {
        if(1 == laww(i))
        {
            law[ji++]=i;
        }
    }
    while(scanf("%d",&n)!=EOF)
    {
        chu();
        for(i=1;i<=n;i++)
        {
            for(f=0;f<n;f++)
            {
                scanf("%d",&map[i][f]);
            }
        }
        right=1<<n;
        for(i=1;i<=n;i++)
        {
            for(f=0;law[f]<right;f++)
            {
                zen=summ(i,law[f]);
                for(g=0;law[g]<right;g++)
                {    
                    if(0 == check(law[f],law[g]))
                    {
                        continue;
                    }
                    if(dp[(i&1)][law[f]] < dp[((i-1)&1)][law[g]]+zen)
                    {
                        dp[(i&1)][law[f]] = dp[((i-1)&1)][law[g]]+zen;    
                    }
                }
            }
        }
        maxx=0;
        for(i=0;i<right;i++)
        {
            if(dp[(n&1)][i] > maxx)
            {
                maxx=dp[(n&1)][i];
            }
        }
        printf("%d\n",maxx);
    }
    return 0;
}
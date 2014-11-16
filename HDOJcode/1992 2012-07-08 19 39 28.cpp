******************************
    Author : townboy
    Submit time : 2012-07-08 19:39:28
    Judge Status : Accepted
    HDOJ Runid : 6155585
    Problem id : 1992
    Exe.time : 0MS
    Exe.memory : 364K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

__int64 dp[1100][20];

void chu()
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
}

int check(int pre,int next)
{
    int i,zan[4],last;
    if(0 != (next&pre))
    {
        return 0;
    }
    next|=pre;
    for(i=0;i<4;i++)
    {
        zan[i]=next&1;
        next>>=1;
    }
    last=0;
    for(i=0;i<4;i++)
    {
        if(1 ==  zan[i])
        {
            if(0 != (last&1))
            {
                return 0;
            }
            last=0;
        }
        else
        {
            last++;
        }
    }
    if(1 == (1&last))
    {
        return 0;
    }
    return 1;
}

int main()
{
    int i,f,g,m,num;
    chu();
    for(i=0;i<1000;i++)
    {
        for(f=0;f<16;f++)
        {
            if(0 == dp[i][f])
            {
                continue;
            }
            for(g=0;g<16;g++)
            {
                if(0 == check(f,g))
                {
                    continue;
                }
                dp[i+1][g]+=dp[i][f];
            }
        }
    }    
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&m);
        printf("%d %I64d\n",i+1,dp[m][0]);        
    }
    return 0;
}
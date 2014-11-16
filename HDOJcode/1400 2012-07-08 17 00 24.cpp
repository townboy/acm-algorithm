******************************
    Author : townboy
    Submit time : 2012-07-08 17:00:24
    Judge Status : Accepted
    HDOJ Runid : 6154678
    Problem id : 1400
    Exe.time : 6406MS
    Exe.memory : 1364K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

__int64 dp[15][10000];
int n,m;

void chu()
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
}

int check(int pre,int next)
{
    int qian[15],hou[15];
    int ji=0,last,i;
    memset(qian,0,sizeof(qian));
    memset(hou,0,sizeof(hou));
    while(0 != next)
    {
        hou[ji++]=(next&1);
        next>>=1;
    }
    ji=0;
    while(0 != pre)
    {
        qian[ji++]=(pre&1);
        pre>>=1;
    }
    last=0;
    for(i=0;i<n;i++)
    {
        if(1 == qian[i])
        {
            if(1 == hou[i])
            {
                return 0;
            }
            if(1 == (last&1))
            {
                return 0;
            }    
            last=0;
        }    
        else
        {
            if(1 == hou[i])
            {
                if(1 == (last&1))
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
    }        
    if(1 == (last&1))
    {
        return 0;
    }
    return 1;
}

int main()
{
    int i,f,g;
    while(scanf("%d%d",&m,&n),0 != n+m)
    {
        chu();    
        for(i=0;i<m;i++)
        {
            for(f=0;f<(1<<n);f++)
            {
                if(0 == dp[i][f])
                {    
                    continue;
                }
                for(g=0;g<(1<<n);g++)
                {
                    if(1 == check(f,g))
                    {
                        dp[i+1][g]+=dp[i][f];
                    }
                }    
            }
        }
        printf("%I64d\n",dp[m][0]);        
    }
    return 0;
}
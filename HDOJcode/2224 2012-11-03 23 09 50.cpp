******************************
    Author : townboy
    Submit time : 2012-11-03 23:09:50
    Judge Status : Accepted
    HDOJ Runid : 7077869
    Problem id : 2224
    Exe.time : 31MS
    Exe.memory : 1124K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<queue>
#include<iostream>
#include<math.h>
#define INF 10000000

using namespace std;

int loc[210][2],n,hash[210][210];
double dp[210][210];
double map[210][210];

void chu()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=n;f++)
        {
            dp[i][f]=INF;
        }
    }
    memset(hash,0,sizeof(hash)); 
}

void spfa()
{
    int i,minn,maxx;
    queue<int>que;
    
    que.push(1);
    que.push(1);
    dp[1][1]=0;
    
    while(!que.empty())
    {
        minn=que.front();
        que.pop();
        maxx=que.front();
        que.pop();
        hash[minn][maxx]=0; 
        
        if(minn >= maxx-1)
        {
            if(maxx == n)
            {
                if(dp[n][n] > dp[n-1][n]+map[n-1][n])
                {    
                    dp[n][n]=dp[n-1][n]+map[n-1][n];
                }
                continue;
            }
            for(i=maxx+1;i<=n;i++)
            {
                if(dp[maxx][i] > dp[minn][maxx]+map[minn][i])
                {
                    dp[maxx][i]=dp[minn][maxx]+map[minn][i];
                    if(0 == hash[maxx][i])
                    {
                        hash[maxx][i]=1;
                        que.push(maxx);
                        que.push(i);    
                    }
                }
            }                
        }
        else
        {
            if(dp[minn+1][maxx] > dp[minn][maxx]+map[minn][minn+1])
            {
                dp[minn+1][maxx]=dp[minn][maxx]+map[minn][minn+1];
                if(0 == hash[minn+1][maxx])
                {
                    hash[minn+1][maxx]=1;
                    que.push(minn+1);
                    que.push(maxx);
                }
            }    
        }
    }
}

int main()
{
    int sum;
    int i,f,g;
    while(scanf("%d",&n)!=EOF)
    {
        chu();
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&loc[i][0],&loc[i][1]);    
            for(f=1;f<n;f++)
            {
                sum=0;
                for(g=0;g<2;g++)
                {
                    sum+=(loc[i][g]-loc[f][g])*(loc[i][g]-loc[f][g]);
                }
                map[f][i]=sqrt((double)sum);
            }
        }
        spfa();
        printf("%.2lf\n",dp[n][n]);
    }
    return 0;
}
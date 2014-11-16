******************************
    Author : townboy
    Submit time : 2013-03-22 21:51:18
    Judge Status : Accepted
    HDOJ Runid : 7844650
    Problem id : 4512
    Exe.time : 453MS
    Exe.memory : 884K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<queue>

using namespace std;

int n;
int dp[210][210],hash[210][210];
int que[210];
queue<int>q;

void init()
{
    memset(hash,0,sizeof(hash));
    memset(dp,-1,sizeof(dp));
}    

void spfa()
{
    int i,f;
    int a,b,tem,val;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        b=q.front();
        q.pop();
        hash[a][b]=0;
        tem=que[a];
        val=dp[a][b];
        for(i=a+1;i<b;i++)
            for(f=b-1;f>=i;f--)
            {
                if(que[i] != que[f])
                    continue;
                if(que[i] <= tem)
                    continue;
                if(i == f)
                {
                    if(val+1 > dp[i][f])
                    {
                        dp[i][f]=val+1;
                        if(0 == hash[i][f])
                        {
                            hash[i][f]=1;
                            q.push(i);
                            q.push(f);
                        }
                    }
                }
                else
                {
                    if(val+2 > dp[i][f])
                    {
                        dp[i][f]=val+2;
                        if(0 == hash[i][f])
                        {
                            hash[i][f]=1;
                            q.push(i);
                            q.push(f);
                        }                    
                    }
                }
            }
    }
}

void debug()
{
    int i,f;
    for(i=0;i<n;i++)
    {
        for(f=0;f<n;f++)
        {
            printf("%d ",dp[i][f]);
        }
        printf("\n");
    }
}

int main()
{
    int ans;
    int g,i,cas,f;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d",&n);
        for(f=0;f<n;f++)
            scanf("%d",que+f);
        init();
        for(f=0;f<n;f++)
            for(g=f;g<n;g++)
                if(que[f] == que[g])
                {
                    dp[f][g]=(g==f?1:2);
                    q.push(f);
                    q.push(g);
                    hash[f][g]=1;
                }
        spfa();
        ans=0;
        for(f=0;f<n;f++)
            for(g=0;g<n;g++)
                ans=max(ans,dp[f][g]);
        printf("%d\n",ans);
    }
    return 0;
}
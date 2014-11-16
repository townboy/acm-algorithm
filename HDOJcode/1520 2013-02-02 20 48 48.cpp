******************************
    Author : townboy
    Submit time : 2013-02-02 20:48:48
    Judge Status : Accepted
    HDOJ Runid : 7585319
    Problem id : 1520
    Exe.time : 78MS
    Exe.memory : 528K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

int head;
int rating[6100];
int n,hash[6100];
int dp[6100][2];

vector<int>map[6100];

void chu()
{
    int i;
    for(i=1;i<=n;i++)
        map[i].clear();
    memset(hash,0,sizeof(hash));
    memset(dp,0,sizeof(dp));
}

void choose()
{
    int i;
    for(i=1;i<=n;i++)
        if(0 == hash[i])
        {
            head=i;
            return ;
        }
}

void dfs(int rt)
{
    int son,none;
    int i,size=map[rt].size();
    for(i=0;i<size;i++)
    {
        son=map[rt][i];
        dfs(son);
        dp[rt][1]+=dp[son][0];
        dp[rt][0]+=max(dp[son][0],dp[son][1]);
    }
    dp[rt][1]+=rating[rt];
}

int main()
{
    int l,k,i;
    while(scanf("%d",&n)!=EOF)
    {
        chu();
        for(i=1;i<=n;i++)
            scanf("%d",&rating[i]);
        while(scanf("%d%d",&l,&k),l+k)
        {
            map[k].push_back(l);
            hash[l]=1;
        }    
        choose();
        dfs(head);
        printf("%d\n",max(dp[head][0],dp[head][1]));
    }
    return 0; 
} 
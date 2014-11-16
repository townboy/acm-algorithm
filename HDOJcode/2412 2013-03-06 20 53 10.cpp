******************************
    Author : townboy
    Submit time : 2013-03-06 20:53:10
    Judge Status : Accepted
    HDOJ Runid : 7702786
    Problem id : 2412
    Exe.time : 0MS
    Exe.memory : 312K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

vector<int>tree[210];
map<string,int>mp;
int n,ji,dp[210][2],mul[210][2];

int id(string tem)
{
    if(0 != mp[tem])
        return mp[tem];
    ji++;
    mp[tem]=ji;
    return ji;
}

void chu()
{
    int i;
    mp.clear();
    for(i=1;i<=n;i++)
        tree[i].clear();
    memset(dp,0,sizeof(dp));
    memset(mul,0,sizeof(mul));
    ji=0;
}

void dfs(int rt)
{
    int son,size=tree[rt].size(),i;
    for(i=0;i<size;i++)
    {
        son=tree[rt][i];
        dfs(son);
        dp[rt][1]+=dp[son][0];
        if(1 == mul[son][0])
            mul[rt][1]=1;
        
        if(dp[son][0] > dp[son][1])
        {
            dp[rt][0]+=dp[son][0];
            if(1 == mul[son][0])
                mul[rt][0]=1;
        }
        else if(dp[son][0] < dp[son][1])
        {
            dp[rt][0]+=dp[son][1];
            if(1 == mul[son][1])
                mul[rt][0]=1;
        }
        else
        {
            dp[rt][0]+=dp[son][1];
            mul[rt][0]=1;
        }
    }
    dp[rt][1]+=1;
}

int main()
{
    int i;
    string boss,tem;
    while(scanf("%d",&n),n)
    {
        chu();
        cin>>boss;
        id(boss);
        for(i=0;i<n-1;i++)
        {    
            cin>>tem>>boss;
            tree[id(boss)].push_back(id(tem));                    
        }
        dfs(1);
        if(dp[1][0] == dp[1][1])
        {
            printf("%d No\n",dp[1][0]);
        }
        else if(dp[1][0] > dp[1][1])
        {
            printf("%d ",dp[1][0]);
            if(1 == mul[1][0])
                printf("No\n");
            else
                printf("Yes\n");
        }
        else
        {
            printf("%d ",dp[1][1]);
            if(1 == mul[1][1])
                printf("No\n");
            else
                printf("Yes\n");
        }
    }
    return 0;
}
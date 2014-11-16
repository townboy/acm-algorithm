******************************
    Author : townboy
    Submit time : 2013-03-12 23:55:20
    Judge Status : Accepted
    HDOJ Runid : 7750000
    Problem id : 4003
    Exe.time : 562MS
    Exe.memory : 1332K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<vector>
#include<iostream>
#include<memory.h>
#define INF 0x3f3f3f3f

using namespace std;

int dp[10010][12];
int n,s,k,hash[10010];
struct node 
{
    int u;
    int v;
    int len;
};
struct node ru;

vector<node>tree[10010];

void init()
{
    int i;
    for(i=1;i<=n;i++)
        tree[i].clear();
    memset(hash,0,sizeof(hash));
    memset(dp,0,sizeof(dp));
}

void add(int u,int v,int len)
{
    ru.len=len;
    ru.v=v;
    tree[u].push_back(ru);
    ru.v=u;
    tree[v].push_back(ru);
}

void dfs(int rt)
{
    int f,tem[12],g,len,val;
    int son,size=tree[rt].size(),i;
    
    for(i=1;i<=k;i++)
        tem[i]=INF;
    tem[0]=0;
    
    for(i=0;i<size;i++)
    {
        son=tree[rt][i].v;
        len=tree[rt][i].len;
        if(1 == hash[son])
            continue;
        hash[son]=1;
        dfs(son);
        for(f=0;f<=k;f++)
            dp[rt][f]=INF;
        for(f=0;f<=k;f++)
            for(g=0;g<=f;g++)
            {
                val=tem[g]+dp[son][f-g]+(f-g)*len;
                if(0 == f-g)
                    val+=len*2;
                dp[rt][f]=min(dp[rt][f],val);
            }
        for(f=0;f<=k;f++)
            tem[f]=dp[rt][f];
    }
}

int main()
{
    int ans,i,u,v,len;
    while(scanf("%d%d%d",&n,&s,&k)!=EOF)
    {
        init();
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&u,&v,&len);
            add(u,v,len);
        }
        
        hash[s]=1;
        dfs(s);
        ans=INF;
        for(i=1;i<=k;i++)
            ans=min(ans,dp[s][i]);
        printf("%d\n",ans);
    }    
    return 0;
}
******************************
    Author : townboy
    Submit time : 2013-03-08 01:00:31
    Judge Status : Accepted
    HDOJ Runid : 7710827
    Problem id : 4303
    Exe.time : 1031MS
    Exe.memory : 27592K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<vector>
#include<memory.h>
#include<queue>

using namespace std;

struct node 
{
    int v;
    int col;
};
struct node tem;

struct node2
{
    __int64 val;
    int col;
    __int64 path;
    friend bool operator < (node2 a,node2 b)
    {
        return a.col > b.col;
    }    
};
struct node2 tem2;

__int64 ans;
int val[310000],hash[310000],n;
vector<node>tree[310000];
__int64 dp[310000],path[310000];

void chu()
{
    int i;
    for(i=1;i<=n;i++)
        tree[i].clear();
    memset(hash,0,sizeof(hash));
    memset(dp,0,sizeof(dp));
    ans=0;
    memset(path,0,sizeof(path));
}

void add(int u,int v,int col)
{
    tem.col=col;
    tem.v=v;
    tree[u].push_back(tem);
    tem.v=u;    
    tree[v].push_back(tem);
}

void dfs(int rt,int rtcol,int father)
{
    priority_queue<node2>que;
    int son,size=tree[rt].size(),i,col;
    __int64 lastcol=0,sum=0,sumpath=0,left=0,leftpath=0;
        
    path[rt]++;
    dp[rt]+=val[rt];
    
    for(i=0;i<size;i++)
    {
        son=tree[rt][i].v;
        col=tree[rt][i].col;
        if(1 == hash[son])
            continue;
        hash[son]=1;
        dfs(son,col,rt);

        ans+=dp[son]+path[son]*val[rt];
        if(col != rtcol)
        {
            dp[rt]+=dp[son]+path[son]*val[rt];
            path[rt]+=path[son];
        }
        
        tem2.path=path[son];
        tem2.col=col;
        tem2.val=dp[son];
        que.push(tem2);
    }
    while(!que.empty())
    {
        tem2=que.top();
        que.pop();
        if(tem2.col != lastcol)
        {
            sum+=left;
            sumpath+=leftpath;
            left=tem2.val;
            leftpath=tem2.path;
            lastcol=tem2.col;
            ans+=sum*leftpath+left*sumpath+val[rt]*leftpath*sumpath;
        }
        else
        {
            ans+=sum*tem2.path+tem2.val*sumpath+val[rt]*sumpath*tem2.path;
            left+=tem2.val;
            leftpath+=tem2.path;
        }
    }
}

int main()
{
    int u,v,col;
    int i;
    while(scanf("%d",&n)!=EOF)
    {
        chu();
        for(i=1;i<=n;i++)
            scanf("%d",val+i);
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&u,&v,&col);
            add(u,v,col);
        }
        hash[1]=1;
        dfs(1,0,0);
        printf("%I64d\n",ans);
    }
    return 0;
}
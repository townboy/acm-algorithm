******************************
    Author : townboy
    Submit time : 2012-06-18 21:04:29
    Judge Status : Accepted
    HDOJ Runid : 6078266
    Problem id : 1269
    Exe.time : 31MS
    Exe.memory : 1388K
    https://github.com/townboy
******************************


#include<stdlib.h>
#include<stdio.h>
#include<stack>
#include<vector>
using namespace std;

int low[11000],dfn[11000],instack[11000];
int n,ans,Dindex;
stack<int>q;
vector<int> adj[10010];

void tarjan(int x)
{
    int i,b;
    dfn[x]=low[x]=++Dindex;
    q.push(x);
    instack[x]=1;
    for(b=0;b<adj[x].size();b++)
    {
        i=adj[x][b];
        if(0 == dfn[i])
        {
            tarjan(i);
            if(low[i] < low[x])
            {
                low[x]=low[i];
            }
        }
        else if(1 == instack[i] && dfn[i]<low[x])
        {
            low[x]=dfn[i];
        }    
    }
    if(low[x] == dfn[x])
    {
        ans++;
        while(1)
        {
            i=q.top();
            q.pop();
            instack[i]=0;
            if(i == x)
            {
                break;
            }
        }
    }
}

void slove()
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(0 == dfn[i])
        {
            tarjan(i);
        }
    }
}

void chu()
{
    int i;
    memset(instack,0,sizeof(instack));
    memset(dfn,0,sizeof(dfn));
    ans=Dindex=0;
    while(!q.empty())
    {
        q.pop();
    }
    for(i=1;i<=n;i++)
    {
        adj[i].clear();
    }
}


int main()
{
    int m,i,s,e;
    //freopen("D:\\in.txt","r",stdin);
    while(scanf("%d%d",&n,&m),!(0 == n && 0 == m))
    {
        chu();
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&s,&e);
            adj[s].push_back(e);
        }

        slove();
        if(1 == ans)
        {    
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}

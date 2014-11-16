******************************
    Author : townboy
    Submit time : 2013-04-27 11:26:43
    Judge Status : Accepted
    HDOJ Runid : 8183939
    Problem id : 1384
    Exe.time : 3484MS
    Exe.memory : 3216K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<queue>
#define maxn 50010
#define INF 0x7fffffff

using namespace std;

int dis[maxn],hash[maxn];

struct node 
{
    int v,len;
    node(){}
    node(int _v,int _len)
    {
        v=_v;
        len=_len;
    }
};

vector<node>G[maxn];

void init()
{
    int i;
    for(i=0;i<=50001;i++)
        G[i].clear();
    memset(dis,0x80,sizeof(dis));
    memset(hash,0,sizeof(hash));
}

void add(int u,int v,int len)
{
    G[u].push_back(node(v,len));
}

int spfa(int s,int t)
{
    int len,i,to,size,tem;
    queue<int>q;
    q.push(s);
    dis[s]=0;
    while(!q.empty())
    {
        tem=q.front();q.pop();
        hash[tem]=0;
        size=G[tem].size();
        for(i=0;i<size;i++)
        {
            to=G[tem][i].v;
            len=G[tem][i].len;
            if(dis[tem]+len > dis[to])
            {
                dis[to]=dis[tem]+len;
                if(1 == hash[to])    continue;
                hash[to]=1;
                q.push(to);
            }
        }
    }
    return dis[t];
}

int main()
{
    int maxx,minn;
    int i,ans;
    int a,b,c,n;
    while(scanf("%d",&n)!=EOF)
    {
        init();
        maxx=0;
        minn=INF;
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            a++;
            b++;
            add(a-1,b,c);
            minn=min(minn,a-1);
            maxx=max(maxx,b);
        }
        for(i=minn;i<maxx;i++)
        {
            add(i,i+1,0);
            add(i+1,i,-1);
        }
        ans=spfa(minn,maxx);
        printf("%d\n",ans);
    }
    return 0;
}
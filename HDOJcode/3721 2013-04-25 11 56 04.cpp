******************************
    Author : townboy
    Submit time : 2013-04-25 11:56:04
    Judge Status : Accepted
    HDOJ Runid : 8168941
    Problem id : 3721
    Exe.time : 5062MS
    Exe.memory : 476K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<vector>

#define maxn 2510
#define INF 0x7fffffff

using namespace std;

int n,del;
int edge[maxn][3];
int down[maxn][2],downid[maxn];
int up[maxn];
int sum;

struct node{
    int v,len; 
    node(){}
    node(int _v,int _len){
        v=_v;
        len=_len;
    }
};

vector<node>G[maxn];
int summax;

int check(int u,int v)
{
    if(u==edge[del][0] && v==edge[del][1])
        return 1;
    if(v==edge[del][0] && u==edge[del][1])
        return 1;
    return 0;
}

void dfs2(int rt,int fa)
{
    int tem;
    int i,size=G[rt].size(),son,len;
    for(i=0;i<size;i++)
    {
        son=G[rt][i].v;
        len=G[rt][i].len;
        if(son == fa)    continue;
        if(son == downid[rt])
            up[son]=len+max(up[rt],down[rt][1]);
        else
            up[son]=len+max(up[rt],down[rt][0]);
        dfs2(son,rt);
    }
    tem=max(down[rt][0],up[rt]);
    sum=min(sum,tem);
}

void dfs1(int rt,int fa)
{
    int maxx;
    int i,size=G[rt].size(),son,len;
    for(i=0;i<size;i++)
    {
        son=G[rt][i].v;
        len=G[rt][i].len;
        if(son == fa)    continue;
        dfs1(son,rt);
        maxx=down[son][0]+len;
        if(maxx > down[rt][0])
        {
            down[rt][1]=down[rt][0];
            down[rt][0]=maxx;
            downid[rt]=son;
        }
        else if(maxx > down[rt][1])
            down[rt][1]=maxx;
    }
    sum=max(sum,down[rt][0]+down[rt][1]);
}

int fun()
{
    int ans,tem;
    int u=edge[del][0],v=edge[del][1];
    memset(down,0,sizeof(down));
    memset(up,0,sizeof(up));
    sum=0;
    dfs1(u,v);
    dfs1(v,u);
    ans=sum;
    
    sum=INF;
    dfs2(u,v);
    tem=sum;
    sum=INF;
    dfs2(v,u);
    ans=max(ans,edge[del][2]+sum+tem);
    return ans;
}

int main()
{
    int ans;
    int i,cas,f,g;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d",&n);
        for(f=0;f<n;f++)
            G[f].clear();
        for(f=0;f<n-1;f++)
        {
            for(g=0;g<3;g++)
                scanf("%d",&edge[f][g]);
            G[edge[f][0]].push_back(node(edge[f][1],edge[f][2]));
            G[edge[f][1]].push_back(node(edge[f][0],edge[f][2]));    
        }
        ans=INF;
        for(f=0;f<n-1;f++)
        {
            del=f;
            ans=min(ans,fun());
        }
        printf("Case %d: %d\n",i+1,ans);
    }
    return 0;
}
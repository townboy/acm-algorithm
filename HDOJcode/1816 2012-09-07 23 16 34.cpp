******************************
    Author : townboy
    Submit time : 2012-09-07 23:16:34
    Judge Status : Accepted
    HDOJ Runid : 6719882
    Problem id : 1816
    Exe.time : 109MS
    Exe.memory : 464K
    https://github.com/townboy
******************************


#include<stack>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<iostream>
#define maxn 5000
#define maxe 2100000
#define W 0
#define R 1
#define B 2

using namespace std;

int scc,Dindex,n,size,m;                // ¶¥µãÐòºÅÊÇ 0 - n-1 
int belong[maxn],instack[maxn],dfn[maxn],low[maxn],first[maxn];
stack<int>q;
int opp[maxn],group,deg[maxn],col[maxn];

int mm,id[1500][2],nn;

struct xx 
{
    int u;
    int v;
};
struct xx door[2500];

struct node 
{
    int v;
    int next;
};
struct node edge[maxe];

void add(int u,int v)
{
    edge[size].v=v;
    edge[size].next=first[u];
    first[u]=size++;
}

void tarjan(int x)
{    
    int tem,i;
    dfn[x]=low[x]=++Dindex;
    instack[x]=1;
    q.push(x);
    
    tem=first[x];
    while(-1 != tem)
    {
        i=edge[tem].v;
        if(0 == dfn[i])
        {
            tarjan(i);
            low[x]=min(low[i],low[x]);
        }
        else if(1==instack[i] && dfn[i]<low[x])
        {
            low[x]=dfn[i];
        }
        tem=edge[tem].next;
    }
    if(low[x] == dfn[x])
    {
        scc++;
        while(1)
        {
            i=q.top();
            q.pop();
            instack[i]=0;
            belong[i]=scc;
            if(i == x)
            {
                break;
            }
        }
    }
}

void chu()
{
    Dindex=scc=size=0;
    memset(instack,0,sizeof(instack));
    memset(dfn,0,sizeof(dfn));
    memset(first,-1,sizeof(first));
    while(!q.empty())
    {
        q.pop();
    }
}

void slove()
{
    int i;
    for(i=0;i<n;i++)
    {
        if(0 == dfn[i])
        {
            tarjan(i);
        }
    }
}

int check()
{
    int i;
    for(i=0;i<group;i++)
    {
        opp[belong[i<<1]]=belong[i<<1|1];
        opp[belong[i<<1|1]]=belong[i<<1];
        if(belong[i<<1] == belong[i<<1|1])
        {
            return 0;
        }    
    }
    return 1;
}

void build(int mid)
{
    int i;
    for(i=0;i<nn;i++)
    {
        add(id[i][0]<<1|1,id[i][1]<<1);
        add(id[i][1]<<1|1,id[i][0]<<1);
    }
    for(i=0;i<=mid;i++)
    {
        add(door[i].u<<1,door[i].v<<1|1);
        add(door[i].v<<1,door[i].u<<1|1);    
    }
}

int bs()
{
    int l=0,r=mm,mid;
    n=4*nn;
    group=2*nn;
    while(l != r-1)
    {
        mid=(l+r)>>1;
        chu();
        build(mid);
        slove();
        if(1 == check())
        {
            l=mid;        
        }
        else
        {
            r=mid;
        }
    }
    return l;
}

int main()
{
    int i,u,v;
    while(scanf("%d%d",&nn,&mm),nn+mm)
    {
        for(i=0;i<nn;i++)
        {
            scanf("%d%d",&id[i][0],&id[i][1]);
        }
        for(i=0;i<mm;i++)
        {
            scanf("%d%d",&door[i].u,&door[i].v);        
        }
        printf("%d\n",bs()+1);
    }
    return 0;
}
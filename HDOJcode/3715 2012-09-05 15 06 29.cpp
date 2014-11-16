******************************
    Author : townboy
    Submit time : 2012-09-05 15:06:29
    Judge Status : Accepted
    HDOJ Runid : 6706531
    Problem id : 3715
    Exe.time : 343MS
    Exe.memory : 692K
    https://github.com/townboy
******************************


#include<stack>
#include<queue>
#include<stdio.h>
#include<memory.h>
#include<iostream>
#define maxn 3000
#define maxe 2100000
#define W 0
#define R 1
#define B 2

using namespace std;

int scc,Dindex,n,size,m;                // ¶¥µãÐòºÅÊÇ 0 - n-1 
int belong[maxn],instack[maxn],dfn[maxn],low[maxn],first[maxn];
stack<int>q;
int opp[maxn],group,deg[maxn],col[maxn];

int a[11000],b[11000],c[11000];

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
    for(i=0;i<=mid;i++)
    {
        if(0 == c[i])
        {
            add(a[i]<<1,(b[i]<<1)^1);
            add(b[i]<<1,(a[i]<<1)^1);
        }
        if(1 == c[i])
        {
            add(a[i]<<1,b[i]<<1);
            add(a[i]<<1|1,b[i]<<1|1);
            add(b[i]<<1,a[i]<<1);
            add(b[i]<<1|1,a[i]<<1|1);        
        }
        if(2 == c[i])
        {
            add((a[i]<<1)^1,(b[i]<<1));
            add((b[i]<<1)^1,(a[i]<<1));
        }    
    }
}

int bs()
{
    int l=0,r=m,mid;
    while(l != r-1)
    {
        mid=(l+r)>>1;
        chu();
        build(mid);
        n=2*group;
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
    return l+1;
}

int main()
{
    int f,i,num;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&group,&m);
        for(f=0;f<m;f++)
        {
            scanf("%d%d%d",&a[f],&b[f],&c[f]);
        }
        
        printf("%d\n",bs());
    }
    return 0;
}
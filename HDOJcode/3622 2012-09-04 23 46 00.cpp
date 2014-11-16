******************************
    Author : townboy
    Submit time : 2012-09-04 23:46:00
    Judge Status : Accepted
    HDOJ Runid : 6704528
    Problem id : 3622
    Exe.time : 375MS
    Exe.memory : 652K
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
#define eps 1e-6

using namespace std;

int scc,Dindex,n,size,m;                // ¶¥µãÐòºÅÊÇ 0 - n-1 
int belong[maxn],instack[maxn],dfn[maxn],low[maxn],first[maxn];
stack<int>q;
int opp[maxn],group,deg[maxn],col[maxn];

struct xx 
{
    int x[2];
    int y[2];
};
struct xx mat[110];

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

void build(double len)
{
    int i,f,g,h;
    chu();
    n=2*group;
    for(i=0;i<group;i++)
    {
        for(f=i+1;f<group;f++)
        {
            for(g=0;g<2;g++)
            {
                for(h=0;h<2;h++)
                {
                    if(4*len*len >= (mat[i].x[g]-mat[f].x[h])*(mat[i].x[g]-mat[f].x[h])+(mat[i].y[g]-mat[f].y[h])*(mat[i].y[g]-mat[f].y[h]))
                    {
                        add(2*i+g,(2*f+h)^1);
                        add(2*f+h,(2*i+g)^1);                    
                    }                
                }
            }    
        }
    }
}

double bs()
{
    double l=0,r=100000,mid;
    while(r-l > eps)
    {
        mid=(l+r)/2;
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
    return mid;
}

int main()
{
    int i;
    while(scanf("%d",&group)!=EOF)
    {
        for(i=0;i<group;i++)
        {
            scanf("%d%d%d%d",&mat[i].x[0],&mat[i].y[0],&mat[i].x[1],&mat[i].y[1]);            
        }
        printf("%.2lf\n",bs());    
    }
    return 0;
}
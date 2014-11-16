******************************
    Author : townboy
    Submit time : 2012-09-08 09:53:32
    Judge Status : Accepted
    HDOJ Runid : 6720600
    Problem id : 4115
    Exe.time : 46MS
    Exe.memory : 712K
    https://github.com/townboy
******************************


#include<stack>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<iostream>
#define maxn 21000
#define maxe 2100000
#define W 0
#define R 1
#define B 2

using namespace std;

int scc,Dindex,n,size,m;                // ¶¥µãÐòºÅÊÇ 0 - n-1 
int belong[maxn],instack[maxn],dfn[maxn],low[maxn],first[maxn];
stack<int>q;
int opp[maxn],group,deg[maxn],col[maxn];

int mm,id[11000][2],nn;

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

void debug()
{
    int i;
    for(i=0;i<nn;i++)
    {
        printf(" %d %d\n",id[i][0],id[i][1]);
    }
    printf("\n");
}

int main()
{
    int i,a,b,k,cas,num,f,g;
    scanf("%d",&num);
    for(cas=1;cas<=num;cas++)
    {
        scanf("%d%d",&nn,&mm);    
        chu();
        group=nn;
        n=2*group;
        for(i=0;i<nn;i++)
        {
            scanf("%d",&k);
            id[i][0]=k;
            if(1 == k)
            {
                id[i][1]=2;
            }
            if(2 == k)
            {
                id[i][1]=3;
            }
            if(3 == k)
            {
                id[i][1]=1;
            }
        }
        for(i=1;i<=mm;i++)
        {
            scanf("%d%d%d",&a,&b,&k);
            a--;
            b--;
            for(f=0;f<2;f++)
            {
                for(g=0;g<2;g++)
                {
                    if(1 == k)
                    {
                        if(id[a][f] == id[b][g])
                        {
                            add((a<<1)+f,((b<<1)+g)^1);
                            add((b<<1)+g,((a<<1)+f)^1);
                        }
                    }
                    else
                    {
                        if(id[a][f] != id[b][g])
                        {
                            add((a<<1)+f,((b<<1)+g)^1);
                            add((b<<1)+g,((a<<1)+f)^1);
                        }    
                    }                
                }
            }
        }
        slove();
        if(1 == check())
        {
            printf("Case #%d: yes\n",cas);
        }
        else
        {
            printf("Case #%d: no\n",cas);
        }
    }
    return 0;
}
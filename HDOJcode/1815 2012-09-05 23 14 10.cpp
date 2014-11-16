******************************
    Author : townboy
    Submit time : 2012-09-05 23:14:10
    Judge Status : Accepted
    HDOJ Runid : 6709895
    Problem id : 1815
    Exe.time : 62MS
    Exe.memory : 792K
    https://github.com/townboy
******************************


#include<stack>
#include<queue>
#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<math.h>
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

int a,b,sx[2],sy[2],x[510],y[510],hate[1100][2],like[1100][2],dis;

struct xx 
{
    int u;
    int v;
};
struct xx mat[maxe];

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

void build(int len)
{
    int sum,i,f,g,h;
    for(i=0;i<group;i++)
    {
        for(f=i+1;f<group;f++)
        {
            for(g=0;g<2;g++)
            {
                for(h=0;h<2;h++)
                {
                    sum=abs(x[i]-sx[g])+abs(y[i]-sy[g])+abs(x[f]-sx[h])+abs(y[f]-sy[h]);
                    if(g != h)
                    {
                        sum+=dis;
                    }
                    if(len < sum)
                    {
                        add(2*i+g,(2*f+h)^1);                
                        add(2*f+h,(2*i+g)^1);
                    }
                }
            }
        }
    }
}

void limit()
{
    int i;
    for(i=0;i<a;i++)
    {
        add(hate[i][0]<<1,hate[i][1]<<1|1);
        add(hate[i][0]<<1|1,hate[i][1]<<1);
        add(hate[i][1]<<1,hate[i][0]<<1|1);
        add(hate[i][1]<<1|1,hate[i][0]<<1);    
    }
    for(i=0;i<b;i++)
    {
        add(like[i][0]<<1,like[i][1]<<1);
        add(like[i][0]<<1|1,like[i][1]<<1|1);
        add(like[i][1]<<1,like[i][0]<<1);
        add(like[i][1]<<1|1,like[i][0]<<1|1);    
    }
}

int bs()
{
    int i,l=-1,r=10100000,mid;
    while(l != r-1)
    {
        mid=(l+r)>>1;
        chu();
        build(mid);
        limit();
        slove();
        if(1 == check())
        {
            r=mid;
        }
        else
        {
            l=mid;
        }
    }
    return r;
}

int main()
{
    int i;
    while(scanf("%d%d%d",&group,&a,&b)!=EOF)
    {
        scanf("%d%d%d%d",&sx[0],&sy[0],&sx[1],&sy[1]);
        dis=abs(sx[1]-sx[0])+abs(sy[1]-sy[0]);
        
        chu();
        
        for(i=0;i<group;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
        }
        
        for(i=0;i<a;i++)
        {
            scanf("%d%d",&hate[i][0],&hate[i][1]);
            hate[i][0]--;
            hate[i][1]--;
        }
        for(i=0;i<b;i++)
        {
            scanf("%d%d",&like[i][0],&like[i][1]);
            like[i][0]--;
            like[i][1]--;
        }

        limit();        
        n=group*2;
        slove();
        if(0 == check())
        {
            printf("-1\n");
            continue;
        }
        printf("%d\n",bs());
    }    
    return 0;
}
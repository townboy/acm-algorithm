******************************
    Author : townboy
    Submit time : 2012-08-24 21:22:55
    Judge Status : Accepted
    HDOJ Runid : 6651035
    Problem id : 3062
    Exe.time : 281MS
    Exe.memory : 888K
    https://github.com/townboy
******************************


#include<stack>
#include<stdio.h>
#include<memory.h>
#include<iostream>
#define maxn 3000
#define maxe 2100000

using namespace std;

int ans,Dindex,n,size;                // ¶¥µãÐòºÅÊÇ 0 - n-1 
int belong[maxn],instack[maxn],dfn[maxn],low[maxn],first[maxn];
stack<int>q;

int nn,m;

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
        ans++;
        while(1)
        {
            i=q.top();
            q.pop();
            instack[i]=0;
            belong[i]=ans;
            if(i == x)
            {
                break;
            }
        }
    }
}

void chu()
{
    Dindex=ans=size=0;
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

int main()
{
    int i,a1,a2,c1,c2;
    while(scanf("%d%d",&nn,&m)!=EOF)
    {
        chu();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&a1,&a2,&c1,&c2);
            add(a1*2+c1,(a2*2+c2)^1);
            add(a2*2+c2,(a1*2+c1)^1); 
        }
        n=2*nn; 
        slove();
        for(i=0;i<nn;i++)
        {
            if(belong[2*i] == belong[2*i+1])
            {
                printf("NO\n"); 
                break; 
            } 
        } 
        if(nn == i)
        {     
            printf("YES\n"); 
        }
    } 
    return 0;
}
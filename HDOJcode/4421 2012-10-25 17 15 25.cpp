******************************
    Author : townboy
    Submit time : 2012-10-25 17:15:25
    Judge Status : Accepted
    HDOJ Runid : 6996433
    Problem id : 4421
    Exe.time : 953MS
    Exe.memory : 4244K
    https://github.com/townboy
******************************


#include<stack>
#include<queue>
#include<stdio.h>
#include<memory.h>
#include<iostream>
#define maxn 1100
#define maxe 3000000
#define W 0
#define R 1
#define B 2

using namespace std;

int scc,Dindex,n,size,m;                // ¶¥µãÐòºÅÊÇ 0 - n-1 
int belong[maxn],instack[maxn],dfn[maxn],low[maxn],first[maxn];
stack<int>q;
int opp[maxn],group,deg[maxn],col[maxn];

int b[510][510],now,nn; 

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

int turn(int first,int second)
{
    return first-1;
} 

void yihuo(int x,int y)
{
    int tem,len=0; 
    tem=b[x][y]&1;
    b[x][y]>>=1;
    
    if(1 == tem)
    {
        add(turn(x,len)*2,turn(y,len)*2+1);
        add(turn(x,len)*2+1,turn(y,len)*2);
        add(turn(y,len)*2,turn(x,len)*2+1);
        add(turn(y,len)*2+1,turn(x,len)*2); 
    }
    else
    {
        add(turn(x,len)*2,turn(y,len)*2);
        add(turn(x,len)*2+1,turn(y,len)*2+1);
        add(turn(y,len)*2,turn(x,len)*2);
        add(turn(y,len)*2+1,turn(x,len)*2+1); 
    } 
} 

void huo(int x,int y)
{
    int tem,len=0; 
    tem=b[x][y]&1;
    b[x][y]>>=1;
    
    if(1 == tem)    
    {
        add(turn(x,len)*2,turn(y,len)*2+1);
        add(turn(y,len)*2,turn(x,len)*2+1); 
    }
    else        // 1,1 1,0 0,1 
    {
        add(turn(x,len)*2+1,turn(x,len)*2);
        add(turn(y,len)*2+1,turn(y,len)*2);        
    } 
} 

void yu(int x,int y)
{
    int tem,len=0; 
    tem=b[x][y]&1;
    b[x][y]>>=1;
    if(0 == tem)    
    {
        add(turn(x,len)*2+1,turn(y,len)*2);
        add(turn(y,len)*2+1,turn(x,len)*2); 
    }
    else 
    {
        add(turn(x,len)*2,turn(x,len)*2+1);
        add(turn(y,len)*2,turn(y,len)*2+1);                
    }         
} 

int pan()
{
    int i,f;
    for(i=1;i<=nn;i++)
    {
        if(0 != b[i][i])
        {
            return 0;
        }
    }
    for(i=1;i<=nn;i++)
    {
        for(f=1;f<=nn;f++)
        {
            if(b[f][i] != b[i][f])
            {
                return 0;
            }    
        }
    }
    return 1;
}

int main()
{
    int f,i; 
    while(scanf("%d",&nn)!=EOF)
    {
        group=nn; 
        n=2*group; 
        for(i=1;i<=nn;i++)
        {
            for(f=1;f<=nn;f++)
            {
                scanf("%d",&b[i][f]); 
            }
        }

        if(0 == pan())
        {
            printf("NO\n");
            continue;
        }
                
        for(now=1;now<=31;now++)
        {
            chu();        
            for(i=1;i<=nn;i++)
            {
                for(f=i+1;f<=nn;f++)
                {
                    if(i == f)
                    {
                        continue;    
                    } 
                    else if((i%2)==0 && (f%2)==0) 
                    {
                        huo(i,f);
                    }
                    else if((i%2)==1 && (f%2)==1)
                    {
                        yu(i,f); 
                    }
                    else
                    {
                        yihuo(i,f);        
                    } 
                }
            }
            slove();
            if(0 == check())
            {
                printf("NO\n"); 
                break;
            }
        }
        if(32 == now)
        {
            printf("YES\n");
        }
    } 
    return 0;
}
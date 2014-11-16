******************************
    Author : townboy
    Submit time : 2012-11-16 09:22:27
    Judge Status : Accepted
    HDOJ Runid : 7168195
    Problem id : 3035
    Exe.time : 6875MS
    Exe.memory : 61464K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<queue>
#include<iostream>
#define INF 0x7fffffff

using namespace std;

struct node 
{
    int v;
    int len;
    friend bool operator < (node a,node b)
    {
        return a.len > b.len;
    }
};
struct node ru;

int hash[1100000];
int nn,mm,n,s,t,dis[1100000];
vector<node>q[1100000];

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        q[i].clear();
        dis[i]=INF;
    }
    memset(hash,0,sizeof(hash));
}

int bfs()
{
    int tem,i,size,len,val,v;
    priority_queue<node>que;
    ru.v=s;
    ru.len=0;
    dis[s]=0;
    que.push(ru);
    
    while(!que.empty())
    {
        tem=que.top().v;
        val=que.top().len;
        que.pop();
    
        if(n == tem)
        {
            return val;
        }
        
        if(1 == hash[tem])
        {
            continue;        
        }
        hash[tem]=1;
        
        size=q[tem].size();
        for(i=0;i<size;i++)
        {
            v=q[tem][i].v;
            len=q[tem][i].len;
            if(dis[v] > dis[tem]+len)
            {
                dis[v]=dis[tem]+len;
                ru.v=v;
                ru.len=dis[v];
                que.push(ru);
            }
        }
    }
    return -1;
}

void add(int u,int v,int len)
{
    ru.len=len;
    ru.v=v;
    q[u].push_back(ru);
    ru.v=u;
    q[v].push_back(ru);
}

int turn(int x,int y,int left)
{
    return 4*((x-1)*mm+y-1)+left;
}

int main()
{
    int i,f,k;
    while(scanf("%d%d",&nn,&mm)!=EOF)
    {
        n=4*nn*mm+2;
        s=n-1;
        t=n;
        chu();
        for(i=0;i<=nn;i++)
        {
            for(f=1;f<=mm;f++)
            {
                scanf("%d",&k);
                if(0 == i)
                {
                    add(s,turn(1,f,1),k);
                }
                else if(nn == i)
                {
                    add(t,turn(nn,f,3),k);
                }
                else
                {
                    add(turn(i,f,3),turn(i+1,f,1),k);
                }
            }
        }
        
        for(i=1;i<=nn;i++)
        {
            for(f=0;f<=mm;f++)
            {
                scanf("%d",&k);
                if(0 == f)
                {
                    add(t,turn(i,1,4),k);
                }
                else if(mm == f)
                {
                    add(s,turn(i,mm,2),k);    
                }
                else
                {
                    add(turn(i,f,2),turn(i,f+1,4),k);
                }
            }
        }
        
        for(i=0;i<2*nn;i++)
        {
            for(f=0;f<2*mm;f++)
            {
                scanf("%d",&k);
                if(0 == i%2 && 0 == f%2)
                {
                    add(turn(i/2+1,f/2+1,1),turn(i/2+1,f/2+1,4),k);
                }
                else if(1 == i%2 && 0 == f%2)
                {
                    add(turn(i/2+1,f/2+1,3),turn(i/2+1,f/2+1,4),k);
                }
                else if(1 == i%2 && 1 == f%2)
                {
                    add(turn(i/2+1,f/2+1,2),turn(i/2+1,f/2+1,3),k);
                }
                else
                {
                    add(turn(i/2+1,f/2+1,1),turn(i/2+1,f/2+1,2),k);
                }
            }
        }
        printf("%d\n",bfs());
    }
    return 0;
}
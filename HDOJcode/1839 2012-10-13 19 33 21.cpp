******************************
    Author : townboy
    Submit time : 2012-10-13 19:33:21
    Judge Status : Accepted
    HDOJ Runid : 6915171
    Problem id : 1839
    Exe.time : 609MS
    Exe.memory : 2108K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#define INF 0x7fffffff
using namespace std;

int n,m,t,hash[11000]; 
__int64 dis[11000];

struct xx
{
    int v;
    int len;
};
struct xx ru;
vector<xx>q[11000];

struct node 
{
    int u;
    int v;
    int cap;
    int len;
};
struct node road[51000];

int cmp(const void *a,const void *b)
{
    return (*(struct node *)b).cap-(*(struct node *)a).cap;
}

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        dis[i]=INF;
        q[i].clear();
    }
    dis[1]=0;
    memset(hash,0,sizeof(hash));
}

void add(int u,int v,int len)
{
    ru.len=len;
    ru.v=v;
    q[u].push_back(ru);
    ru.v=u;
    q[v].push_back(ru);    
}

void spfa(int x)
{
    int len,tem,size,i,v;
    queue<int>que;
    add(road[x].u,road[x].v,road[x].len);
    que.push(road[x].u);
    que.push(road[x].v);
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        hash[tem]=0;
        size=q[tem].size();
        for(i=0;i<size;i++)
        {
            v=q[tem][i].v;
            len=q[tem][i].len;
            if(dis[v] > dis[tem]+len)
            {
                dis[v]=dis[tem]+len;
                if(0 == hash[v])
                {
                    hash[v]=1;
                    que.push(v);
                }
            }        
        }
    }
}  

int main()
{
    int num,i,f;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d%d",&n,&m,&t);
        chu();
        for(f=0;f<m;f++)
        {
            scanf("%d%d%d%d",&road[f].u,&road[f].v,&road[f].cap,&road[f].len);
        }
        qsort(road,m,sizeof(road[0]),cmp);
        for(f=0;f<m;f++)
        {
            spfa(f);
            if(dis[n] <= t)
            {
                printf("%d\n",road[f].cap);
                break;
            }
        }
    }
    return 0;
}
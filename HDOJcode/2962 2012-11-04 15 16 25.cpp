******************************
    Author : townboy
    Submit time : 2012-11-04 15:16:25
    Judge Status : Accepted
    HDOJ Runid : 7081516
    Problem id : 2962
    Exe.time : 140MS
    Exe.memory : 648K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<vector>
#include<memory.h>
#include<iostream>
#define INF 0x7fffffff 

using namespace std;

struct node 
{
    int v;
    int len;
    int cap;
};
struct node ru;

vector<node>q[1100];
int n,s,t,tcap,limit;
int dis[1100],hash[1100];

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        q[i].clear();    
    }
}

void add(int u,int v,int cap,int len)
{
    ru.len=len;
    ru.cap=cap;
    ru.v=v;
    q[u].push_back(ru);
    ru.v=u;
    q[v].push_back(ru);
}

int sspfa()
{
    int size,i,tem,cap,v;
    queue<int>que;
    memset(dis,-1,sizeof(dis));
    memset(hash,0,sizeof(hash)); 
    que.push(s);
    dis[s]=INF;

    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        hash[tem]=0;
        
        size=q[tem].size();        
        for(i=0;i<size;i++)
        {
            cap=q[tem][i].cap;
            v=q[tem][i].v;
            if(dis[v] < min(cap,dis[tem]))
            {
                dis[v]=min(cap,dis[tem]);
                if(0 == hash[v])
                {
                    hash[v]=1;
                    que.push(v);
                }    
            }    
        }
    } 
    return dis[t]; 
} 

int spfa()
{
    int size,i,v,len,tem,cap;
    queue<int>que;
    memset(hash,0,sizeof(hash));
    for(i=1;i<=n;i++)
    {
        dis[i]=INF; 
    } 
    dis[s]=0;
    que.push(s); 
    
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
            cap=q[tem][i].cap;
            if(cap < limit)
            {
                continue; 
            } 
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
    return dis[t]; 
}

int main()
{
    int u,v,cap,len;
    int i,m,cas=0;
    while(scanf("%d%d",&n,&m),n+m)
    {
        chu(); 
        cas++;    
        if(1 != cas)
        {
            printf("\n");
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&u,&v,&cap,&len);
            if(-1 == cap)
            {
                cap=INF; 
            } 
            add(u,v,cap,len);
        }
        scanf("%d%d%d",&s,&t,&tcap);
        limit=min(tcap,sspfa());
        printf("Case %d:\n",cas);        
        if(-1 == limit)
        {
            printf("cannot reach destination\n");
            continue; 
        } 
        
        printf("maximum height = %d\n",limit);
        printf("length of shortest route = %d\n",spfa());
    }
    return 0;
}
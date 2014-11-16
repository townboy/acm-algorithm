******************************
    Author : townboy
    Submit time : 2012-10-13 15:20:04
    Judge Status : Accepted
    HDOJ Runid : 6913856
    Problem id : 1595
    Exe.time : 1609MS
    Exe.memory : 11512K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<iostream>
#include<vector>
#include<memory.h> 
#define INF 0x7fffffff 
using namespace std; 

int mat[510000][3],hash[1100]; 
int n,m,dis[1100],ji,pre[1100],road[1100],shan[1100]; 
struct node 
{
    int id;
    int v;
    int len; 
}; 
struct node ru;

vector<node>q[1100]; 

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        dis[i]=INF;    
        q[i].clear(); 
    } 
} 

void add(int u,int v,int len,int id)
{
    ru.len=len;
    ru.id=id;
    ru.v=v; 
    q[u].push_back(ru); 
    ru.v=u;
    q[v].push_back(ru); 
} 

void spfa_yu()
{
    queue<int>que;
    int i,size,v,tem,id,len;
    que.push(1); 
    memset(hash,0,sizeof(hash));
    dis[1]=0; 
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
            id=q[tem][i].id;
            if(dis[v] > dis[tem]+len)
            {
                dis[v]=dis[tem]+len;
                pre[v]=tem;
                road[v]=id;
                if(0 == hash[v])
                {
                    hash[v]=1;
                    que.push(v); 
                }                
            } 
        } 
    }
    ji=0;
    tem=n;
    while(1 != tem)
    {
        shan[ji]=road[tem];
        ji++;
        tem=pre[tem];
    } 
} 

void build(int x)
{
    int i;
    for(i=0;i<m;i++)
    {
        if(i == x)
        {
            continue; 
        } 
        add(mat[i][0],mat[i][1],mat[i][2],i); 
    } 
} 

void spfa()
{
    queue<int>que;
    int i,size,v,tem,id,len;
    que.push(1); 
    memset(hash,0,sizeof(hash));
    dis[1]=0; 
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
    int i,f,ans;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        chu(); 
        for(i=0;i<m;i++) 
        {
            for(f=0;f<3;f++) 
            {
                scanf("%d",&mat[i][f]);        
            }
            add(mat[i][0],mat[i][1],mat[i][2],i); 
        } 
        spfa_yu();
        ans=0; 
        for(i=0;i<ji;i++)
        {
            chu();
            build(shan[i]);
            spfa();
            ans=max(ans,dis[n]); 
        } 
        printf("%d\n",ans); 
    } 
    return 0; 
} 
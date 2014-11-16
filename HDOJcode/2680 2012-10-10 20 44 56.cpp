******************************
    Author : townboy
    Submit time : 2012-10-10 20:44:56
    Judge Status : Accepted
    HDOJ Runid : 6900547
    Problem id : 2680
    Exe.time : 171MS
    Exe.memory : 524K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<vector>
#include<memory.h> 
#define INF 0x7fffffff 
using namespace std; 
 
struct node 
{
    int v;
    int len; 
}; 
struct node ru; 

vector<node>q[1100]; 
int s,t,n; 
int dis[1100],hash[1100]; 
 
void chu()
{    
    int i; 
    for(i=1;i<=n+1;i++)
    {
        q[i].clear(); 
        dis[i]=INF; 
    }
    memset(hash,0,sizeof(hash)); 
}

void add(int u,int v,int len)
{
    ru.v=v;
    ru.len=len; 
    q[u].push_back(ru); 
} 

void spfa()
{
    int len,tem,i,size,v;
    queue<int>que;
    que.push(s);
    dis[s]=0;
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
    int k,m,i,u,v,len; 
    while(scanf("%d%d%d",&n,&m,&t)!=EOF)
    { 
        chu();
        s=n+1; 
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&len);
            add(u,v,len); 
        } 
        scanf("%d",&k); 
        for(i=0;i<k;i++)
        {
            scanf("%d",&u); 
            add(s,u,0); 
        }
        spfa();
        if(INF == dis[t])
        {
            printf("-1\n"); 
            continue; 
        } 
        printf("%d\n",dis[t]); 
    } 
    return 0; 
} 
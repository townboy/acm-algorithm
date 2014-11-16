******************************
    Author : townboy
    Submit time : 2012-10-13 14:37:19
    Judge Status : Accepted
    HDOJ Runid : 6913634
    Problem id : 3986
    Exe.time : 687MS
    Exe.memory : 4016K
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
    int id;
    int v;
    int len;
};
struct node ru;

vector<node>q[1100];
int hash[1100],n,m,dis[1100],pre[1100],road[1100];
int shan[1100],ji,ans;
int mat[51000][3];

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        q[i].clear();
        dis[i]=INF;
    }
}

void add(int u,int v,int len,int id)
{
    ru.id=id;
    ru.len=len;
    ru.v=v;
    q[u].push_back(ru);
    ru.v=u;
    q[v].push_back(ru);
}

void spfa1()
{
    int i,size,v,tem,len,id;
    queue<int>que;
    memset(hash,0,sizeof(hash));            
    que.push(1);
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
            id=q[tem][i].id;
            len=q[tem][i].len;
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
    int i,size,v,tem,len,id;
    queue<int>que;
    memset(hash,0,sizeof(hash));            
    que.push(1);
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
    int u,v,len,num,i,f;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&n,&m);
        chu();
        for(f=0;f<m;f++)
        {
            scanf("%d%d%d",&u,&v,&len);
            mat[f][0]=u;
            mat[f][1]=v;
            mat[f][2]=len;
            add(u,v,len,f);
        }
        spfa1();
        ans=0;
        for(f=0;f<ji;f++)
        {
            chu();
            build(shan[f]);
            spfa();
            ans=max(ans,dis[n]);
        }
        if(INF == ans)
        {
            printf("-1\n");
            continue;
        }
        printf("%d\n",ans);
    }
    return 0;
}
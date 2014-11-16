******************************
    Author : townboy
    Submit time : 2012-12-02 11:55:09
    Judge Status : Accepted
    HDOJ Runid : 7310662
    Problem id : 4479
    Exe.time : 109MS
    Exe.memory : 1076K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include<iostream>
#define INF (((__int64)1)<<50)

using namespace std;

struct node 
{
    int u;
    int v;
    int len;
};
struct node que[51000];

int cmp(const void *a,const void *b)
{
    return (*(struct node *)a).len-(*(struct node *)b).len;
}

int n,m,lens[11000];
__int64 dis[11000][2];

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        dis[i][0]=dis[i][1]=INF;    
    }
    memset(lens,-1,sizeof(lens));
    dis[1][1]=0;
}

__int64 spfa()
{
    int i,u,v,len;
    __int64 nowu,nowv;
    for(i=0;i<m;i++)
    {
        u=que[i].u;
        v=que[i].v;
        len=que[i].len;
        if(lens[u] != len)
        {
            dis[u][1]=min(dis[u][1],dis[u][0]);
            dis[u][0]=INF;
            lens[u]=len;
        }
        if(lens[v] != len)
        {
            dis[v][1]=min(dis[v][1],dis[v][0]);
            dis[v][0]=INF;
            lens[v]=len;
        }
        
        nowu=min(dis[u][0],dis[u][1]);
        nowv=min(dis[v][0],dis[v][1]);
        if(dis[u][1] != INF)
        {
            if(dis[u][1]+len < nowv)
            {
                dis[v][0]=dis[u][1]+len;        
            }
        }
        if(dis[v][1] != INF)
        {
            if(dis[v][1]+len < nowu)
            {
                dis[u][0]=dis[v][1]+len;
            }
        }
    }
    if(min(dis[n][0],dis[n][1]) != INF)
    {
        return min(dis[n][0],dis[n][1]);
    }
    return -1;
}

int main()
{
    __int64 ans;
    int i,cas,f;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d",&n,&m);
        chu();
        for(f=0;f<m;f++)
        {
            scanf("%d%d%d",&que[f].u,&que[f].v,&que[f].len);
        }
        qsort(que,m,sizeof(que[0]),cmp);
        ans=spfa();
        if(-1 == ans)
        {
            printf("No answer\n");
            continue;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
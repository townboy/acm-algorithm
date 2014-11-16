******************************
    Author : townboy
    Submit time : 2013-04-24 19:19:28
    Judge Status : Accepted
    HDOJ Runid : 8163670
    Problem id : 3001
    Exe.time : 640MS
    Exe.memory : 8264K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<queue>
#define INF 0x3f3f3f3f

using namespace std;

int map[10][10];
int n,m;
int cost[10][60000],hash[10][60000];
queue<int>q;
int dig[60000][10];
int start[11];

void init()
{
    memset(cost,0x3f,sizeof(cost));
    memset(hash,0,sizeof(hash));
    for(int i=0;i<n;i++)
    {
        cost[i][start[i]]=0;
        q.push(i);q.push(start[i]);
    }
}

void yu()
{
    int i,tem,f;
    start[0]=1;
    for(i=1;i<11;i++)
        start[i]=3*start[i-1];
    for(i=0;i<60000;i++)
    {    
        tem=i;
        for(f=0;f<10;f++)
        {
            dig[i][f]=tem%3;
            tem/=3;
        }
    }
}

void spfa()
{
    int newcost,newstate;
    int i,head,state;
    while(!q.empty())
    {
        head=q.front();q.pop();
        state=q.front();q.pop();
        hash[head][state]=0;
        for(i=0;i<n;i++)
        {
            if(INF == map[head][i] || 2 == dig[state][i])
                continue;
            newcost = cost[head][state]+map[head][i];
            newstate = state+start[i];
            if(newcost < cost[i][newstate])
            {
                cost[i][newstate]=newcost;
                if(1 == hash[i][newstate])
                    continue;
                hash[i][newstate]=1;
                q.push(i);
                q.push(newstate);
            }
        }
    }
}

int check(int x)
{
    for(int i=0;i<n;i++)
        if(0 == dig[x][i])
            return 0;
    return 1;
}

int ans()
{
    int i,f,ans=INF;
    for(i=0;i<start[n];i++)
    {
        if(0 == check(i))    continue;
        for(f=0;f<n;f++)
            ans=min(ans,cost[f][i]);
    }
    return ans;
}

int main()
{
    int u,v,len;
    int i,tem;
    yu();
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(map,0x3f,sizeof(map));
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&len);
            u--;v--;
            map[u][v]=min(len,map[u][v]);
            map[v][u]=map[u][v];
        }
        init();
        spfa();
        tem=ans();
        printf("%d\n",INF==tem?-1:tem);
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-11-15 21:18:19
    Judge Status : Accepted
    HDOJ Runid : 7166066
    Problem id : 4370
    Exe.time : 406MS
    Exe.memory : 612K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<vector>
#include<queue>
#include<memory.h>
#include<iostream>
#define INF 0x7fffffff

using namespace std;

int n,dis[310],hash[310];
int map[310][310],huan[2];

int minn(int a,int b)
{
    return a<b?a:b;
}

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        dis[i]=INF; 
    } 
    memset(hash,0,sizeof(hash)); 
    huan[0]=huan[1]=INF;
}

int spfa()
{
    int i,tem;
    queue<int>que;
    dis[1]=0; 
    que.push(1);
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        hash[tem]=0; 
        for(i=1;i<=n;i++)
        {
            if(i == 1 && tem != 1)
            {
                if(huan[0] > dis[tem]+map[tem][i])
                {
                    huan[0]=dis[tem]+map[tem][i];
                } 
                continue;    
            }
            if(dis[i] > dis[tem]+map[tem][i])
            {
                dis[i]=dis[tem]+map[tem][i];
                if(0 == hash[i])
                {
                    hash[i]=1;
                    que.push(i); 
                } 
            } 
        }
    }
    return dis[n];
} 

int spfahuan()
{
    int i,tem;
    queue<int>que;

    for(i=1;i<=n;i++)
    {
        dis[i]=INF; 
    } 
    memset(hash,0,sizeof(hash)); 

    dis[n]=0; 
    que.push(n);
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        hash[tem]=0; 
        for(i=1;i<=n;i++)
        {
            if(i == n && tem != n)
            {
                if(huan[1] > dis[tem]+map[tem][i])
                {
                    huan[1]=dis[tem]+map[tem][i];
                } 
                continue;
            }
            if(dis[i] > dis[tem]+map[tem][i])
            {
                dis[i]=dis[tem]+map[tem][i];
                if(0 == hash[i])
                {
                    hash[i]=1;
                    que.push(i); 
                } 
            } 
        }
    }
    return huan[0]+huan[1];
}

int main()
{
    int i,f,ans;
    while(scanf("%d",&n)!=EOF)
    {
        chu(); 
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=n;f++)
            {
                scanf("%d",&map[i][f]);
            }
        }    
        ans=spfa();
        ans=min(ans,spfahuan());
        printf("%d\n",ans);
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-11-03 02:33:12
    Judge Status : Accepted
    HDOJ Runid : 7069847
    Problem id : 3268
    Exe.time : 0MS
    Exe.memory : 260K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<queue>
#include<stdlib.h>
#define INF 0x7fffffff

using namespace std;

int dis[25],hash[100];
int n,map[25][25],price[25];

int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}

void chu()
{
    int i;
    memset(map,-1,sizeof(map));
    memset(hash,0,sizeof(hash));
    for(i=1;i<=n;i++)
    {
        dis[i]=INF;
    }    
}

void add(int u,int v,int len)
{
    if(-1 == map[u][v])
    {
        map[u][v]=len;
        return ;
    }
    map[u][v]=min(len,map[u][v]);    
}

void spfa()
{
    int tem,i;
    queue<int>que;
    dis[n+1]=0;
    que.push(n+1);
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        hash[tem]=0;
        for(i=1;i<=n+1;i++)
        {
            if(-1 == map[tem][i])
            {
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
}

int main()
{
    int g,h;
    int i,cas,f,k,p,m,u,v,len;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d",&n);
        chu();
        for(f=0;f<n;f++)
        {
            scanf("%d%d",&k,&p);
            price[k]=p;
            add(n+1,k,p-1);
        }
        
        for(f=1;f<=n;f++)
        {
            for(g=1;g<=n;g++)
            {
                if(f == g)
                {
                    continue;
                }
                if(price[f] == price[g])
                {
                    add(f,g,0);
                }
            }
        }
        
        scanf("%d",&m);
        for(f=0;f<m;f++)
        {
            scanf("%d%d%d",&u,&v,&len);
            add(u,v,len);
        }
        spfa();
        for(f=1;f<=n;f++)
        {
            printf("%d %d\n",f,dis[f]);
        }
        m=0;
        for(f=1;f<=n;f++)
        {
            for(g=1;g<=n;g++)
            {
                for(h=1;h<=n;h++)
                {
                    if(f != g && g != h && f != h && dis[f]+dis[g] == dis[h] && 0 == hash[h])
                    {
                        hash[h]=1;
                        m++;                
                    }
                }
            }
        }    
        printf("%d\n",m);
    }
    return 0;
}
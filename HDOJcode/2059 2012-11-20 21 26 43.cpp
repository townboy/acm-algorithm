******************************
    Author : townboy
    Submit time : 2012-11-20 21:26:43
    Judge Status : Accepted
    HDOJ Runid : 7210590
    Problem id : 2059
    Exe.time : 15MS
    Exe.memory : 408K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<queue>
#include<iostream>
#define INF 1000000000

using namespace std;

__int64 l,n,c,t;
__int64 vr,vt1,vt2,pos[110];
int hash[110];
double map[110][110],dis[110];

void chu()
{
    int i,f;
    pos[0]=0;
    pos[n+1]=l;
    memset(hash,0,sizeof(hash));
    for(i=0;i<=n+1;i++)
    {
        dis[i]=INF;
        for(f=0;f<=n+1;f++)
        {
            map[i][f]=INF;
        }
    }
}

double cal(int s,int e)
{
    if(pos[e]-pos[s] <= c)
    {
        return (double)(pos[e]-pos[s])/vt1+t;
    }
    return (double)c/vt1+(double)(pos[e]-pos[s]-c)/vt2+t;
}

double walk(int s,int t)
{
    return (double)(pos[t]-pos[s])/vt2;
}

void build()
{
    int i,f;
    for(i=1;i<=n+1;i++)
    {
        map[0][i]=min(cal(0,i),map[0][i])-t;        
        if(pos[i] >= c)
        {
            break;
        }
    }
    for(i=1;i<=n;i++)
    {
        map[i][i+1]=min(walk(i,i+1),map[i][i+1]);
        for(f=i+1;f<=n+1;f++)
        {
            map[i][f]=min(cal(i,f),map[i][f]);        
            if(pos[f]-pos[i] >= c)
            {
                break;
            }            
        }
    }
}

void spfa()
{
    int tem,i;
    queue<int>que;
    dis[0]=0;
    que.push(0);
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        hash[tem]=0;
        
        for(i=0;i<=n+1;i++)
        {    
            if(INF == map[tem][i])
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
    int i;
    while(scanf("%I64d",&l)!=EOF)
    {
        scanf("%I64d%I64d%I64d",&n,&c,&t);
        scanf("%I64d%I64d%I64d",&vr,&vt1,&vt2);
        chu();
        for(i=1;i<=n;i++)
        {
            scanf("%I64d",&pos[i]);
        }
        build();
        spfa();

        if((double)l/vr < dis[n+1])
        {
            printf("Good job,rabbit!\n");
        }
        else
        {
            printf("What a pity rabbit!\n");
        }
    }
    return 0;
}
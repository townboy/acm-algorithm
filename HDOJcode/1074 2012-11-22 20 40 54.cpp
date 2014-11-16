******************************
    Author : townboy
    Submit time : 2012-11-22 20:40:54
    Judge Status : Accepted
    HDOJ Runid : 7227479
    Problem id : 1074
    Exe.time : 31MS
    Exe.memory : 976K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<queue>
#include<string>
#include<iostream>
#define INF 0x7fffffff
using namespace std;

int hash[40000],M,dis[40000],sum[41000];
int n,deadline[20],tt[20],pre[40000];
string id[20];

void chu()
{
    int i;
    memset(hash,0,sizeof(hash));
    for(i=0;i<=M;i++)
    {
        dis[i]=INF;
    }
}

int cal2(int sum,int x)
{
    return max(0,sum-deadline[x]);
}

void spfa()
{
    int tem,i,state;
    queue<int>que;
    que.push(0);
    dis[0]=0;
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        hash[tem]=0;
        for(i=1;i<=n;i++)
        {
            state=(tem|(1<<(i-1)));
            if(0 != ((1<<(i-1))&tem))
            {
                continue;
            }
            if(dis[state] > dis[tem]+cal2(sum[tem],i))
            {
                dis[state]=dis[tem]+cal2(sum[tem],i);
                pre[state]=i;
                if(0 == hash[state])
                {
                    hash[state]=1;
                    que.push(state);
                }
            }
            else if(dis[state] == dis[tem]+cal2(sum[tem],i))
            {
                if(i < pre[state])
                {
                    pre[state]=i;
                }
            }
        }
    }
}

int cal(int state)
{
    int i,sum=0;
    for(i=1;i<=n;i++)
    {
        if(0 == state%2)
        {
            sum+=tt[i];                        
        }
        state>>=1;
    }
    return sum;
}

void yu()
{
    int i;
    memset(sum,0,sizeof(sum));
    for(i=0;i<=M;i++)
    {
        sum[i]=cal(i);
    }
}

void print()
{
    int tem=M;
    while(0 != tem)
    {
        cout<<id[pre[tem]]<<endl;
        tem=tem^(1<<(pre[tem]-1));
    }
}

void debug()
{
    int i;
    for(i=0;i<=M;i++)
    {
        printf("%d %d %d\n",dis[i],pre[i],sum[i]);
    }
}

int main()
{
    int i,cas,f;
    string ch;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d",&n);
        M=(1<<n)-1;
        chu();
        for(f=1;f<=n;f++)
        {
            cin>>ch;
            id[f]=ch;
            scanf("%d%d",&deadline[f],&tt[f]);    
        }
        yu();
        spfa();
        printf("%d\n",dis[M]);
        print();
    }
    return 0;
}
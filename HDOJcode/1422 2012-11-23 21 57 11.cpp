******************************
    Author : townboy
    Submit time : 2012-11-23 21:57:11
    Judge Status : Accepted
    HDOJ Runid : 7235970
    Problem id : 1422
    Exe.time : 250MS
    Exe.memory : 2644K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>

using namespace std;

int dis[210000],val[210000];
int n,cost[210000];

void dp()
{
    int i;
    if(0 <= cost[1])
    {    
        dis[1]=1;
        val[1]=cost[1];
    }
    else
    {
        dis[1]=-1;
    }
    for(i=2;i<=2*n;i++)
    {
        if(-1 == dis[i-1])
        {
            if(cost[i] >= 0)
            {
                dis[i]=i;
                val[i]=cost[i];    
            }    
            else
            {
                dis[i]=-1;
            }
        }
        else
        {
            if(cost[i]+val[i-1] >= 0)
            {
                dis[i]=dis[i-1];
                val[i]=cost[i]+val[i-1]; 
            }
            else
            {
                dis[i]=-1;
            }
        }
    }    
}

void print()
{
    int i,ans=0;
    for(i=1;i<=2*n;i++)
    {
        if(-1 == dis[i])
        {
            continue;
        }
        ans=max(ans,i-dis[i]+1);
    }
    printf("%d\n",min(n,ans));
}

void debug()
{
    int i;
    for(i=1;i<=2*n;i++)
    {
        printf("%d ",dis[i]);
    }
    printf("\n");
}

int main()
{
    int i,get,use;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&get,&use);
            cost[i]=get-use;
            cost[i+n]=cost[i];
        }
        dp();
        print();
    }
    return 0;
}
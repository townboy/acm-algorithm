******************************
    Author : townboy
    Submit time : 2012-11-23 00:13:02
    Judge Status : Accepted
    HDOJ Runid : 7229671
    Problem id : 1078
    Exe.time : 359MS
    Exe.memory : 380K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h> 
#include<memory.h>
#include<iostream>
#define INF 0x7fffffff
using namespace std;

int val[110][110],dis[110][110];
int n,k;

int check(int x,int y,int a,int b)
{
    return abs(a-x)+abs(b-y)<=k?1:-1;
}

int dfs(int x,int y)
{
    int i,f;
    if(-1 != dis[x][y])
    {
        return dis[x][y];
    }
    dis[x][y]=-INF;
    for(i=1;i<=n;i++)
    {
        if(1 == check(x,y,i,y) && val[x][y]>val[i][y])
        {
            dis[x][y]=max(dis[x][y],dfs(i,y)+val[x][y]);            
        }            
    }
    for(f=1;f<=n;f++)
    {
        if(1 == check(x,y,x,f) && val[x][y]>val[x][f])
        {
            dis[x][y]=max(dis[x][y],dfs(x,f)+val[x][y]);            
        }            
    }
    return dis[x][y];
}

void chu()
{
    memset(dis,-1,sizeof(dis));
} 

void debug()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=n;f++)
        {
            printf("%d ",dis[i][f]);
        }
        printf("\n");
    }
}

int main()
{
    int ans;
    int i,f; 
    while(scanf("%d%d",&n,&k),-2 != n+k)
    {
        chu();
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=n;f++)
            {
                scanf("%d",&val[i][f]);
            }
        }
        ans=0;
        dis[1][1]=val[1][1];
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=n;f++)
            {
                ans=max(ans,dfs(i,f));
            }
        }
        printf("%d\n",ans);
    }    
    return 0;
}
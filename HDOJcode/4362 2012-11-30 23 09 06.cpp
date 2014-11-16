******************************
    Author : townboy
    Submit time : 2012-11-30 23:09:06
    Judge Status : Accepted
    HDOJ Runid : 7299685
    Problem id : 4362
    Exe.time : 234MS
    Exe.memory : 880K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include<iostream>
#define INF 100000000

using namespace std;

struct node 
{
    int cost;
    int loc;
};

int n,m,x,dis[55][1010]; 
struct node ball[55][1010];

int cmp(const void *a,const void *b)
{
    return (*(struct node *)a).loc-(*(struct node *)b).loc;
}

void chu()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=m;f++)
        {
            dis[i][f]=INF;
        }
    }
}

int dp()
{
    int start;
    int ans=INF,i,f,minn;
    for(i=1;i<=m;i++)
    {    
        dis[1][i]=abs(ball[1][i].loc-x)+ball[1][i].cost;
    }
    for(i=2;i<=n;i++)
    {
        minn=INF;
        start=1;
        for(f=1;f<=m;f++)
        {
            while(ball[i-1][start].loc <= ball[i][f].loc && start <= m)
            {
                minn=min(minn,dis[i-1][start]+(ball[i][f].loc-ball[i-1][start].loc));
                start++;
            }
            dis[i][f]=minn+ball[i][f].cost;
            minn+=(ball[i][f+1].loc-ball[i][f].loc);    
        }
        
        minn=INF;
        start=m;
        for(f=m;f>=1;f--)
        {
            while(ball[i-1][start].loc >= ball[i][f].loc && start > 0)
            {
                minn=min(minn,dis[i-1][start]+(ball[i-1][start].loc-ball[i][f].loc));
                start--;
            }
            dis[i][f]=min(dis[i][f],minn+ball[i][f].cost);
            minn+=(ball[i][f].loc-ball[i][f-1].loc);            
        }    
    }
    for(i=1;i<=m;i++)
    {
        ans=min(ans,dis[n][i]);
    }
    return ans;
}

int main()
{
    int i,cas,f,g;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d%d",&n,&m,&x);
        chu();
        for(f=1;f<=n;f++)
        {
            for(g=1;g<=m;g++)
            {
                scanf("%d",&ball[f][g].loc);
            }
        }
        for(f=1;f<=n;f++)
        {
            for(g=1;g<=m;g++)
            {
                scanf("%d",&ball[f][g].cost);
            }
            qsort(&ball[f][1],m,sizeof(ball[f][1]),cmp);
        }
        printf("%d\n",dp());
    }    
    return 0;
}
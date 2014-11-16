******************************
    Author : townboy
    Submit time : 2012-12-01 01:13:00
    Judge Status : Accepted
    HDOJ Runid : 7300480
    Problem id : 4374
    Exe.time : 328MS
    Exe.memory : 21088K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#define INF 1000000000

using namespace std;

__int64 que[10010],dis[110][10010];
int n,m,x,t,head,tail;
int sro[110][10010];
int rsum[110][10010],lsum[110][10010];

void chu()
{
    int i,f;
    memset(dis,0,sizeof(dis));
    memset(lsum,0,sizeof(lsum));
    memset(rsum,0,sizeof(rsum));
}

void quechu()
{
    head=0;
    tail=-1;
}

void del(int x)
{
    if(x == que[head])
        head++;
}

void add(int x)
{
    while(head <= tail)
    {
        if(que[tail] < x)
            tail--;
        else
            break;    
    }
    tail++;
    que[tail]=x;
}

__int64 dp()
{
    __int64 ans=-INF;
    int i,f;
    for(f=1;f<=m;f++)
    {
        if(abs(f-x) <= t)
        {
            if(f <= x)
                dis[1][f]=rsum[1][f]-rsum[1][x+1];
            else
                dis[1][f]=lsum[1][f]-lsum[1][x-1];
        }
        else
            dis[1][f]=-INF;
    }
    for(i=2;i<=n;i++)
    {
        quechu();
        for(f=1;f<=m;f++)
        {
            add(rsum[i][f]+dis[i-1][f]);
            if(f > t+1)
            {
                del(rsum[i][f-t-1]+dis[i-1][f-t-1]);
            }
            dis[i][f]=que[head]-rsum[i][f+1];
        }
        
        quechu();
        for(f=m;f>=1;f--)
        {
            add(lsum[i][f]+dis[i-1][f]);
            if(f <= m-t-1)
            {
                del(lsum[i][f+t+1]+dis[i-1][f+t+1]);
            }
            dis[i][f]=max(dis[i][f],que[head]-lsum[i][f-1]);
        }
    }
    for(i=1;i<=m;i++)
    {
        ans=max(ans,dis[n][i]);    
    }
    return ans;
}

void yu()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=m;f++)
        {
            lsum[i][f]=lsum[i][f-1]+sro[i][f];    
        }
        for(f=m;f>=1;f--)
        {
            rsum[i][f]=rsum[i][f+1]+sro[i][f];
        }
    }
}

int main()
{
    int i,f;
    while(scanf("%d%d%d%d",&n,&m,&x,&t)!=EOF)
    {
        chu();
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=m;f++)
            {
                scanf("%d",&sro[i][f]);
            }    
        }
        yu();
        printf("%I64d\n",dp());
    }    
    return 0;
}
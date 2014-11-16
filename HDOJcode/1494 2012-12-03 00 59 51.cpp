******************************
    Author : townboy
    Submit time : 2012-12-03 00:59:51
    Judge Status : Accepted
    HDOJ Runid : 7317547
    Problem id : 1494
    Exe.time : 15MS
    Exe.memory : 804K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#define INF 100000000

using namespace std;

int l,n;
int dis[11000][15];
int a[110],b[110];

int dp()
{
    int ans=INF,i,f,now,next;
    dis[1][1]=a[0];
    for(i=1;i<l*n;i++)
    {
        now=i%l;
        for(f=0;f<15;f++)
        {    
            if(INF == dis[i][f])
            {
                continue;
            }
            if(14 == f)
            {
                dis[i+1][9]=min(dis[i+1][9],dis[i][f]+b[now]);
                dis[i+1][10]=min(dis[i+1][10],dis[i][f]+a[now]);                        
            }
            else if(f >= 5)
            {
                dis[i+1][f+1]=min(dis[i+1][f+1],dis[i][f]+a[now]);
                dis[i+1][f-5]=min(dis[i+1][f-5],dis[i][f]+b[now]);                    
            }
            else
            {
                dis[i+1][f+1]=min(dis[i+1][f+1],dis[i][f]+a[now]);
            }
        }
    }
    for(f=0;f<15;f++)
    {
        ans=min(ans,dis[l*n][f]);    
    }
    return ans;
}

void chu()
{
    int i,f;
    for(i=0;i<=l*n;i++)
        for(f=0;f<15;f++)
            dis[i][f]=INF;
}

int main()
{
    int i;
    while(scanf("%d%d",&l,&n)!=EOF)
    {
        chu();
        for(i=0;i<l;i++)
            scanf("%d",&a[i]);
        for(i=0;i<l;i++)
            scanf("%d",&b[i]);
        
        printf("%d\n",dp());
    }
    return 0;
}
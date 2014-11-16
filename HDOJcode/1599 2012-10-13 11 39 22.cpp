******************************
    Author : townboy
    Submit time : 2012-10-13 11:39:22
    Judge Status : Accepted
    HDOJ Runid : 6912727
    Problem id : 1599
    Exe.time : 62MS
    Exe.memory : 300K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#define INF 100000000

using namespace std;

int n,map[110][110],ans;
int path[110][110];

void floyd()
{
    int k,i,f;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<k;i++)
        {
            for(f=i+1;f<k;f++)
            {
                ans=min(ans,path[k][i]+path[k][f]+map[i][f]);            
            }
        }

        for(i=1;i<=n;i++)
        {
            for(f=1;f<=n;f++)
            {
                map[i][f]=min(map[i][f],map[i][k]+map[k][f]);
            }
        }
    }
}

void add(int u,int v,int len)
{
    map[u][v]=min(map[u][v],len);
    path[u][v]=map[u][v];
    map[v][u]=min(map[v][u],len);
    path[v][u]=map[v][u];
}

void chu()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=n;f++)
        {
            map[i][f]=INF;
            path[i][f]=INF;
        }
    }
}

int main()
{
    int i,u,v,len,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        chu();    
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&len);
            add(u,v,len);
        }
        ans=INF;
        floyd();
        if(INF == ans)
        {
            printf("It's impossible.\n");
            continue;
        }
        printf("%d\n",ans);
    }
    return 0;
}
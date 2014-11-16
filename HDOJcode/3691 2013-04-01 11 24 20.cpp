******************************
    Author : townboy
    Submit time : 2013-04-01 11:24:20
    Judge Status : Accepted
    HDOJ Runid : 7955026
    Problem id : 3691
    Exe.time : 640MS
    Exe.memory : 612K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>

#define maxn 310
#define INF 0x7fffffff
using namespace std;

int id[maxn];
int dis[maxn],gra[maxn][maxn],vis[maxn];

int Min_Cut(int n)
{
    int ans=INF;
    int i,f,s,t;
    for(i=0;i<n;i++)    id[i]=i;
    while(n > 1)
    {
        t=1;
        for(i=1;i<n;i++)
        {
            dis[id[i]]=gra[id[0]][id[i]];
            if(dis[id[i]] > dis[id[t]])
                t=i;
        }
        memset(vis,0,sizeof(vis));
        vis[id[0]]=1;
        for(i=0;i<n-2;i++)
        {
            vis[id[t]]=1;
            s=t;
            t=-1;
            for(f=1;f<n;f++)
            {
                if(1 == vis[id[f]])    continue;
                dis[id[f]]+=gra[id[s]][id[f]];
                if(-1 == t || dis[id[t]] < dis[id[f]])
                    t=f;
            }
        }
        ans=min(ans,dis[id[t]]);
        for(i=0;i<n;i++)
        {
            gra[id[s]][id[i]]+=gra[id[t]][id[i]];
            gra[id[i]][id[s]]=gra[id[s]][id[i]];
        }
        id[t]=id[--n];
    }
    return ans;
}

int main()
{
    int u,v,len;
    int i,n,m,k,ans,s;
    while(scanf("%d%d%d",&n,&m,&s),n+m+s)
    {
        memset(gra,0,sizeof(gra));
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&len);
            u--;
            v--;
            gra[u][v]+=len;
            gra[v][u]+=len;
        }
        ans=Min_Cut(n);
        printf("%d\n",ans);
    }
    return 0;
}
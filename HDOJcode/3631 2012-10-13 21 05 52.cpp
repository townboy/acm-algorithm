******************************
    Author : townboy
    Submit time : 2012-10-13 21:05:52
    Judge Status : Accepted
    HDOJ Runid : 6915858
    Problem id : 3631
    Exe.time : 312MS
    Exe.memory : 572K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#define INF 0x7fffffff
#include<iostream>
using namespace std;

int map[310][310],n,m,q;
int mark[310];

void chu()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=n;f++)
        {
            map[i][f]=INF;
        }
        map[i][i]=0;
    }
    memset(mark,0,sizeof(mark));
}

void add(int u,int v,int len)
{
    map[u][v]=min(map[u][v],len);
}

void floyd(int x)
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=n;f++)
        {
            if(INF ==map[i][x] || INF == map[x][f])
            {
                continue;
            }
            map[i][f]=min(map[i][f],map[i][x]+map[x][f]);
        }
    }
}

int main()
{
    int k,i,u,v,len,cas=0;
    while(scanf("%d%d%d",&n,&m,&q),n+m+q)
    {
        cas++;
        if(1 != cas)
        {
            printf("\n");
        }
        printf("Case %d:\n",cas);
        chu();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&len);
            add(u+1,v+1,len);
        }    
        for(i=0;i<q;i++)
        {
            scanf("%d\n",&k);
            if(0 == k)
            {
                scanf("%d",&u);
                u++;
                if(1 == mark[u])
                {
                    printf("ERROR! At point %d\n",u-1);
                    continue;
                }        
                mark[u]=1;
                floyd(u);
            }
            else
            {
                scanf("%d%d",&u,&v);
                u++;
                v++;
                if(0 == mark[u] || 0 == mark[v])
                {
                    printf("ERROR! At path %d to %d\n",u-1,v-1);
                    continue;
                }
                if(INF == map[u][v])
                {
                    printf("No such path\n");
                }
                else
                {
                    printf("%d\n",map[u][v]);
                }
            }        
        }
    }
    return 0;
}
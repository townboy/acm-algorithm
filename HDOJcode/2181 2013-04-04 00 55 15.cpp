******************************
    Author : townboy
    Submit time : 2013-04-04 00:55:15
    Judge Status : Accepted
    HDOJ Runid : 7989787
    Problem id : 2181
    Exe.time : 0MS
    Exe.memory : 232K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<algorithm>

using namespace std;

int vis[25],start;
int cas;
int path[25],to[25][3];

void ans()
{
    int i;
    cas++;
    printf("%d: ",cas);
    for(i=1;i<=21;i++)
        printf(" %d",path[i]);
    printf("\n");
}

void dfs(int now,int pos)
{
    int i;
    if(21 == pos)
    {
        ans();
        return ;
    }
    if(20 == pos)
    {
        for(i=0;i<3;i++)
            if(start == to[now][i])
            {
                path[pos+1]=start;
                dfs(start,pos+1);
            }
        return ;
    }
    for(i=0;i<3;i++)
    {
        if(1 == vis[to[now][i]])    continue;
        vis[to[now][i]]=1;
        path[pos+1]=to[now][i];
        dfs(to[now][i],pos+1);
        vis[to[now][i]]=0;
    }
}

int main()
{
    int a,b;
    int i,f,tem;
    while(scanf("%d",&tem)!=EOF)
    {
        to[1][0]=tem;
        for(i=1;i<=2;i++)
        {
            scanf("%d",&tem);
            to[1][i]=tem;
        }
        for(i=2;i<=20;i++)
        {
            for(f=0;f<3;f++)
            {
                scanf("%d",&tem);
                to[i][f]=tem;
            }
            sort(to[i],to[i]+3);
        }    
        while(scanf("%d",&start),start)
        {
            cas=0;
            memset(vis,0,sizeof(vis));
            vis[start]=1;
            path[1]=start;
            dfs(start,1);
        }
    }
    return 0;
}
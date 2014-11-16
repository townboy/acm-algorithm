******************************
    Author : townboy
    Submit time : 2012-11-09 11:52:02
    Judge Status : Accepted
    HDOJ Runid : 7118527
    Problem id : 2807
    Exe.time : 1859MS
    Exe.memory : 920K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<queue>
#define INF 0x7fffffff

using namespace std;

int res[90][90];
int s,t,n,m,dis[90],run[90];
int mat[85][85][85],map[85][85];

void chu()
{
    memset(map,0,sizeof(map));
}

int check(int x)
{
    int i,f;
    for(i=1;i<=m;i++)
    {
        for(f=1;f<=m;f++)
        {
            if(res[i][f] != mat[x][i][f])
            {
                return 0;        
            }
        }
    }
    return 1;
}

void op(int x)
{
    int i,f,g,h;
    for(i=1;i<=n;i++)
    {
        if(i == x)
        {
            continue;
        }
        memset(res,0,sizeof(res));
        for(f=1;f<=m;f++)
        {
            for(g=1;g<=m;g++)
            {
                for(h=1;h<=m;h++)
                {
                    res[f][g]+=mat[x][f][h]*mat[i][h][g];
                }
            }            
        }
        for(f=1;f<=n;f++)
        {
            if(1 == map[x][f] || f == i)
            {
                continue;
            }
            map[x][f]=check(f);
        }
    }
}

void bfs()
{
    int i,tem;
    queue<int>que;
    
    for(i=1;i<=n;i++)
    {
        dis[i]=INF;
    }
    dis[s]=0;
    que.push(s);
    
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        
        if(0 == run[tem])
        {
            run[tem]=1;
            op(tem);
        }
        for(i=1;i<=n;i++)
        {
            if(0 == map[tem][i])
            {
                continue;
            }
            if(dis[i] > dis[tem]+1)
            {
                dis[i]=dis[tem]+1;
                que.push(i);
            }
        }
    }
}

int main()
{
    int i,f,g,k;
    while(scanf("%d%d",&n,&m),n+m)
    {
        chu();
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=m;f++)
            {
                for(g=1;g<=m;g++)
                {
                    scanf("%d",&mat[i][f][g]);
                }
            }
        }    
        memset(run,0,sizeof(run));
        scanf("%d",&k);
        for(i=0;i<k;i++)
        {
            scanf("%d%d",&s,&t);
            bfs();
            if(INF == dis[t])
            {
                printf("Sorry\n");
                continue;
            }
            printf("%d\n",dis[t]);
        }
    }
    return 0;
}
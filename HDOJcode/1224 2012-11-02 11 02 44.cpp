******************************
    Author : townboy
    Submit time : 2012-11-02 11:02:44
    Judge Status : Accepted
    HDOJ Runid : 7064030
    Problem id : 1224
    Exe.time : 0MS
    Exe.memory : 288K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int map[110][110],n;
int inte[110],m,dis[110],pre[110];

void chu()
{
    memset(map,0,sizeof(map));
    memset(dis,0,sizeof(dis));
    memset(inte,0,sizeof(inte));
}

void dp()
{
    int i,f;
    for(i=1;i<=n;i++)
    {    
        for(f=1;f<=n+1;f++)
        {
            if(0 == map[i][f])
            {
                continue;
            }
            if(dis[f] < dis[i]+inte[f])
            {
                dis[f]=dis[i]+inte[f];
                pre[f]=i;
            }
        }
    }
}

void print()
{
    int path[110],ji;
    int tem,i;
    printf("points : %d\n",dis[n+1]);
    printf("circuit : "); 
    tem=n+1;    
    ji=1;
    path[0]=n+1;
    while(1 != tem)
    {
        tem=pre[tem];
        path[ji]=tem;
        ji++;
    }
    for(i=ji-1;i>0;i--)
    {
        printf("%d->",path[i]);
    }
    printf("1\n");
}

void debug()
{
    int i;
    for(i=1;i<=n+1;i++)
    {    
        printf("%d ",dis[i]);
    }
    printf("\n");
}

int main()
{
    int i,cas,f,u,v;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        if(0 != i)
        {    
            printf("\n");
        }
    
        scanf("%d",&n);
        chu();
        for(f=1;f<=n;f++)
        {
            scanf("%d",&inte[f]);
        }
        scanf("%d",&m);
        for(f=0;f<m;f++)
        {
            scanf("%d%d",&u,&v);
            map[u][v]=1;
        }
        dp();
        
        printf("CASE %d#\n",i+1);
        print();
    }    
    return 0;
}
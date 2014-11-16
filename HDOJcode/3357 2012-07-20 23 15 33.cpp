******************************
    Author : townboy
    Submit time : 2012-07-20 23:15:33
    Judge Status : Accepted
    HDOJ Runid : 6283204
    Problem id : 3357
    Exe.time : 109MS
    Exe.memory : 464K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int map[250][250],n;

void chu()
{
    int i;
    memset(map,0,sizeof(map));    
    for(i=1;i<=n;i++)
    {
        map[i][i]=1;
    }
}

int check(int u,int v)
{
    int i,f;
    if(1 == map[v][u])
    {
        return 1;
    }    
    if(1 == map[u][v])
    {    
        return 0;
    }    

    for(f=1;f<=n;f++)
    {
        if(0 == map[v][f])
        {
            continue;
        }
        for(i=1;i<=n;i++)
        {
            map[i][f]|=map[i][u];
        }
    }
    return 0;
}

int main()
{
    int u,v,ans,m,i,cas=0;
    while(scanf("%d%d",&n,&m),n+m)
    {
        chu();
        ans=0;
        cas++;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            if(1 == check(u,v))
            {
                ans++;
            }
        }
        printf("%d. %d\n",cas,ans);
    }
    return 0;
}
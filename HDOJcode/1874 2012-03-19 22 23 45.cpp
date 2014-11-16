******************************
    Author : townboy
    Submit time : 2012-03-19 22:23:45
    Judge Status : Accepted
    HDOJ Runid : 5587651
    Problem id : 1874
    Exe.time : 15MS
    Exe.memory : 272K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int maxint=1000000000;
int map[120][120],dis[110],hash[110];

void chu(int v)
{
    int i,f;
    for(i=0;i<=v;i++)
    {
        hash[i]=0;
        dis[i]=maxint;
    }
    for(i=0;i<v;i++)
    {
        for(f=0;f<v;f++)
        {
            map[i][f]=-1;
        }
    }
}

int main()
{
    int i,f,v,e,a,b,x,s,t,min,aim;
    while(scanf("%d%d",&v,&e)!=EOF)
    {
        chu(v);
        for(i=0;i<e;i++)
        {
            scanf("%d%d%d",&a,&b,&x);
            if(-1==map[a][b])
            {
                map[a][b]=x;
                map[b][a]=x;
            }
            else
            {
                if(x<map[a][b])
                {
                    map[a][b]=x;
                    map[b][a]=x;
                }
            }
        }
        scanf("%d%d",&s,&t);
        dis[s]=0;
        hash[s]=1;
        for(i=0;i<v;i++)
        {
            if(1==hash[i])
            {
                continue;
            }
            if(-1==map[s][i])
            {
                continue;
            }
            if(map[s][i]+dis[s]<dis[i])
            {
                dis[i]=map[s][i]+dis[s];
            }
        }
        for(i=0;i<v-1;i++)
        { 
            min=maxint;
            for(f=0;f<v;f++)
            {
                if(1==hash[f])
                {
                    continue;
                }
                if(dis[f]<min)
                {
                    min=dis[f];
                    aim=f;
                }
            }
            hash[aim]=1;
            for(f=0;f<v;f++)
            {
                if(1==hash[f])
                {
                    continue;
                }
                if(-1==map[aim][f])
                {
                    continue;
                }
                if(dis[aim]+map[aim][f]<dis[f])
                {
                    dis[f]=dis[aim]+map[aim][f];
                }
            }
        }
        if(maxint==dis[t])
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",dis[t]);
        }
    }
    return 0;
}
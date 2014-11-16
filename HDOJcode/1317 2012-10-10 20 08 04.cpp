******************************
    Author : townboy
    Submit time : 2012-10-10 20:08:04
    Judge Status : Accepted
    HDOJ Runid : 6900205
    Problem id : 1317
    Exe.time : 78MS
    Exe.memory : 316K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<queue>
#define INF -100000000
using namespace std;

int s,t;
int n,val[110],map[110][110];
int dis[110],hash[110],ru[110],flag;
int ff[110][110],vis[110];

void chu()
{
    int i;
    memset(map,0,sizeof(map));
    memset(hash,0,sizeof(hash));
    memset(ru,0,sizeof(ru));
    memset(ff,0,sizeof(ff));
    memset(vis,0,sizeof(vis));
    
    for(i=2;i<=n;i++)
    {
        dis[i]=INF;
    }
}

int checkin(int x)
{
    if(1 == ff[x][t])
    {
        flag=1;
        return 1; 
    }
    return 0; 
} 

void spfa()
{
    int tem,i;
    queue<int>q;
    q.push(s);
    dis[s]=100;
    ru[s]++;
    while(!q.empty())
    {
        tem=q.front();
        q.pop();
        hash[tem]=0;
        if(tem == t)
        {
            if(dis[t] > 0)
            {
                flag=1;
                return ; 
            } 
        } 
        if(0 >= dis[tem])
        {
            continue;
        }
        for(i=1;i<=n;i++)
        {
            if(0 == map[tem][i])
            {
                continue;
            }
            if(dis[i] < dis[tem]+val[i])
            {
                dis[i]=dis[tem]+val[i];                    
                if(0 == hash[i])
                {
                    hash[i]=1;
                    q.push(i);
                    ru[i]++;
                }
                if(n < ru[i])
                {
                    if(0 == vis[i])
                    {
                        if(1 == checkin(i))
                        {
                            flag=1; 
                            return ;            
                        } 
                        vis[i]=1; 
                    } 
                }
                if(200 < ru[i])
                {
                    return ; 
                } 
            }
        }
    }
}

void flyod()
{
    int i,f,k;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=n;f++)
            {
                if(1 == ff[i][k] && 1 == ff[k][f])
                {
                    ff[i][f]=1; 
                }
            } 
        }
    }
}

int main()
{
    int i,k,next,f;
    while(scanf("%d",&n),-1 != n)
    {
        chu();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&val[i]);
            scanf("%d",&k);
            for(f=0;f<k;f++)
            {
                scanf("%d",&next);
                map[i][next]=1;
                ff[i][next]=1; 
            }
        }
        s=1;
        t=n;
        flag=0;
        flyod();
        spfa();
    
        if(1 == flag)
        {
            printf("winnable\n");
            continue; 
        } 
        if(0 < dis[t])
        {
            printf("winnable\n");
        }    
        else
        {
            printf("hopeless\n");
        }
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-11-07 23:04:55
    Judge Status : Accepted
    HDOJ Runid : 7109497
    Problem id : 2433
    Exe.time : 1203MS
    Exe.memory : 1668K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<memory.h>
#include<vector>
#define INF 0x7fffffff

using namespace std;

int n,m,edgehash[110][3100],to[6100];
int head[110],next[6100],size;
int dis[110],hash[110],sum[110];

void chu()
{
    int i;
    memset(edgehash,0,sizeof(edgehash));    
    memset(head,-1,sizeof(head));
    size=0;
}

void add(int u,int v)
{
    to[size]=v;
    next[size]=head[u];
    head[u]=size;
    size++;
    
    to[size]=u;
    next[size]=head[v];
    head[v]=size;
    size++;        
}

void bfs(int s)
{
    int v,id,i,tem;
    queue<int>que;
    
    memset(hash,0,sizeof(hash));
    hash[s]=1;
    dis[s]=0;
    que.push(s);
    
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        
        for(id=head[tem];-1 != id;id=next[id])
        {    
            v=to[id];
            if(0 == hash[v])
            {
                hash[v]=1;
                dis[v]=dis[tem]+1;
                edgehash[s][id>>1]=1;
                que.push(v);
            }
        }
    }
    sum[s]=0;
    for(i=1;i<=n;i++)
    {
        sum[s]+=dis[i];
    }
}

int bfs_tem(int del,int s)
{
    int tem,v,id,sum,i;
    queue<int>que;
    que.push(s);
    memset(dis,-1,sizeof(dis));
    dis[s]=0;
    memset(hash,0,sizeof(hash));
    hash[s]=1;
    
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        
        for(id=head[tem];-1 != id;id=next[id])
        {
            if((id>>1) == del)
            {
                continue;
            }
            v=to[id];
            if(0 == hash[v])
            {
                hash[v]=1;
                dis[v]=dis[tem]+1;
                que.push(v);
            }
        }
    }    
    
    sum=0;
    for(i=1;i<=n;i++)
    {
        if(-1 == dis[i])
        {
            return -1;
        }
        sum+=dis[i];
    }
    return sum;
}

void debug()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=0;f<m;f++)
        {
            printf("%d ",edgehash[i][f]);
        }
        printf("\n");
    }
    printf("\n");
}    

int main()
{
    int u,v,tem;
    int i,f,ans;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        chu();
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            add(u,v);
        }
        for(i=1;i<=n;i++)
        {
            bfs(i);
        }
        
        for(i=0;i<m;i++)
        {
            ans=0;
            for(f=1;f<=n;f++)
            {
                if(1 == edgehash[f][i])
                {
                    tem=bfs_tem(i,f);
                    if(-1 == tem)
                    {
                        break;
                    }
                    ans+=tem;                
                }
                else
                {
                    ans+=sum[f];
                }
            }    
            if(f != n+1)
            {
                printf("INF\n");
                continue;
            }    
            printf("%d\n",ans);
        }    
    }    
    return 0;
}
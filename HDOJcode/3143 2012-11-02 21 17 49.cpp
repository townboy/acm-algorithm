******************************
    Author : townboy
    Submit time : 2012-11-02 21:17:49
    Judge Status : Accepted
    HDOJ Runid : 7068376
    Problem id : 3143
    Exe.time : 0MS
    Exe.memory : 320K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<queue>
#define INF 0x7fffffff

using namespace std;

int hash[110],dis[110],pdis[110];
int map[110][110],end[110];
int n,m,e,b,p,set[110];
double l,r,mid;

void chu()
{
    int i; 
    memset(map,-1,sizeof(map));
    memset(end,0,sizeof(end)); 
    for(i=1;i<=n;i++)
    {
        set[i]=i; 
        pdis[i]=INF;
    } 
}

void merge(int a,int b)
{
    set[a]=b; 
} 

int find(int x)
{
    return x==set[x]?x:set[x]=find(set[x]); 
} 

void add(int u,int v,int len)
{
    map[u][v]=map[v][u]=len;    
}

int able()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=i+1;f<=n;f++)
        {
            if(-1 != map[i][f])
            {
                if(p == i || p == f)
                {
                    continue; 
                }
                merge(find(i),find(f)); 
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(0 == end[i])
        {
            continue; 
        }
        if(find(b) == find(i))
        {
            return 1;
        }
    } 
    return 0; 
} 

int spfa()
{
    int i,tem,newlen;
    queue<int>que;
    for(i=1;i<=n;i++)
    {
        dis[i]=INF;
    }
    memset(hash,0,sizeof(hash));
    que.push(b);
    dis[b]=0;
    
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        hash[tem]=0;
        if(1 == end[tem])
        {
            return 1;
        }
        
        for(i=1;i<=n;i++)
        {
            if(-1 == map[tem][i])
            {
                continue;
            }
            newlen=dis[tem]+map[tem][i];
            if(newlen < dis[i] && (double)newlen/(pdis[i]/160.0) <= mid)
            {
                dis[i]=newlen;
                if(0 == hash[i])
                {
                    hash[i]=1;
                    que.push(i);
                }    
            }
        }
    }
    return 0;
}

void pspfa()
{
    int i,tem;
    queue<int>que;
    memset(hash,0,sizeof(hash));
    que.push(p);
    pdis[p]=0;
    
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        hash[tem]=0;
        
        for(i=1;i<=n;i++)
        {
            if(-1 == map[tem][i])
            {
                continue;
            }
            if(pdis[i] > pdis[tem]+map[tem][i])
            {
                pdis[i]=pdis[tem]+map[tem][i];
                if(0 == hash[i])
                {
                    hash[i]=1;
                    que.push(i);    
                }
            }
        }
    }
}

double bs()
{
    l=0;
    r=10000000;
    while(r-l > 1e-7)
    {
        mid=(l+r)/2;    
        if(1 == spfa())
        {
            r=mid;            
        }
        else
        {
            l=mid;
        }
    }        
    return (l+r)/2;
} 

void debug()
{
    int i;
    for(i=1;i<=n;i++)
    {
        printf("%d ",pdis[i]);
    }
    printf("\n");
}

int main()
{
    int k; 
    int i,u,v,len;
    while(scanf("%d%d%d",&n,&m,&e)!=EOF)
    {
        chu(); 
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&len);
            add(u,v,len);
        }
        for(i=0;i<e;i++)
        {
            scanf("%d",&k);
            end[k]=1;
        }
        scanf("%d%d",&b,&p);
        if(0 == able()) 
        {
            printf("IMPOSSIBLE\n"); 
            continue; 
        }
        pspfa();
        printf("%.7lf\n",bs());        
    }
    return 0;
}
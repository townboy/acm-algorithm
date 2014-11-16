******************************
    Author : townboy
    Submit time : 2012-07-23 22:16:22
    Judge Status : Accepted
    HDOJ Runid : 6308773
    Problem id : 2874
    Exe.time : 1828MS
    Exe.memory : 26576K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<vector>
#include<malloc.h>

using namespace std;

struct node 
{
    int v;
    int dis;
};
struct node run;

struct query
{
    int id;
    int v;
};
struct query ruq;

vector<node>q[10005];
vector<query>que[10005];
int n,visit[10010],hash[10005],ans[1000500],dis[10005];
int ji,set[10005],ancestor[10005];

int find(int x)
{
    return x==set[x]?x:set[x]=find(set[x]);
}

void merge(int a,int b)
{
    set[a]=b;
}

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        q[i].clear();
        que[i].clear();
        set[i]=i;
    }
    memset(hash,0,sizeof(hash));
    memset(ans,0,sizeof(ans));
    memset(visit,0,sizeof(visit));
} 

void lca(int x,int len)
{
    int u,v;
    int i,size=q[x].size();
    hash[x]=ji;
    dis[x]=len;
    ancestor[x]=x;
    for(i=0;i<size;i++)
    {
        if(0 != hash[q[x][i].v])
        {
            continue;
        }
        lca(q[x][i].v,len+q[x][i].dis);
        v=find(q[x][i].v);
        merge(v,x);
    }
    visit[x]=1;
    size=que[x].size();
    for(i=0;i<size;i++)
    {
        if(1 == visit[que[x][i].v])
        {
            if(hash[x] != hash[que[x][i].v])
            {
                ans[que[x][i].id]=-1;
                continue;
            }
            ans[que[x][i].id]=dis[x]+dis[que[x][i].v]-2*dis[ancestor[find(que[x][i].v)]];
        }
    }
}

int main()
{
    int i,u,v,len,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        chu();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&len);
            run.dis=len;
            run.v=v;
            q[u].push_back(run);
            run.v=u;
            q[v].push_back(run);            
        }
        for(i=0;i<k;i++)
        {
            scanf("%d%d",&u,&v);
            ruq.id=i;
            ruq.v=v;
            que[u].push_back(ruq);
            ruq.v=u;
            que[v].push_back(ruq);    
        }
        ji=0;
        for(i=1;i<=n;i++)
        {
            if(0 == hash[i])
            {
                ji++;
                lca(i,0);    
            }
        }
        for(i=0;i<k;i++)
        {
            if(-1 == ans[i])
            {
                printf("Not connected\n");    
            }
            else
            {
                printf("%d\n",ans[i]);            
            }
        }
    }
    return 0;
}
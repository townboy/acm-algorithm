******************************
    Author : townboy
    Submit time : 2012-10-06 21:53:56
    Judge Status : Accepted
    HDOJ Runid : 6878257
    Problem id : 2586
    Exe.time : 46MS
    Exe.memory : 4772K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<vector>
#include<memory.h>

using namespace std;

struct node
{
    int u;
    int len;
};
struct node ru;

struct question 
{
    int id;
    int u;
};
struct question tem;

vector<node>q[41000];
vector<question>qes[40010];
int set[41000],n,m,ancestor[41000],dis[41000],hash[41000],visit[41000];
int ans[41000];

int find(int x)
{
    return x==set[x]?x:set[x]=find(set[x]);
}

void merge(int a,int b)
{
    set[a]=b;
}

void lca(int x,int len)
{
    int id,i,v,size;
    hash[x]=1;
    dis[x]=len;
    ancestor[x]=x;
    size=q[x].size();
    for(i=0;i<size;i++)
    {
        v=q[x][i].u;
        if(1 == hash[v])
        {
            continue;
        }
        lca(v,len+q[x][i].len);
        merge(find(v),find(x));
        ancestor[find(x)]=x;
    }
    visit[x]=1;
    size=qes[x].size();
    for(i=0;i<size;i++)
    {
        id=qes[x][i].id;
        v=qes[x][i].u;
        if(1 == visit[v])
        {
            ans[id]=dis[x]+dis[v]-2*dis[ancestor[find(v)]];
        }
    }
}

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        set[i]=i;
        q[i].clear();
        qes[i].clear();    
    }
    memset(hash,0,sizeof(hash));
    memset(visit,0,sizeof(visit));
}

int main()
{
    int i,num,f,u,v,len;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&n,&m);    
        chu();
        for(f=0;f<n-1;f++)
        {
            scanf("%d%d%d",&u,&v,&len);
            ru.u=v;
            ru.len=len;
            q[u].push_back(ru);
            ru.u=u;
            q[v].push_back(ru);
        }
        for(f=0;f<m;f++)
        {
            scanf("%d%d",&u,&v);
            tem.id=f;
            tem.u=u;
            qes[v].push_back(tem);
            tem.u=v;
            qes[u].push_back(tem);    
        }
        lca(1,0);
        for(f=0;f<m;f++)
        {
            printf("%d\n",ans[f]);
        }
    }
    return 0;
}
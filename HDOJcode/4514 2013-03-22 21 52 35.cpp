******************************
    Author : townboy
    Submit time : 2013-03-22 21:52:35
    Judge Status : Accepted
    HDOJ Runid : 7844678
    Problem id : 4514
    Exe.time : 781MS
    Exe.memory : 25944K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;

int len[100010];
int vis[100010];
int set[100010];
int n,m,far;
int cur_far,farid; 

struct node 
{
    int v;
    int val;
};
struct node ru;
vector<node>map[110000];

void add(int u,int v,int w)
{
    ru.v=v;
    ru.val=w;
    map[u].push_back(ru);
    ru.v=u;
    map[v].push_back(ru);
}

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
        map[i].clear();
        set[i]=i;
    }
}

void init()
{
    memset(vis,0,sizeof(vis));
}

void bfs(int s)
{
    int val,size;
    int i,son,tem;
    queue<int>que;

    init();
    vis[s]=1;
    len[s]=0;
    que.push(s);

    while(!que.empty())
    {
        tem=que.front();
        if(len[tem] > cur_far)
        {
            cur_far=len[tem];
            farid=tem;
        }
        que.pop();
        size=map[tem].size();
        for(i=0;i<size;i++)
        {
            son=map[tem][i].v;
            val=map[tem][i].val;
            if(1 == vis[son])
                continue;
            vis[son]=1;
            len[son]=len[tem]+val;
            que.push(son);
        }        
    }
}

int main()
{
    int ans;
    int u,v,w;
    int i,flag;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        chu();
        flag=1;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            if(0 == flag)
                continue;
            if(find(u) == find(v))
                flag=0;
            else
                merge(find(u),find(v));                            
        }
        if(0 == flag)
        {
            printf("YES\n");
            continue;
        }
        
        far=-1;
        for(i=1;i<=n;i++)
        {
            if(i != set[i])
                continue;
            bfs(i);
            bfs(farid);
            far=max(far,cur_far);
        }
        printf("%d\n",far);
    }
    return 0;
}
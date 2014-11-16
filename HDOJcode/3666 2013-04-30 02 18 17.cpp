******************************
    Author : townboy
    Submit time : 2013-04-30 02:18:17
    Judge Status : Accepted
    HDOJ Runid : 8201990
    Problem id : 3666
    Exe.time : 1140MS
    Exe.memory : 6532K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
#include<iostream>
#include<queue>
#include<memory.h>
#include<vector>
#include<math.h>
#define maxn 900
#define INF 0x7fffffff

using namespace std;

double l,r;
int n,m,end;
int hash[maxn],ru[maxn];
double dis[maxn];

struct node
{
    int v;
    double len;
    node(){}
    node(int _v,double _len):v(_v),len(_len){}
};

vector<node>G[maxn];

void init()
{
    int i;
    end=n+m;
    for(i=0;i<=end;i++)
    {
        G[i].clear();
        dis[i]=INF;
    }
    l=log(l);
    r=log(r);
    memset(hash,0,sizeof(hash));
    memset(ru,0,sizeof(ru));
}

int spfa(int s)
{
    double len;
    int tem,i,size,to;
    queue<int>q;
    q.push(s);
    dis[s]=0;
    while(!q.empty())
    {
        tem=q.front();q.pop();
        hash[tem]=0;
        if(ru[tem] > (int)sqrt((double)end))
            return 0;
        size=G[tem].size();
        for(i=0;i<size;i++)
        {
            to=G[tem][i].v;
            len=G[tem][i].len;
            if(dis[tem]+len < dis[to])
            {
                dis[to]=dis[tem]+len;
                if(1 == hash[to])    continue;
                hash[to]=1;
                ru[to]++;
                q.push(to);
            }
        }
    }
    return 1;
}

void add(int u,int v,double len){
    G[u].push_back(node(v,len));
}

int main()
{
    double tem,ll,rr;
    int ans,i,f;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        scanf("%lf%lf",&l,&r);
        init();
        for(i=0;i<n;i++)
            for(f=0;f<m;f++)
            {
                scanf("%lf",&tem);
                tem=log(tem);
                ll=l-tem;
                rr=r-tem;
                add(f+n,i,rr);
                add(i,f+n,-ll);
            }
        for(i=0;i<end;i++)
            add(end,i,0);
        ans=spfa(end);
        puts(1==ans?"YES":"NO");
    }
    return 0;
}
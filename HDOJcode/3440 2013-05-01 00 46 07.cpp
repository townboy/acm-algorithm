******************************
    Author : townboy
    Submit time : 2013-05-01 00:46:07
    Judge Status : Accepted
    HDOJ Runid : 8208088
    Problem id : 3440
    Exe.time : 640MS
    Exe.memory : 364K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<queue>
#include<vector>
#include<algorithm>
#define maxn 1010

using namespace std;

struct node{
    int v,len;
    node(){}
    node(int _v,int _len):v(_v),len(_len){}
};
vector<node>G[maxn];

int hash[maxn],n,d;
int hei[maxn],ru[maxn];
int dis[maxn],cycle;

void init()
{
    int i;
    for(i=0;i<n;i++)
        G[i].clear();
    memset(hash,-1,sizeof(hash));
    memset(ru,0,sizeof(ru));
    memset(dis,0x3f,sizeof(dis));
    cycle=0;
}

void add(int u,int v,int len){
    G[u].push_back(node(v,len));
}

struct xx{
    int id,hei;
    xx(){}
    xx(int _id,int _hei):id(_id),hei(_hei){}
    friend bool operator < (xx a,xx b){
        return a.hei < b.hei;
    }
};
xx tem[maxn];
    
void yu()
{
    int i;
    for(i=0;i<n;i++)
        tem[i] = xx(i,hei[i]);
    sort(tem,tem+n);
}

void spfa(int s)
{
    int i,tem,size,to,len;
    queue<int>q;
    q.push(s);
    dis[s]=0;
    while(!q.empty())
    {
        tem=q.front();q.pop();
        if(ru[tem] > n)
        {
            cycle=1;
            break;
        }
        hash[tem]=0;
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
                q.push(to);
                ru[to]++;
            }
        }
    }
}

int main()
{
    int s,t;
    int u,v;
    int i,f,cas;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d",&n,&d);
        init();
        for(f=0;f<n;f++)
            scanf("%d",hei+f);
        yu();
        for(f=0;f<n-1;f++)
            add(f+1,f,-1);
        for(f=0;f<n-1;f++)
        {
            u=tem[f].id;
            v=tem[f+1].id;
            if(u < v)
                add(u,v,d);
            else
                add(v,u,d);
        }
        if(tem[0].id < tem[n-1].id)
            s=tem[0].id,t=tem[n-1].id;
        else
            s=tem[n-1].id,t=tem[0].id;
        spfa(s);
        printf("Case %d: %d\n",i+1,1==cycle?-1:dis[t]);
    }
    return 0;
}
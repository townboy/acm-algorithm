******************************
    Author : townboy
    Submit time : 2013-04-29 23:00:56
    Judge Status : Accepted
    HDOJ Runid : 8201337
    Problem id : 1531
    Exe.time : 15MS
    Exe.memory : 292K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<queue>
#include<vector>
#define maxn 110
using namespace std;

struct node
{
    int u,v,len;
    node(){}
    node(int _v,int _len):v(_v),len(_len){}
};
vector<node>G[maxn];

int cycle;
int n,m,ru[maxn];
int hash[maxn];
int dis[maxn];

void init()
{
    int i;
    for(i=0;i<=n+1;i++)
        G[i].clear();
    memset(hash,0,sizeof(hash));
    memset(ru,0,sizeof(ru));
    memset(dis,0x3f,sizeof(dis));
    cycle=0;
}

void add(int u,int v,int len){
    G[u].push_back(node(v,len));
}

void spfa(int s)
{
    int i,size,tem,to,len;
    queue<int>q;
    q.push(s);
    dis[s]=0;
    while(!q.empty())
    {
        tem=q.front();q.pop();
        hash[tem]=0;
        if(ru[tem] > n+1)
        {
            cycle=1;
            break;
        }
        size=G[tem].size();
        for(i=0;i<size;i++)
        {
            to=G[tem][i].v;
            len=G[tem][i].len;
            if(dis[tem]+len < dis[to])
            {
                dis[to]=dis[tem]+len;
                if(1 == hash[to])    continue;
                ru[to]++;
                hash[to]=1;
                q.push(to);
            }
        }
    }
}

int main()
{    
    char ch[10];
    int s,len,c;
    int i;
    while(scanf("%d",&n),n)
    {
        scanf("%d",&m);
        init();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%s%d",&s,&len,ch,&c);
            if(0 == strcmp(ch,"gt"))
                add(s+len,s-1,-c-1);
            else
                add(s-1,s+len,c-1);
        }
        for(i=0;i<=n;i++)
            add(n+1,i,0);
        spfa(n+1);
        puts(1==cycle?"successful conspiracy":"lamentable kingdom");
    }
    return 0;
}
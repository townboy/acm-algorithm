******************************
    Author : townboy
    Submit time : 2013-04-28 21:05:29
    Judge Status : Accepted
    HDOJ Runid : 8193790
    Problem id : 3592
    Exe.time : 31MS
    Exe.memory : 436K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<vector>
#include<queue>
#define maxn 1010
#define INF 0x3f3f3f3f

using namespace std;

struct node {
    int v,len;
    node(){}
    node(int _v,int _len):v(_v),len(_len){}
};
vector<node>G[maxn];

int n,dis[maxn];
int hash[maxn],ru[maxn];

void spfa(int s)
{
    int flag=0;
    int len,to,i,size,tem;
    queue<int>q;
    dis[s]=0;
    q.push(s);
    flag=0;
    while(!q.empty())
    {
        tem=q.front();q.pop();
        if(ru[tem] > n)
        {
            flag=1;
            break;
        }
        size=G[tem].size();
        hash[tem]=0;
        for(i=0;i<size;i++)
        {
            to=G[tem][i].v;
            len=G[tem][i].len;
            if(dis[to] > dis[tem]+len)
            {
                ru[to]++;
                dis[to]=dis[tem]+len;
                if(1 == hash[to])    continue;
                hash[to]=1;
                q.push(to);
            }
        }
    }
    if(1 == flag)
        puts("-1");
    else
        printf("%d\n",INF==dis[n]?-2:dis[n]);
}

void init(){
    int i;
    for(i=0;i<=n;i++)
        G[i].clear();
    memset(hash,0,sizeof(hash));
    memset(dis,0x3f,sizeof(dis));
    memset(ru,0,sizeof(ru));
}

void add(int u,int v,int len){
    G[u].push_back(node(v,len));
}

int main()
{
    int a,b,c;
    int x,y,f;
    int cas,i,ans;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d%d",&n,&x,&y);
        init();
        for(f=n;f>1;f--)
            add(f,f-1,0);
        for(f=0;f<x;f++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(a < b)    add(a,b,c);
            else    add(b,a,c);
        }
        for(f=0;f<y;f++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(a < b)    add(b,a,-c);
            else    add(a,b,-c);
        }
        spfa(1);
    }
    return 0;
}
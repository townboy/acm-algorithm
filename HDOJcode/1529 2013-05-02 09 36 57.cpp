******************************
    Author : townboy
    Submit time : 2013-05-02 09:36:57
    Judge Status : Accepted
    HDOJ Runid : 8215560
    Problem id : 1529
    Exe.time : 46MS
    Exe.memory : 292K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<queue>
#include<vector>
#define maxn 30

using namespace std;

int need[maxn],get[maxn];
int dis[maxn],hash[maxn],ru[maxn];

struct node{
    int v,len;
    node(){}
    node(int _v,int _len):v(_v),len(_len){}
};
vector<node>G[maxn];

void G_init(){
    int i;
    for(i=0;i<25;i++)
        G[i].clear();
    memset(dis,0x3f,sizeof(dis));
    memset(hash,0,sizeof(hash));
    memset(ru,0,sizeof(ru));
}

void add(int u,int v,int len){
    G[u].push_back(node(v,len));
}

int spfa()
{
    int to,i,len,tem,size;
    queue<int>q;
    q.push(23);
    q.push(24);
    while(!q.empty())
    {
        tem=q.front();q.pop();        
        if(ru[tem] > 30)
            return 0;
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
                if(23 == to)    return 0;
                hash[to]=1;
                q.push(to);
                ru[to]++;
            }
        }
    }
    return 1;
}

int check(int sum)
{
    int i;
    G_init();
    add(24,0,get[0]);
    for(i=1;i<24;i++)
        add(i-1,i,get[i]);
    add(0,24,0);
    for(i=1;i<24;i++)
        add(i,i-1,0);    
    for(i=8;i<=23;i++)
        add(i,i-8,-need[i]);
    for(i=0;i<8;i++)
        add(i,i+16,sum-need[i]);
    
    dis[24]=0;
    dis[23]=sum;
    return spfa();
}

void debug()
{
    int i;
    for(i=0;i<25;i++)
        printf("# %d %d\n",i,dis[i]);
}

int main()
{
    int n,cas;
    int i,f,tem;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        for(f=0;f<24;f++)
            scanf("%d",need+f);
        scanf("%d",&n);
        memset(get,0,sizeof(get));
        for(f=0;f<n;f++)
        {
            scanf("%d",&tem);
            get[tem]++;
        }
        for(f=0;f<=n;f++)
        {
            if(1 == check(f))
                break;
        }
        if(f == n+1)
            puts("No Solution");
        else
            printf("%d\n",f);
    }
    return 0;
}
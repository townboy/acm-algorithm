******************************
    Author : townboy
    Submit time : 2013-04-28 15:51:12
    Judge Status : Accepted
    HDOJ Runid : 8191762
    Problem id : 1534
    Exe.time : 15MS
    Exe.memory : 612K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<queue>
#define maxn 10005 

using namespace std;

struct node
{
    int v,len;
    node(){}
    node(int _v,int _len){
        v=_v;    len=_len;
    }
};

int n,nn,dis[maxn],hash[maxn];
int t[maxn],ru[maxn];
int flag;
vector<node>G[maxn];

void init()
{
    int i;
    nn=2*n;
    flag=0;
    for(i=0;i<nn;i++)
        G[i].clear();
    memset(dis,0x80,sizeof(dis));
    memset(ru,0,sizeof(ru));
    memset(hash,0,sizeof(hash));
}

void add(int u,int v,int len){
    G[u].push_back(node(v,len));
}
    
void spfa(int s)
{
    int len;
    int i,size,tem,to;
    queue<int>q;
    ru[s]++;
    q.push(s);
    dis[s]=0;
    while(!q.empty())
    {
        tem=q.front();
        q.pop();
        if(ru[tem] > nn)
        {
            flag=1;
            break;
        }
        hash[tem]=0;
        size=G[tem].size();
        for(i=0;i<size;i++)
        {
            len=G[tem][i].len;
            to=G[tem][i].v;
            if(dis[tem]+len > dis[to])
            {
                ru[to]++;
                dis[to]=dis[tem]+len;
                if(1 == hash[to])    continue;
                hash[to]=1;
                q.push(to);
            }
        }
    }
}    

void ans()
{
    int i;
    if(1 == flag)
    {
        puts("impossible\n");
        return ;
    }
    for(i=0;i<n;i++)
        printf("%d %d\n",i+1,dis[2*i]);
    printf("\n");
}

int main()
{
    char ch[10];
    int u,v,len;
    int i,cas=0;
    while(scanf("%d",&n),n)
    {
        cas++;
        init();
        for(i=0;i<n;i++)
            scanf("%d",t+i);
        for(i=0;i<n;i++)
        {
            add(2*i,2*i+1,t[i]);
            add(2*i+1,2*i,-t[i]);
        }
        while(scanf("%s",ch)!=EOF)
        {
            if('#' == ch[0])    break;
            scanf("%d%d",&u,&v);
            u--;v--;
            if(0 == strcmp(ch,"FAS"))
                add(2*v,2*u+1,0);
            else if(0 == strcmp(ch,"FAF"))
                add(2*v+1,2*u+1,0);
            else if(0 == strcmp(ch,"SAF"))
                add(2*v+1,2*u,0);
            else
                add(2*v,2*u,0);
        }
        for(i=0;i<nn;i++)
            add(nn,i,0);
        spfa(nn);
        printf("Case %d:\n",cas);
        ans();
    }
    return 0;
}
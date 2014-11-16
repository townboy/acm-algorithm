******************************
    Author : townboy
    Submit time : 2013-01-23 15:00:45
    Judge Status : Accepted
    HDOJ Runid : 7535052
    Problem id : 3313
    Exe.time : 687MS
    Exe.memory : 3212K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<vector>
#include<iostream>
#include<queue>

using namespace std;

int path[100010],ji;
int s,t,from[100000],hash[100000];
int n,m,id[100000];
int first[100000],next[310000],to[310000];
int bian;

void add(int u,int v)
{
    to[bian]=v;
    next[bian]=first[u];
    first[u]=bian;
    bian++;    
}

int bfs()
{
    int tem,i,size;
    queue<int>que;

    que.push(s);
    memset(hash,0,sizeof(hash));
    hash[s]=1;

    while(!que.empty())
    {
        tem=que.front();    
        que.pop();
        for(i=first[tem];i!=-1;i=next[i])
        {
            if(1 == hash[to[i]])
                continue;
            from[to[i]]=tem;
            hash[to[i]]=1;
            que.push(to[i]);    
        }
        if(1 == hash[t])
            break;
    }    
    if(0 == hash[t])
         return 1;

    memset(id,0,sizeof(id));
    tem=t;
    ji=1;
    while(tem != s)
    {
        path[ji]=tem;
        id[tem]=ji;
        tem=from[tem];
        ji++;    
    }
    path[ji]=tem;
    id[tem]=ji;
    return 0;
}

void chu()
{
    bian=0;
    memset(first,-1,sizeof(first));
}

inline void in(int &num){
     char in=getchar();
     while(in<'0'||in>'9'){
           in=getchar();
     }
     num=in-'0';
     in=getchar();
     while(in>='0'&&in<='9'){
           num*=10; num+=in-'0';
           in=getchar();
     }
}

int fun()
{
    int minn=ji,size,maxx=ji;
    int i,sum=0,tem;
    queue<int>que;

    memset(hash,0,sizeof(hash));

    while(0 == hash[t])
    {
        sum++;
        for(i=maxx;i>=minn;i--)
        {
            que.push(path[i]);
            hash[path[i]]=1;
           }
           maxx=minn-1;
           
        while(!que.empty())
        {
            tem=que.front();
            que.pop();
            for(i=first[tem];i!=-1;i=next[i])
            {
                if(1 == hash[to[i]])
                    continue;
                if(id[to[i]] != 0)
                    minn=min(minn,id[to[i]]);
                else
                {
                    hash[to[i]]=1;
                    que.push(to[i]);
                }            
            }
        }
    }
    return sum;
}

int main()
{
    int i,u,v;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        chu();
        for(i=0;i<m;i++)
        {
            in(u);
            in(v);
            add(u,v);
        }
        scanf("%d%d",&s,&t);
        if(1 == bfs())
        {
            printf("%d\n",n);
            continue;    
        }
        printf("%d\n",fun());
    }    
    return 0;
}
******************************
    Author : townboy
    Submit time : 2013-01-24 18:38:59
    Judge Status : Accepted
    HDOJ Runid : 7541141
    Problem id : 3665
    Exe.time : 15MS
    Exe.memory : 244K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<queue>

using namespace std;

int n;
int map[15][15];
int oversea[15],hash[15];

void chu()
{
    memset(map,-1,sizeof(map));
}

struct node
{
    int id;
    int val;
    friend bool operator < (node a,node b)
    {    
        return a.val > b.val;
    }
};
struct node tem,ru;

int bfs()
{
    int to;
    priority_queue<node>que;
    
    ru.id=0;
    ru.val=0;
    que.push(ru);
    
    memset(hash,0,sizeof(hash));
    while(!que.empty())
    {
        tem=que.top();
        que.pop();
        if(1 == hash[tem.id])
            continue;
        hash[tem.id]=1;        
        if(1 == oversea[tem.id])
            return tem.val;
        for(to=0;to<n;to++)
        {
            if(-1 == map[tem.id][to])
                continue;
            ru.val=tem.val+map[tem.id][to];
            ru.id=to;
            que.push(ru);
        }    
    }    
    return -1;    
}

int main()
{
    int m,p,f;
    int i,len,t;
    while(scanf("%d",&n)!=EOF)
    {
        chu();
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&m,&oversea[i]);    
            for(f=0;f<m;f++)
            {
                scanf("%d%d",&t,&len);
                map[i][t]=len;
            }
        }    
        printf("%d\n",bfs());
    }
    return 0;
}
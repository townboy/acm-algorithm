******************************
    Author : townboy
    Submit time : 2012-03-23 22:24:55
    Judge Status : Accepted
    HDOJ Runid : 5618763
    Problem id : 2544
    Exe.time : 15MS
    Exe.memory : 344K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

int map[150][150],hash[200],m,n;

void chu(int n)
{
    int i,f;
    for(i=0;i<=n;i++)
    {
        hash[i]=0;
        for(f=0;f<=n;f++)
        { 
            map[i][f]=-1;
        }
    }
}

struct node 
{
    int num;
    int d;
    friend bool operator < (node a,node b)
    {
        return a.d>b.d;
    }
};

struct node ru,tem;

int bfs()
{
    int i;
    priority_queue<node>q;
    ru.num=1;
    ru.d=0;
    q.push(ru);
    while(!q.empty())
    {
        tem=q.top();
        q.pop();
        if(n==tem.num)
        {
            return tem.d;
        }
        if(1==hash[tem.num])
        {
            continue;
        }
        hash[tem.num]=1;
        for(i=1;i<=n;i++)
        {
            if(1==hash[i])
            {
                continue;
            }
            if(-1==map[tem.num][i])
            {
               continue;
            }
            ru.num=i;
            ru.d=tem.d+map[tem.num][i];
            q.push(ru);
        }
    }
    return -1;
}

int main()
{
    int i,a,b,x;
    while(scanf("%d%d",&n,&m),!(0==n&&0==m))
    {
        chu(n);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&x);
            if(-1==map[a][b]||x<map[a][b])
            {
                map[a][b]=x;
                map[b][a]=x;
            }
        }
        printf("%d\n",bfs());
    }
    return 0;
}
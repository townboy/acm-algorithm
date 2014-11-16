******************************
    Author : townboy
    Submit time : 2012-03-23 21:48:25
    Judge Status : Accepted
    HDOJ Runid : 5618428
    Problem id : 1874
    Exe.time : 0MS
    Exe.memory : 364K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;

int map[300][300],s,t,n,m,hash[300];

struct node 
{
    int num;
    int d;
    friend bool operator < (node a,node b)
    {
        return a.d>b.d;
    }
};

struct node tem,ru;

void chu(int n)
{
    int i,f;
    for(i=0;i<n;i++)
    {
        hash[i]=0;
        for(f=0;f<n;f++)
        {
            map[i][f]=-1;
        }
    }
}

int bfs()
{
    int i;
    priority_queue<node>q;
    ru.d=0;
    ru.num=s;
    q.push(ru);
    while(!q.empty())
    {
        tem=q.top();
        q.pop();
        if(1==hash[tem.num])
        {
            continue;
        }
        if(t==tem.num)
        {
            return tem.d;
        }
        hash[tem.num]=1;
        for(i=0;i<n;i++)
        {
            if(-1==map[tem.num][i])
            {
                continue;
            }
            if(1==hash[i])
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
    int i,x,y,d,res;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        chu(n);

        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&d);
            if(-1==map[x][y])
            {
                map[x][y]=d;
                map[y][x]=d;
            }
            else if(d<map[x][y])
            {
                map[x][y]=d;
                map[y][x]=d;
            }
        }
        scanf("%d%d",&s,&t);

        res=bfs();
        printf("%d\n",res);
    }
    return 0;
}
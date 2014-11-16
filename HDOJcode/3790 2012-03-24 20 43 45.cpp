******************************
    Author : townboy
    Submit time : 2012-03-24 20:43:45
    Judge Status : Accepted
    HDOJ Runid : 5627258
    Problem id : 3790
    Exe.time : 125MS
    Exe.memory : 8220K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

int hash[1200],map[1010][1010],d,p,s,t,m,n,fei[1010][1010],val[1200];

struct node 
{
    int num;
    int d;
    int p;
    friend bool operator < (node a,node b)
    {
        if(a.d>b.d)
        {
            return true; 
        }
        if(a.d<b.d)
        {
            return false;
        }
        if(a.p>b.p)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

node ru,tem;

void bfs()
{
    priority_queue<node>q;
    ru.num=s;
    ru.d=0;
    ru.p=0;
    val[s]=0;
    q.push(ru);
    while(!q.empty())
    {
        tem=q.top();
        q.pop();
        if(t==tem.num)
        {
             d=tem.d;
             p=tem.p;
             return ;
        }
        if(1==hash[tem.num])
        {
            continue;
        }
        hash[tem.num]=1;
        for(int i=1;i<=n;i++)
        {
            if(-1==map[tem.num][i])
            {
                continue;
            }
            if(1==hash[i])
            {
                continue;
            }
            if(tem.d+map[tem.num][i]<=val[i])
            {
                val[i]=tem.d+map[tem.num][i];
            }
            else
            {
                continue;
            }
            ru.d=tem.d+map[tem.num][i];
            ru.p=tem.p+fei[tem.num][i];
            ru.num=i;
            q.push(ru);
        }
    }
}

void chu(int n)
{
    for(int i=1;i<=n;i++)
    {
        hash[i]=0;
        val[i]=2000000000;
        for(int f=1;f<=n;f++)
        {
            map[i][f]=-1;
        }
    }
}

int main()
{
    while(scanf("%d%d",&n,&m),!(0==n&&0==m))
    {
        chu(n);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&s,&t,&d,&p);
            if(-1==map[s][t]||d<map[s][t])
            {
                map[s][t]=d;
                map[t][s]=d;
                fei[s][t]=p;
                fei[t][s]=p;
            }
        }
        scanf("%d%d",&s,&t);
        bfs();
        printf("%d %d\n",d,p);
    }
    return 0;
}
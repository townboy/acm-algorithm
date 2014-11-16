******************************
    Author : townboy
    Submit time : 2012-03-31 21:49:56
    Judge Status : Accepted
    HDOJ Runid : 5681183
    Problem id : 1596
    Exe.time : 1000MS
    Exe.memory : 6872K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<queue>
#include<iostream>
using namespace std;

double map[1010][1010],val[1010];
int e,s,n,hash[1010];

struct node 
{
    int num;
    double d;
    friend bool operator < (node a,node b)
    {
        return  a.d<b.d;
    }
};
node ru,tem;

double bfs()
{
    int i;
    priority_queue<node> q;
    ru.num=s;
    ru.d=1;
    val[s]=1;
    q.push(ru);
    while(!q.empty())
    {
        tem=q.top();
        q.pop();
        if(e==tem.num)
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
            if(tem.d*map[tem.num][i]<=val[i])
            {
                continue;
            }
            val[i]=tem.d*map[tem.num][i];
            ru.num=i;
            ru.d=val[i];
            q.push(ru);
        }
    }
    return 0;
}

void chu()
{
    int i;
    for(i=1;i<=1005;i++)
    {
        val[i]=0;
    }
    memset(hash,0,sizeof(hash)); 
}

int main()
{
    int i,k,f;
    double res;
//    freopen("C:\\Documents and Settings\\hduacm\\×ÀÃæ\\in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=n;f++)
            {
                scanf("%lf",&map[i][f]);
            }
        }
        scanf("%d",&k);
        for(i=0;i<k;i++)
        {
            chu();      
            scanf("%d%d",&s,&e);
            res=bfs();
            if(0==res)
            {
                printf("What a pity!\n");
            }
            else
            {
                printf("%.3lf\n",res);
            }
        }
    }
    return 0;
}
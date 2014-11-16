******************************
    Author : townboy
    Submit time : 2012-07-30 14:51:12
    Judge Status : Accepted
    HDOJ Runid : 6376705
    Problem id : 1385
    Exe.time : 31MS
    Exe.memory : 348K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#define INF 0x7fffffff
#include<queue>
using namespace std;

int map[505][505],n;
int tax[505],s,t,pre[505],val[505];

void print()
{
    int x=t;
    printf("From %d to %d :\n",t,s);
    printf("Path: %d",t);
    while(x != s)
    {
        x=pre[x];
        printf("-->%d",x);
    }
    printf("\n");
    if(s == t)
    {
        printf("Total cost : 0\n\n");
        return ;
    }
    printf("Total cost : %d\n\n",val[t]-tax[t]);
}

void spfa()
{
    int xin,tem,i,hash[505];
    queue<int>q;
    memset(hash,0,sizeof(hash));
    q.push(s);
    val[s]=0;
    pre[s]=s;
    while(!q.empty())
    {
        tem=q.front();
        q.pop();
        hash[tem]=0;
        for(i=1;i<=n;i++)
        {
            if(-1 == map[tem][i])
            {
                continue;
            }
            xin=val[tem]+map[tem][i]+tax[i];
            if(val[i] > xin || (xin == val[i] && tem < pre[i]))
            {
                val[i] = xin;
                pre[i]=tem;
                if(0 == hash[i])
                {
                    hash[i]=1;
                    q.push(i);
                }
            }        
        }
    }
    print();
}

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        val[i]=INF;
        pre[i]=INF;
    }
}

int main()
{
    int i,f;
    while(scanf("%d",&n),n)
    {
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=n;f++)
            {
                scanf("%d",&map[f][i]);
            }
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&tax[i]);
        }
        
        while(scanf("%d%d",&t,&s),-2 != s+t)
        {
            chu();
            spfa();    
        }
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-09-17 15:38:12
    Judge Status : Accepted
    HDOJ Runid : 6781663
    Problem id : 1598
    Exe.time : 171MS
    Exe.memory : 256K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#define INF 0x7fffffff

int s,t,n,m,set[210];

struct node 
{
    int u;
    int v;
    int speed;
};
struct node que[1100];

int cmp(const void *a,const void*b)
{
    return (*(struct node *)b).speed-(*(struct node *)a).speed;
}

void merge(int x,int y)
{
    set[x]=y;
}

int find(int x)
{
    return x==set[x]?x:set[x]=find(set[x]);
}

int minn(int a,int b)
{
    return a<b?a:b;
}

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        set[i]=i;
    }
}

int check()
{
    if(find(s) == find(t))
    {
        return 1;
    }
    return 0;
}

int solve()
{
    int f,i,ans=INF;
    for(i=0;i<m;i++)
    {
        chu();
        for(f=i;f<m;f++)
        {
            merge(find(que[f].u),find(que[f].v));
            if(1 == check())
            {
                ans=minn(ans,que[i].speed-que[f].speed);
                break;
            }
        }
        if(f == m)
        {
            if(INF == ans)
            {    
                return -1;
            }
            return ans;
        }
    }
}

int main()
{
    int i,q;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&que[i].u,&que[i].v,&que[i].speed);
        }
        qsort(que,m,sizeof(que[0]),cmp);
        scanf("%d",&q);
        for(i=0;i<q;i++)
        {
            scanf("%d%d",&s,&t);
            printf("%d\n",solve());
        }        
    }
    return 0;
}
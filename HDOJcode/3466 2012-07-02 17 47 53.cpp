******************************
    Author : townboy
    Submit time : 2012-07-02 17:47:53
    Judge Status : Accepted
    HDOJ Runid : 6118340
    Problem id : 3466
    Exe.time : 78MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

struct node 
{
    int p;
    int q;
    int v;
};
struct node que[600];

int dp[6000],n,m;

int cmp(const void*a,const void*b)
{
    return ((*(struct node *)a).q-(*(struct node *)a).p)-((*(struct node *)b).q-(*(struct node *)b).p);
}

int maxx(int a,int b)
{
    return a>b?a:b;
}

void mul(int p,int q,int v)
{
    int i;
    for(i=m;i>=q;i--)
    {
        dp[i]=maxx(dp[i],dp[i-p]+v);
    }
}

void chu()
{
    memset(dp,0,sizeof(dp));
}

int main()
{
    int i;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        chu();
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&que[i].p,&que[i].q,&que[i].v);
        }
        qsort(que,n,sizeof(que[0]),cmp);
        for(i=0;i<n;i++)
        {
            mul(que[i].p,que[i].q,que[i].v);        
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}
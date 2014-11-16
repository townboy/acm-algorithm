******************************
    Author : townboy
    Submit time : 2012-07-02 01:41:47
    Judge Status : Accepted
    HDOJ Runid : 6115375
    Problem id : 3033
    Exe.time : 93MS
    Exe.memory : 1072K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define INF  -999999999
int n,m,k,dp[15][15000];

int maxx(int a,int b)
{
    return a>b?a:b;
}

struct node 
{
    int id;
    int c;
    int w;
};

struct node que[150];

int cmp(const void*a,const void*b)
{
    return (*(struct node *)a).id-(*(struct node *)b).id;
}

void mul(int num,int c,int w)
{
    int i;
    for(i=m;i>=c;i--)
    {
        dp[num][i]=maxx(dp[num][i],maxx(dp[num][i-c],dp[num-1][i-c])+w);
    }
}

void chu()
{
    int i,f;
    memset(dp,0,sizeof(dp));
    for(i=1;i<=k;i++)
    {
        for(f=0;f<=m;f++)
        {
            dp[i][f]=INF;
        }
    }    
}

int main()
{
    int i;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&que[i].id,&que[i].c,&que[i].w);
        }
        chu();
        qsort(que,n,sizeof(que[0]),cmp);
        for(i=0;i<n;i++)
        {
            mul(que[i].id,que[i].c,que[i].w);
        }
        if(0 > dp[k][m])
        {
            printf("Impossible\n");
            continue;
        }
        printf("%d\n",dp[k][m]);
    }
    return 0;
}
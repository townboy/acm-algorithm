******************************
    Author : townboy
    Submit time : 2012-07-02 02:28:57
    Judge Status : Accepted
    HDOJ Runid : 6115401
    Problem id : 3496
    Exe.time : 46MS
    Exe.memory : 668K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define INF -999999999

int maxx(int a,int b)
{
    return a>b?a:b;
}

struct node 
{
    int c;
    int w;
};
struct node que[150];
int dp[110][1100],m,l,n;

void mul(int c,int w)
{
    int i,f;
    for(i=m;i>=1;i--)
    {
        for(f=l;f>=c;f--)
        {
            dp[i][f]=maxx(dp[i][f],dp[i-1][f-c]+w);
        }
    }
}

void chu()
{
    int i,f;
    memset(dp,0,sizeof(dp));
    for(i=1;i<=m;i++)
    {
        for(f=0;f<=l;f++)
        {
            dp[i][f]=INF;
        }
    }
}

int main()
{
    int i,f,num;
//    freopen("D:\\in.txt","r",stdin);
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d%d",&n,&m,&l);
        chu();
        for(f=0;f<n;f++)
        {
            scanf("%d%d",&que[f].c,&que[f].w);
        }
        for(f=0;f<n;f++)
        {
            mul(que[f].c,que[f].w);
        }
        if(dp[m][l] < 0)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n",dp[m][l]);
    }
    return 0;
}
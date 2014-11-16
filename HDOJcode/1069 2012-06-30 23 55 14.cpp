******************************
    Author : townboy
    Submit time : 2012-06-30 23:55:14
    Judge Status : Accepted
    HDOJ Runid : 6111980
    Problem id : 1069
    Exe.time : 0MS
    Exe.memory : 196K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int x;
    int y;
    int z;
};
struct node que[1000];
int a[3],maxx,dp[1100],n;

int cmp(const void*a,const void*b)
{
    return (*(struct node*)a).x*(*(struct node*)a).y-(*(struct node*)b).x*(*(struct node*)b).y;
}

int cmpp(const void*a,const void*b)
{
    return *(int*)a-*(int *)b;
}

void zao(int x)
{
    que[3*x].x=a[0];
    que[3*x].y=a[1];
    que[3*x].z=a[2];

    que[3*x+1].x=a[0];
    que[3*x+1].y=a[2];
    que[3*x+1].z=a[1];
    
    que[3*x+2].x=a[1];
    que[3*x+2].y=a[2];
    que[3*x+2].z=a[0];
}    

int check(int i,int f)
{
    if(que[i].x>que[f].x && que[i].y>que[f].y)
    {
        return 1;
    }
    return 0;
}

void chu()
{
    int i;
    for(i=0;i<3*n;i++)
    {
        dp[i]=que[i].z;
    }
    maxx=0;
}

int main()
{
    int i,f,ji=0;
    while(scanf("%d",&n),n)
    {
        ji++;
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&a[0],&a[1],&a[2]);
            qsort(a,3,sizeof(a[0]),cmpp);
            zao(i);
        }
        qsort(que,3*n,sizeof(que[0]),cmp);
        chu();
        for(i=0;i<3*n;i++)
        {
            for(f=0;f<i;f++)
            {
                if(0 == check(i,f))
                {
                    continue;
                }
                if(dp[f]+que[i].z > dp[i])
                {
                    dp[i]=dp[f]+que[i].z;
                }
            }
            if(dp[i] > maxx)
            {
                maxx=dp[i];
            }
        }
        printf("Case %d: maximum height = %d\n",ji,maxx);
    }    
    return 0;
}
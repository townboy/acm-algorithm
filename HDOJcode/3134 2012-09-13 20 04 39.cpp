******************************
    Author : townboy
    Submit time : 2012-09-13 20:04:39
    Judge Status : Accepted
    HDOJ Runid : 6759544
    Problem id : 3134
    Exe.time : 0MS
    Exe.memory : 256K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
using namespace std;

struct node 
{
    int len[3];
    int sum;
};
struct node que[510];
int dp[510],n;

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int cmp2(const void *a,const void*b)
{
    return (*(struct node *)a).sum-(*(struct node *)b).sum;
}

void chu()
{
    int i;
    for(i=0;i<n;i++)
    {
        dp[i]=1;
    }
}

int check(int a,int b)
{
    int i;
    for(i=0;i<3;i++)
    {
        if(que[a].len[i] <= que[b].len[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int ans,i,f; 
    while(scanf("%d",&n),-1 != n)
    {
        chu();
        for(i=0;i<n;i++)
        {
            scanf("%d x %d x %d",&que[i].len[0],&que[i].len[1],&que[i].len[2]);    
            que[i].sum=que[i].len[0]*que[i].len[1]*que[i].len[2];
            qsort(que[i].len,3,sizeof(que[i].len[0]),cmp);
        }
        qsort(que,n,sizeof(que[0]),cmp2);
        ans=-1;    
        for(i=1;i<n;i++)
        {
            for(f=0;f<i;f++)
            {    
                if(1 == check(i,f))
                {
                    dp[i]=max(dp[i],dp[f]+1);            
                }
            }
            if(dp[i] > ans)
            {
                ans=dp[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
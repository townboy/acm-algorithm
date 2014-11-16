******************************
    Author : townboy
    Submit time : 2012-07-26 23:31:21
    Judge Status : Accepted
    HDOJ Runid : 6343357
    Problem id : 4310
    Exe.time : 0MS
    Exe.memory : 256K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int dps;
    int hp;
    double x;
};
struct node que[30];

int cmp(const void*a,const void*b)
{    
    if((*(struct node *)b).x-(*(struct node *)a).x > 0)
    {
        return 1;
    }     
    return -1;
}

int main()
{
    int sum,ans,i,n;
    while(scanf("%d",&n)!=EOF)
    {
        ans=0;
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&que[i].dps,&que[i].hp);
            que[i].x=(double)que[i].dps/que[i].hp;
            sum+=que[i].dps;    
        }
        qsort(que,n,sizeof(que[0]),cmp);
        for(i=0;i<n;i++)
        {
            ans+=sum*que[i].hp;
            sum-=que[i].dps;        
        }
        printf("%d\n",ans);
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-06-30 22:24:33
    Judge Status : Accepted
    HDOJ Runid : 6111786
    Problem id : 1160
    Exe.time : 15MS
    Exe.memory : 216K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>

int root[1100],dp[1100],pr[1100];

struct node 
{
    int id;
    int w;
    int v;
};
struct node que[1100];

int cmp(const void*a,const void*b)
{
    return (*(struct node *)a).w-(*(struct node *)b).w;
}

void chu()
{
    int i;
    for(i=0;i<1050;i++)
    {
        dp[i]=1;
        root[i]=i;
    }
}

int main()
{
    int maxx=0,f;
    int ji=0,i;
    while(scanf("%d",&que[ji].w)!=EOF)
    {
        scanf("%d",&que[ji].v);
        que[ji].id=ji+1;
        ji++;
    }    
    qsort(que,ji,sizeof(que[0]),cmp);
    chu();
    for(i=1;i<ji;i++)
    {
        for(f=0;f<i;f++)
        {
            if(que[f].w == que[i].w)
            {
                continue;
            }
            if(que[f].v <= que[i].v)
            {
                continue;    
            }            
            if(dp[f]+1 > dp[i])
            {
                root[i]=f;
                dp[i]=dp[f]+1;
            }
            if(dp[i] > dp[maxx])
            {
                maxx=i;
            }
        }    
    }
    printf("%d\n",dp[maxx]);
    ji=0;
    pr[ji]=que[maxx].id;
    ji++;
    while(maxx != root[maxx])
    {
        maxx=root[maxx];
        pr[ji]=que[maxx].id;
        ji++;
    }
    for(i=ji-1;i>-1;i--)
    {
        printf("%d\n",pr[i]);
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-09-13 14:32:50
    Judge Status : Accepted
    HDOJ Runid : 6756766
    Problem id : 1518
    Exe.time : 1531MS
    Exe.memory : 240K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

int ave,que[25],n;
int ci,hash[25],flag;

int cmp(const void *a,const void*b)
{
    return -*(int *)a+*(int *)b;
}

void dfs(int s,int wei)
{
    if(1 == flag)
    {
        return ;
    }
    if(ci == 4)
    {
        flag=1;
        return ;
    }
    if(s == ave)
    {
        ci++;
        dfs(0,1);
        ci--;
    }
    if(n+1 == wei)
    {
        return ;    
    }
    if(0 == hash[wei] && ave >= s+que[wei])
    {
        hash[wei]=1;
        dfs(s+que[wei],wei+1);    
        hash[wei]=0;
    }
    dfs(s,wei+1);
}

void chu()
{
    memset(hash,0,sizeof(hash));
}

void debug()
{
    int i;
    for(i=1;i<=n;i++)
    {
        printf("%d ",que[i]);
    }
    printf("\n");
}

int main()
{
    int num,i,f,sum;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        sum=0;
        chu();
        for(f=1;f<=n;f++)
        {
            scanf("%d",&que[f]);
            sum+=que[f];
        }
        qsort(&que[1],n,sizeof(que[0]),cmp);
        if(0 != sum%4)
        {
            printf("no\n");
            continue;
        }        
        ave=sum/4;
        ci=0;
        flag=0;
        dfs(0,1);                
        if(1 == flag)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}
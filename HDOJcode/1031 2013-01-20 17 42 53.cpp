******************************
    Author : townboy
    Submit time : 2013-01-20 17:42:53
    Judge Status : Accepted
    HDOJ Runid : 7521304
    Problem id : 1031
    Exe.time : 78MS
    Exe.memory : 296K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

int n,m,k;

struct node
{
    int num;
    double sum;
};
struct node que[1100];

int cmp1(const void *a,const void *b)
{
    if( (*(struct node *)a).sum > (*(struct node *)b).sum)
        return -1;    
    else
        return 1;
}

int cmp2(const void *a,const void *b)
{
    if( (*(struct node *)a).num > (*(struct node *)b).num)
        return -1;
    else
        return 1;    
}

int main()
{
    double tem;
    int i,f;

    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        for(i=0;i<m;i++)
        {
            que[i].sum=0;
            que[i].num=i;
        }
    
        for(i=1;i<=n;i++)
            for(f=0;f<m;f++)
            {
                scanf("%lf",&tem);
                que[f].sum+=tem;        
            }
            
        qsort(que,m,sizeof(que[0]),cmp1);        
        qsort(que,k,sizeof(que[0]),cmp2);

        printf("%d",que[0].num+1);
        for(i=1;i<k;i++)
            printf(" %d",que[i].num+1);    
        printf("\n");
    }
    return 0;    
}
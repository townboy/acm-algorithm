******************************
    Author : townboy
    Submit time : 2012-04-13 21:40:54
    Judge Status : Accepted
    HDOJ Runid : 5768886
    Problem id : 2673
    Exe.time : 62MS
    Exe.memory : 256K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>

int zan[11000];
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int head,tail,n,i;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&zan[i]);
        }
        qsort(zan,n,sizeof(zan[0]),cmp);
        head=0;
        tail=n-1;
        printf("%d",zan[tail--]);
        while(tail!=head-1)
        {
            printf(" %d",zan[head++]);
            if(head!=tail+1)
            {
                printf(" %d",zan[tail--]);
            }
        }
        printf("\n");
    }
    return 0;
}
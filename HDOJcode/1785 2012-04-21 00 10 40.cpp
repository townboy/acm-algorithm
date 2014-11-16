******************************
    Author : townboy
    Submit time : 2012-04-21 00:10:40
    Judge Status : Accepted
    HDOJ Runid : 5813950
    Problem id : 1785
    Exe.time : 0MS
    Exe.memory : 212K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>


struct node 
{
    double x;
    double y;
};
struct node q[110];

int cmp(const void *a,const void *b)
{
    if(((*(struct node *)a).x*(*(struct node *)b).y-(*(struct node *)b).x*(*(struct node *)a).y)>0)
    {
        return -1;
    }
    return 1;
}

int main()
{
    int n,i;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%d",&n),n>=0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf",&q[i].x,&q[i].y);
        }

        qsort(q,n,sizeof(q[0]),cmp);

        for(i=0;i<n;i++)
        {
            if(0!=i)
            {
                printf(" ");
            }
            printf("%.1lf %.1lf",q[i].x,q[i].y);
        }
        printf("\n");
    }
    return 0;
}
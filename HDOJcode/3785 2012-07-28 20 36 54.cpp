******************************
    Author : townboy
    Submit time : 2012-07-28 20:36:54
    Judge Status : Accepted
    HDOJ Runid : 6365333
    Problem id : 3785
    Exe.time : 328MS
    Exe.memory : 628K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>

int que[110000];

int cmp(const void*a,const void*b)
{
    return *(int *)b-*(int *)a;
}

int minn(int a,int b)
{
    return a<b?a:b;
}

int main()
{
    int i,n,m;
    while(scanf("%d%d",&n,&m),n+m)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&que[i]);
        }
        qsort(que,n,sizeof(que[0]),cmp);
        for(i=0;i<minn(n,m);i++)
        {
            if(0 != i)
                printf(" ");
            printf("%d",que[i]);
        }
        printf("\n");
    }
    return 0;
}
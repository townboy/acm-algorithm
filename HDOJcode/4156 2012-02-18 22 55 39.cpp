******************************
    Author : townboy
    Submit time : 2012-02-18 22:55:39
    Judge Status : Accepted
    HDOJ Runid : 5375308
    Problem id : 4156
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int a[3];
    while(scanf("%d%d%d",&a[0],&a[1],&a[2]),a[0]+a[1]+a[2])
    {
        qsort(a,3,sizeof(a[0]),cmp);
        if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2])
        {
            printf("right\n");
        }
        else
        {
            printf("wrong\n");
        }
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2011-12-04 23:42:49
    Judge Status : Accepted
    HDOJ Runid : 5114097
    Problem id : 2561
    Exe.time : 0MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int main(void)
{
    int a[300],num,i,f,n;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        for(f=0;f<n;f++)
        {
            scanf("%d",&a[f]);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("%d\n",a[1]);
    }
    return 0;
} 

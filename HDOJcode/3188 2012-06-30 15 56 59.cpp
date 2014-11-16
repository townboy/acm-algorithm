******************************
    Author : townboy
    Submit time : 2012-06-30 15:56:59
    Judge Status : Accepted
    HDOJ Runid : 6110659
    Problem id : 3188
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int num,i,a[3],f;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        qsort(a,3,sizeof(a[0]),cmp);
        if(a[0] == a[1]||a[1] == a[2])
        {
            printf("perfect\n");
            continue;
        }
        for(f=0;f<3;f++)
        {
            a[f]*=a[f];
        }
        if(a[0]+a[1] == a[2])
        {
            printf("good\n");
            continue;
        }
        printf("just a triangle\n");
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-06-26 00:10:17
    Judge Status : Accepted
    HDOJ Runid : 6099094
    Problem id : 1157
    Exe.time : 0MS
    Exe.memory : 272K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{    
    return *(int *)a-*(int *)b;
}

int que[11000];

int main()
{
    int num,i;
    while(scanf("%d",&num)!=EOF)
    {
        for(i=0;i<num;i++)
        {
            scanf("%d",&que[i]);
        }
        qsort(que,num,sizeof(que[0]),cmp);
        printf("%d\n",que[num/2]);
    }
    return 0;
}
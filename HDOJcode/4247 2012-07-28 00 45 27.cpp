******************************
    Author : townboy
    Submit time : 2012-07-28 00:45:27
    Judge Status : Accepted
    HDOJ Runid : 6357203
    Problem id : 4247
    Exe.time : 15MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>

int cmp(const void*a,const void*b)
{
    return *(int*)b-*(int*)a;
}

int main()
{
    int que[4],ji=0;
    while(scanf("%d%d%d%d",&que[0],&que[1],&que[2],&que[3])!=EOF)
    {
        ji++;
        qsort(que,4,sizeof(que[0]),cmp);
        printf("Case %d: %d\n",ji,que[0]+que[1]);
    }
    return 0;
}

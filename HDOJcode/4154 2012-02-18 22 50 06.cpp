******************************
    Author : townboy
    Submit time : 2012-02-18 22:50:06
    Judge Status : Accepted
    HDOJ Runid : 5375286
    Problem id : 4154
    Exe.time : 0MS
    Exe.memory : 204K
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
    int que[5000],i,flag,num;
    while(scanf("%d",&num),num)
    {
        flag=0;
        for(i=0;i<num;i++)
        {
            scanf("%d",&que[i]);
        }
        qsort(que,num,sizeof(que[0]),cmp);
        for(i=0;i<num-1;i++)
        {
            if(que[i+1]-que[i]>200)
            {
                printf("IMPOSSIBLE\n");
                flag=1;
                break;
            }
        } 
        if(0==flag)
        {
            if(1422-que[num-1]>100)
            {
                printf("IMPOSSIBLE\n");
            }
            else
            {
                printf("POSSIBLE\n");
            }
        }
    }
    return 0;
}
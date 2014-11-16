******************************
    Author : townboy
    Submit time : 2012-07-10 16:33:06
    Judge Status : Accepted
    HDOJ Runid : 6171222
    Problem id : 3177
    Exe.time : 0MS
    Exe.memory : 196K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int a;
    int b;
};
struct node que[1100];

int cmp(const void *a,const void *b)
{
    return ((*(struct node *)b).b-(*(struct node *)b).a)-((*(struct node *)a).b-(*(struct node *)a).a); 
}

int main()
{
    int num,i,f,v,k;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {    
        scanf("%d%d",&v,&k);
        for(f=0;f<k;f++)
        {
            scanf("%d%d",&que[f].a,&que[f].b);
        }
        qsort(que,k,sizeof(que[0]),cmp);
        for(f=0;f<k;f++)
        {
            if(v >= que[f].b)
            {
                v-=que[f].a;
            }
            else
            {
                break;
            }
        }
        if(f == k)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
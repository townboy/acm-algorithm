******************************
    Author : townboy
    Submit time : 2012-02-10 15:41:11
    Judge Status : Accepted
    HDOJ Runid : 5336945
    Problem id : 2111
    Exe.time : 0MS
    Exe.memory : 144K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    int w;
};
int cmp(const void *a,const void *b)
{
    return -(*(struct node*)a).val+(*(struct node*)b).val;
}
struct node que[200];
int main()
{
    int i,m,v,sum;
    while(scanf("%d",&v),v)
    {
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&que[i].val,&que[i].w);
        }
        sum=0;
        qsort(que,m,sizeof(que[0]),cmp);
        for(i=0;i<m;i++)
        {
            if(v>0)
            {
                if(v>=que[i].w)
                {
                    sum=sum+que[i].w*que[i].val; 
                    v=v-que[i].w;
                }
                else
                {
                    sum=sum+v*que[i].val;
                    break;
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-03-09 01:18:39
    Judge Status : Accepted
    HDOJ Runid : 5503371
    Problem id : 1160
    Exe.time : 15MS
    Exe.memory : 240K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
int val[1200],ci[1200];
struct node 
{
    int w;
    int s;
    int n;
};
struct node que[1200];

int cmp(const void *a,const void *b)
{
    return (*(struct node *)b).w-(*(struct node *)a).w;
}
 
int main()
{
    int i,f,ji,max;
    i=0;
    while(scanf("%d%d",&que[i].w,&que[i].s)!=EOF)
    {
        que[i].n=i+1;
        i++;
    }
    ji=i;
    max=0;
    qsort(que,ji,sizeof(que[0]),cmp);
    for(i=0;i<ji;i++)
    {
        val[i]=1;
        ci[i]=-1;
        for(f=0;f<i;f++)
        {
            if((que[i].s>que[f].s)&&(que[i].w<que[f].w))
            {
                if(val[f]+1>=val[i])
                {
                    val[i]=val[f]+1;
                    ci[i]=f;
                }
            }
        }
        if(val[i]>val[max])
        {
            max=i;
        }
    }
    printf("%d\n",val[max]);
    while(-1!=ci[max])
    {
        printf("%d\n",que[max].n);
        max=ci[max];
    }
    printf("%d\n",que[max].n);
    getchar();
    return 0;
}
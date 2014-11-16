******************************
    Author : townboy
    Submit time : 2012-03-14 17:52:10
    Judge Status : Accepted
    HDOJ Runid : 5546400
    Problem id : 1025
    Exe.time : 187MS
    Exe.memory : 720K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
struct node
{
    int r;
    int p;
};

struct node que[600000];

int cmp(const void *a,const void *b)
{
    return (*(struct node *)a).p-(*(struct node *)b).p;
}

int min[600000];

int main()
{
    int n,i,ji,l,r,m,num;
    num=0;
    while(scanf("%d",&n)!=EOF)
    {
        num++;
        min[0]=0;
        ji=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&que[i].p,&que[i].r);
        }
        qsort(que,n,sizeof(que[0]),cmp);
        for(i=0;i<n;i++)
        {
            if(que[i].r>min[ji])
            {
                ji++;
                min[ji]=que[i].r;
            }
            else 
            {
                l=1;
                r=ji;
                while(r>=l)
                {
                    m=(l+r)>>1;
                    if(min[m]>que[i].r&&que[i].r>min[m-1])
                    {
                        min[m]=que[i].r;
                        break;
                    }
                    else if(que[i].r>min[m])
                    {
                        l=m+1;
                    }
                    else
                    {
                        r=m-1;
                    }
                }
            }
        }
        if(1==ji)
        {
            printf("Case %d:\nMy king, at most 1 road can be built.\n\n",num);
        }
        else
        {
            printf("Case %d:\nMy king, at most %d roads can be built.\n\n",num,ji);
        }
    }
    return 0;
}
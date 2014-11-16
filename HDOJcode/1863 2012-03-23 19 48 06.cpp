******************************
    Author : townboy
    Submit time : 2012-03-23 19:48:06
    Judge Status : Accepted
    HDOJ Runid : 5617000
    Problem id : 1863
    Exe.time : 0MS
    Exe.memory : 196K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>

int set[10000];

void merge(int x,int y)
{
    set[x]=y;
}

int find(int x)
{
    while(set[x]!=x)
    {
        x=set[x];
    }
    return x;
}

struct node 
{
    int x;
    int y;
    int d;
};

int cmp(const void *a,const void *b)
{
    return (*(struct node *)a).d-(*(struct node *)b).d; 
}

int main()
{
    int m,n,i,ji,sum;
    struct node que[200];
    while(scanf("%d",&n),n)
    {
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
            set[i]=i;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&que[i].x,&que[i].y,&que[i].d);
        }
        qsort(que,n,sizeof(que[0]),cmp);
        ji=0;
        sum=0;
        for(i=0;i<n;i++)
        {
            if(m-1==ji)
            {
                break;
            }
            if(find(que[i].x)!=find(que[i].y))
            {
                ji++;
                sum=sum+que[i].d;
                merge(find(que[i].x),find(que[i].y));
            }
        }
        if(m-1==ji)
        {
            printf("%d\n",sum);
        }
        else
        {
            printf("?\n");
        }
    }
    return 0;
}
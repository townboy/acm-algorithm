******************************
    Author : townboy
    Submit time : 2012-05-02 00:12:16
    Judge Status : Accepted
    HDOJ Runid : 5880255
    Problem id : 3249
    Exe.time : 15MS
    Exe.memory : 328K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int l;
    int p;
};
struct node q[12000];

int cmp(const void *a,const void *b)
{
    if( ((struct node*)a)->p > ((struct node*)b)->p )
    {
        return 1;
    }
    if( ((struct node*)a)->p < ((struct node*)b)->p )
    {
        return -1;
    }
    if( ((struct node*)a)->l > ((struct node*)b)->l )
    {
        return 1;
    }
    return -1;
} 

int main()
{
    int n,i,last,now,ji,sum;
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&q[i].l,&q[i].p);
        }

        qsort(q,n,sizeof(q[0]),cmp);

        sum=0;
        ji=0;
        last=-10000000;
        now=-10000000;

        for(i=0;i<=100100;i++)
        {
            if(ji == n )
            {
                break;
            }

            if(q[ji].p > i)
            {
                continue;
            }
            
            if(q[ji].p >= now)
            {
                last=now;
                if(last+q[ji].l >= q[ji].p)
                {
                    now=last+q[ji].l;
                }
                else
                {
                    now=q[ji].p;
                }
                 sum++;
                 ji++;
                 continue;
            }

            if(q[ji].l < now-last)
            {
               if(last+q[ji].l >= q[ji].p)
                {
                    now=last+q[ji].l;
                }
                else
                {
                    now=q[ji].p;
                }
                ji++;

                continue;
            }
            ji++;
        }
        
        printf("%d\n",sum);
    }
    return 0;
}
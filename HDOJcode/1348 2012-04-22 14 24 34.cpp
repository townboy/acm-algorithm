******************************
    Author : townboy
    Submit time : 2012-04-22 14:24:34
    Judge Status : Accepted
    HDOJ Runid : 5822017
    Problem id : 1348
    Exe.time : 15MS
    Exe.memory : 288K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node 
{
    double x;
    double y;
};
struct node zan[1100],q[1100],stack[1100];
int n;

int cmp(const void *a,const void *b)
{
    if( ((struct node *)a)->x * ((struct node *)b)->y - ((struct node *)b)->x * ((struct node *)a)->y >0 )
    {
        return -1;
    }
    if( ((struct node *)a)->x * ((struct node *)b)->y - ((struct node *)b)->x * ((struct node *)a)->y <0 )
    {
        return 1;
    }
    if( fabs(((struct node *)a)->x) < fabs(((struct node *)b)->x) )
    {
        return -1;
    }
    if( fabs(((struct node *)a)->x) > fabs(((struct node *)b)->x) )
    {
        return 1;
    }
    if( fabs(((struct node *)a)->y) < fabs(((struct node *)b)->y) )
    {
        return -1;
    }
    return 1;
}

double cha(struct node a,struct node b,struct node c)
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

int scan()
{
    int i,head;
    
    head=1;
    stack[0].x=0;
    stack[0].y=0;
    stack[1]=q[0];

    for(i=1;i<n-1;i++)
    { 
        head++;
        stack[head]=q[i];
        while( cha(stack[head-2],stack[head-1],stack[head]) < 0 )
        {
            stack[head-1]=stack[head--];
        }
    }

    return head;
}

int main()
{
    int i,f,k,ji,aim,head,dis;
    double res,minx,miny;
//    freopen("D:\\in.txt","r",stdin);
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        scanf("%d%d",&n,&dis);

        if(0!=i)
        {
            printf("\n");
        }
        minx=1000000;
        miny=1000000;

        for(f=0;f<n;f++)
        {
            scanf("%lf%lf",&zan[f].x,&zan[f].y);
            if( zan[f].y<miny || ( miny==zan[f].y && zan[f].x<minx ) )
            {
                aim=f;
                minx=zan[f].x;
                miny=zan[f].y;
            }
        }

        if(1==n)
        {
            printf("%.0lf\n",2*3.1415927*dis);
            continue ;
        }

        ji=0;
        for(f=0;f<n;f++)
        {
            if(aim == f)
            {
                continue;
            }
            q[ji].x=zan[f].x-minx;
            q[ji++].y=zan[f].y-miny;
        }

        qsort(q,n-1,sizeof(q[0]),cmp);
    
        head=scan();
        
        res=0;
        for(f=0;f<=head;f++)
        {
            res+=sqrt( (stack[f].x-stack[(f+1)%(head+1)].x)*(stack[f].x-stack[(f+1)%(head+1)].x) + (stack[f].y-stack[(f+1)%(head+1)].y)*(stack[f].y-stack[(f+1)%(head+1)].y) );
        }
        res+=2*3.1415927*dis;

        printf("%.0lf\n",res);
    }
    return 0;
}
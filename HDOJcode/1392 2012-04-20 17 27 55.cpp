******************************
    Author : townboy
    Submit time : 2012-04-20 17:27:55
    Judge Status : Accepted
    HDOJ Runid : 5811088
    Problem id : 1392
    Exe.time : 15MS
    Exe.memory : 220K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct point 
{
    int x;
    int y;
};
struct point zan[110],p[110],stack[110];

int n;

int cha(struct point a,struct point b,struct point c)
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

int cmp(const void *a,const void *b)
{
    return -((struct point*)a)->x*((struct point*)b)->y+((struct point*)a)->y*((struct point*)b)->x;
}

int scan()
{
    int head,i;
    head=1;
    
    stack[0].x=0;
    stack[0].y=0;
    stack[1]=p[0];
        
    for(i=1;i<n-1;i++)
    {
        head++;
        stack[head]=p[i];
        while(cha(stack[head-2],stack[head-1],stack[head])<0)
        {
            stack[head-1]=stack[head--];
        }
    }
    return head;
}

int main()
{
    double res;
    int i,ji,minx,miny,aimi,head;
    while(scanf("%d",&n),n)
    {
        
        miny=10000000;
        minx=10000000;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&zan[i].x,&zan[i].y);
            if( (zan[i].y<miny) || (zan[i].y==miny)&&(zan[i].x<minx) )
            {
                aimi=i;
                miny=zan[i].y;
                minx=zan[i].x;
            }
        }
        if(1==n)
        {
            printf("0.00\n");
            continue;
        }
        
        ji=0;
        for(i=0;i<n;i++)
        {
            if( i==aimi )
            {
                continue;
            }
            p[ji].x=zan[i].x-minx;
            p[ji++].y=zan[i].y-miny;
        }
        
        qsort(p,n-1,sizeof(p[0]),cmp);
        head=scan();
        res=0;
        for(i=0;i<=head;i++)
        {
            res+=sqrt((stack[i].x-stack[(i+1)%(head+1)].x)*(stack[i].x-stack[(i+1)%(head+1)].x)+(stack[i].y-stack[(i+1)%(head+1)].y)*(stack[i].y-stack[(i+1)%(head+1)].y));
        }
        if(2==n)
        {
            printf("%.2lf\n",res/2);    
        }
        else
        {
            printf("%.2lf\n",res);
        }
    } 
    return 0;
}
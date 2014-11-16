******************************
    Author : townboy
    Submit time : 2012-07-04 14:15:38
    Judge Status : Accepted
    HDOJ Runid : 6127195
    Problem id : 3400
    Exe.time : 0MS
    Exe.memory : 212K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>

struct node
{
    double x;
    double y;
};
struct node que[4];
int P,Q,R; 

double second(struct node a,struct node b)
{
    return (sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)))/R+(sqrt((que[3].x-b.x)*(que[3].x-b.x)+(que[3].y-b.y)*(que[3].y-b.y)))/Q; 
}

double first(struct node x)
{
    struct node l=que[2],r=que[3],ml,mr;
    while((r.x-l.x)*(r.x-l.x)+(r.y-l.y)*(r.y-l.y) > 1e-12)
    {
        ml.x=(l.x*2+r.x)/3;
        ml.y=(l.y*2+r.y)/3;
        mr.x=(l.x+r.x*2)/3;
        mr.y=(l.y+r.y*2)/3;
        if(second(x,ml) < second(x,mr))
        {
            r=mr; 
        }
        else
        { 
            l=ml; 
        } 
    }
    return second(x,ml)+sqrt((x.x-que[0].x)*(x.x-que[0].x)+(x.y-que[0].y)*(x.y-que[0].y))/P; 
}    

int main()
{
    int i,f,num;
    struct node r,l,mr,ml; 
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        for(f=0;f<4;f++)
        {
            scanf("%lf%lf",&que[f].x,&que[f].y);
        }
        scanf("%d%d%d",&P,&Q,&R);
        
        l=que[0];
        r=que[1];
        
        while((r.x-l.x)*(r.x-l.x)+(r.y-l.y)*(r.y-l.y) > 1e-12)
        {
            ml.x=(l.x*2+r.x)/3;
            ml.y=(l.y*2+r.y)/3;
            mr.x=(l.x+r.x*2)/3;
            mr.y=(l.y+r.y*2)/3;
            if(first(ml) < first(mr))
            {
                r=mr;
            }
            else
            {
                l=ml;    
            }
        }
        printf("%.2lf\n",first(ml));
    }    
    return 0;
}
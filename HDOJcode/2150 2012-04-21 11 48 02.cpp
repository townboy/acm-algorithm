******************************
    Author : townboy
    Submit time : 2012-04-21 11:48:02
    Judge Status : Accepted
    HDOJ Runid : 5815234
    Problem id : 2150
    Exe.time : 0MS
    Exe.memory : 232K
    https://github.com/townboy
******************************


#include<stdio.h>

struct node 
{
    double x;
    double y;
};
struct node q[50][110];

int check(struct node a,struct node b,struct node c,struct node d)
{
    if( ( (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x) )*( (b.x-a.x)*(d.y-a.y)-(b.y-a.y)*(d.x-a.x) ) >0 )
    {
        return 0;
    }
    if( ( (d.x-c.x)*(a.y-c.y)-(d.y-c.y)*(a.x-c.x) )*( (d.x-c.x)*(b.y-c.y)-(d.y-c.y)*(b.x-c.x) ) >0 )
    {
        return 0;
    }
    return 1;
}

int main()
{
    int k,n,num[50],f,i,g,h,flag;
    while(scanf("%d",&k)!=EOF)
    {
        flag=1;
        for(i=0;i<k;i++)
        {
            scanf("%d",&n);

            num[i]=n;
            for(f=0;f<num[i];f++)
            {
                scanf("%lf%lf",&q[i][f].x,&q[i][f].y);
                if(0==f)
                {
                    continue ;    
                }
                for(g=0;g<i;g++)
                {
                    for(h=1;h<num[g];h++)
                    {
                        if(0==flag)
                        {
                            continue;
                        }
                        else
                        {
                            if( 1==check(q[i][f],q[i][f-1],q[g][h],q[g][h-1]) )
                            {
                                flag=0;
                            }
                        }
                    }
                }
            }
        }

        if(0==flag)
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
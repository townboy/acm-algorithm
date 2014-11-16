******************************
    Author : townboy
    Submit time : 2012-04-19 22:08:41
    Judge Status : Accepted
    HDOJ Runid : 5806885
    Problem id : 1086
    Exe.time : 0MS
    Exe.memory : 212K
    https://github.com/townboy
******************************


#include<stdio.h>

struct xx
{
    double x;
    double y;
};

struct node
{
    struct xx s;
    struct xx e;
};
struct node point[110];

double cha(struct xx a,struct xx b,struct xx c)
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

int check(int a,int b)
{
    if(cha(point[a].s,point[a].e,point[b].s)*cha(point[a].s,point[a].e,point[b].e)>0)
    {
        return 0;
    }
    if(cha(point[b].s,point[b].e,point[a].s)*cha(point[b].s,point[b].e,point[a].e)>0)
    {
        return 0;
    }
    return 1;
}

int main()
{
    int sum,n,i,f;
    while(scanf("%d",&n),n)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf%lf%lf",&point[i].s.x,&point[i].s.y,&point[i].e.x,&point[i].e.y);
            for(f=0;f<i;f++)
            {
                sum+=check(f,i);
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
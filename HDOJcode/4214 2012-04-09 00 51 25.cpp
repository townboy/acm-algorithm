******************************
    Author : townboy
    Submit time : 2012-04-09 00:51:25
    Judge Status : Accepted
    HDOJ Runid : 5735047
    Problem id : 4214
    Exe.time : 0MS
    Exe.memory : 252K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
#include<queue>
using namespace std;

struct node
{
    double x;
    double y;
    double d;
};

struct node ru,tem;

int test(struct node a,struct node b)
{
    double dis;
    dis=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    if(a.d*a.d>dis)
    {
        return 1;
    }
    if(b.d*b.d>dis)
    {
        return 1;
    }
    return 0;
}

int fun(int n)
{
    int chu,sum,i,f,ji;
    chu=0;
    sum=0;
    queue<node> he,cun;
    for(i=0;i<n;i++)
    {
        scanf("%lf%lf%lf",&ru.x,&ru.y,&ru.d);
        he.push(ru);
        for(f=0;f<sum;f++)
        {
            tem=cun.front();
            cun.pop();
            if(1==test(tem,ru))
            {
                chu++;
                he.push(tem);
            }
            else
            {
                cun.push(tem);
            }
        }
        sum=sum-chu;
        while(0!=chu)
        {
            ru.x=0;
            ru.y=0;
            ru.d=0;
            for(f=0;f<chu+1;f++)
            {
                tem=he.front();
                he.pop();
                ru.x+=tem.x;
                ru.y+=tem.y;
                ru.d+=tem.d*tem.d;
            }
    
            ru.x=(ru.x)/(chu+1);
            ru.y=(ru.y)/(chu+1);
            ru.d=sqrt(ru.d);
            he.push(ru);
     
            chu=0;
            for(f=0;f<sum;f++)
            {
                tem=cun.front();
                cun.pop();
                if(1==test(tem,ru))
                {
                    chu++;
                    he.push(tem);
                }
                else
                {
                    cun.push(tem);
                }
            }
            sum-=chu;
        }

        sum++;
        tem=he.front();
        he.pop();
        cun.push(tem);
    }
    ji=0;
    while(!cun.empty())
    {
        ji++;
        cun.pop();
    }
    return ji;
}

int main()
{
    int n,pr;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%d",&n),n)
    {
        pr=fun(n);
        printf("%d\n",pr);
    }
    return 0;
}
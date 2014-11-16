******************************
    Author : townboy
    Submit time : 2013-03-29 22:34:19
    Judge Status : Accepted
    HDOJ Runid : 7927214
    Problem id : 4533
    Exe.time : 171MS
    Exe.memory : 5168K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>

using namespace std;

__int64 xi[210000][3];

void fun(__int64 x,__int64 y,__int64 k)
{
    __int64 maxx=max(x,y),minn=min(x,y);
    xi[0][0]+=k;
    xi[minn+1][0]-=k;
    xi[minn+1][1]+=minn*k;
    xi[maxx+1][1]-=minn*k;
    xi[maxx+1][2]+=k*x*y;
}

void debug()
{
    int i;
    for(i=0;i<10;i++)
        printf("%d %d %d\n",xi[i][0],xi[i][1],xi[i][2]);
}

int main()
{
    int x1,x2,y1,y2,f,g;
    int q;
    __int64 t,sum,now,sa,sb,sc;
    int i,cas,n;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d",&n);
        memset(xi,0,sizeof(xi));
        for(f=0;f<n;f++)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            fun(x2,y2,1);
            fun(x1,y1,1);
            fun(x1,y2,-1);
            fun(x2,y1,-1);
        }
        scanf("%d",&q);
        now=0;
        sa=0;
        sb=0;
        sc=0;
        for(f=0;f<q;f++)
        {
            scanf("%I64d",&t);
            for(;now<=t;now++)
            {
                sa+=xi[now][0];
                sb+=xi[now][1];
                sc+=xi[now][2];
            }
            sum=t*t*sa+t*sb+sc;
            printf("%I64d\n",sum);
        }
    }
    return 0;
}
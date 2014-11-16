******************************
    Author : townboy
    Submit time : 2013-04-08 10:39:00
    Judge Status : Accepted
    HDOJ Runid : 8028218
    Problem id : 2187
    Exe.time : 31MS
    Exe.memory : 248K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

struct node 
{
    int p;
    int sum;
    friend bool operator < (node a,node b)
    {
        return a.p < b.p;
    }
};
struct node que[1100];

int main()
{
    int n,m;
    double ans,rest,buy;
    int i,cas,f;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        ans=0;
        scanf("%d%d",&n,&m);
        for(f=0;f<m;f++)
            scanf("%d%d",&que[f].p,&que[f].sum);
        sort(que,que+m);
        rest=n;
        for(f=0;f<m;f++)
        {
            if(rest <= que[f].sum*que[f].p)
            {
                ans+=rest/que[f].p;
                break;
            }
            else
            {
                ans+=que[f].sum;
                rest-=que[f].sum*que[f].p;
            }
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
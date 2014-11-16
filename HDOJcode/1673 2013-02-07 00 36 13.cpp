******************************
    Author : townboy
    Submit time : 2013-02-07 00:36:13
    Judge Status : Accepted
    HDOJ Runid : 7601033
    Problem id : 1673
    Exe.time : 15MS
    Exe.memory : 248K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>

using namespace std;

int n;
int minn,maxx;

void chu()
{
    maxx=-1;
    minn=10000000;
}

int main()
{
    int tem;
    int f,i,cas;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d",&n);
        chu();
        for(f=0;f<n;f++)
        {
            scanf("%d",&tem);
            maxx=max(maxx,tem);
            minn=min(minn,tem);
        }
        printf("%d\n",2*(maxx-minn));
    }
    return 0;
}
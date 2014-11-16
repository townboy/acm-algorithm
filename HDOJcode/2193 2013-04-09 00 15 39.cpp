******************************
    Author : townboy
    Submit time : 2013-04-09 00:15:39
    Judge Status : Accepted
    HDOJ Runid : 8035470
    Problem id : 2193
    Exe.time : 0MS
    Exe.memory : 256K
    https://github.com/townboy
******************************


#include<stdio.h>

int hei[51];

void init()
{
    int i;
    hei[0]=1;
    hei[1]=2;
    for(i=2;i<=45;i++)
        hei[i]=1+hei[i-1]+hei[i-2];
}

int main()
{
    int i,n;
    init();
    while(scanf("%d",&n),n)
    {
        for(i=0;i<=43;i++)
            if(n < hei[i])
            {
                printf("%d\n",i-1);
                break;
            }
    }
    return 0;
}
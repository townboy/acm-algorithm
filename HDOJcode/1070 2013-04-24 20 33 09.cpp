******************************
    Author : townboy
    Submit time : 2013-04-24 20:33:09
    Judge Status : Accepted
    HDOJ Runid : 8164734
    Problem id : 1070
    Exe.time : 0MS
    Exe.memory : 288K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>

using namespace std;

#define INF 0x7fffffff

char brand[110][110];

int main()
{
    double price,tem;
    int cost,vol,maxvol;
    int i,cas,n,pos,f;
    int tian;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d",&n);
        price = INF;
        for(f=0;f<n;f++)
        {
            scanf("%s%d%d",brand[f],&cost,&vol);
            tian=vol/200;
            tian=min(tian,5);
            if(0 == tian)    continue;
            tem = (double)cost/tian;
            if(tem < price || (tem==price && vol > maxvol))
            {
                price = tem;
                pos = f;
                maxvol = vol;
            }
        }
        printf("%s\n",brand[pos]);
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2013-01-22 15:06:11
    Judge Status : Accepted
    HDOJ Runid : 7530045
    Problem id : 1557
    Exe.time : 15MS
    Exe.memory : 320K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>

using namespace std;

int num[11000],tuan[30];

void chu()
{
    memset(num,0,sizeof(num));
    num[0]=1;
}

void fun(int tem)
{
    int i;
    for(i=10000;i>=tem;i--)
        num[i]+=num[i-tem];
}

int main()
{
    int ban,tem;
    int g,sum,cas,n,i,f;

    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d",&n);
        sum=0;
        for(f=0;f<n;f++)
        {    
            scanf("%d",&tuan[f]);
            sum+=tuan[f];
        }
        ban=sum/2;
        for(f=0;f<n;f++)
        {
            chu();
            for(g=0;g<n;g++)
            {
                if(f == g)
                    continue;
                fun(tuan[g]);
            }
            tem=0;
            if(0 != f)
                printf(" ");
            
            if(0 == tuan[f])
            {
                printf("0");
                continue;
            }
            for(g=max(0,ban+1-tuan[f]);g<=ban;g++)
                tem+=num[g];
            printf("%d",tem);    
        }
        printf("\n");
    }
    return 0;
}
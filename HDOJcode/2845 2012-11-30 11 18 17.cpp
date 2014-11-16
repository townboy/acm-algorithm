******************************
    Author : townboy
    Submit time : 2012-11-30 11:18:17
    Judge Status : Accepted
    HDOJ Runid : 7292516
    Problem id : 2845
    Exe.time : 140MS
    Exe.memory : 972K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
using namespace std;

int n,m;
int beans[210000];
int hang[210000],lie[210000];

int turn(int x,int y)
{
    return m*(x-1)+y;
}

int dp()
{
    int i,f,one,two;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=2;f++)
        {
            lie[f]=beans[turn(i,f)];
        }    
        for(f=3;f<=m;f++)
        {
            lie[f]=max(lie[f-2],lie[f-3])+beans[turn(i,f)];        
        }
        hang[i]=max(lie[m],lie[m-1]);
    }
    for(i=1;i<=2;i++)
    {
        lie[i]=hang[i];        
    }
    for(i=3;i<=n;i++)
    {
        lie[i]=max(lie[i-2],lie[i-3])+hang[i];
    }
    return max(lie[n],lie[n-1]);
}

int main()
{
    int i,f;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=m;f++)
            {
                scanf("%d",&beans[turn(i,f)]);
            }
        }
        printf("%d\n",dp());    
    }
    return 0;
}
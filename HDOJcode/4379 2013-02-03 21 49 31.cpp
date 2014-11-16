******************************
    Author : townboy
    Submit time : 2013-02-03 21:49:31
    Judge Status : Accepted
    HDOJ Runid : 7589915
    Problem id : 4379
    Exe.time : 953MS
    Exe.memory : 264K
    https://github.com/townboy
******************************


#include<stdio.h>
#define INF 0x7fffffff

int sum;
int maxx,minn;
int n,l,a,b,mod;
double er;

int min(int a,int b)
{
    return a<b?a:b;    
}

int max(int a,int b)
{
    return a>b?a:b;    
}

void fun()
{
    int i,yu=b;
    for(i=1;i<=n;i++)
    {
        yu=(yu+a)%mod;
        if(yu <= l/2)
        {    
            sum++;
            maxx=max(maxx,yu);            
        }
        else
            minn=min(minn,yu);
    }
}

void chu()
{
    maxx=0;
    minn=INF;
    sum=0;
    er=(double)l/2;
}

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        chu();
        scanf("%d%d%d%d",&l,&a,&b,&mod);
        fun();
        if(INF == minn)
        {
            printf("%d\n",sum);
            continue;
        }
        if(minn+maxx > l)
            printf("%d\n",sum);
        else
            printf("%d\n",sum+1);
    }
    return 0;
}
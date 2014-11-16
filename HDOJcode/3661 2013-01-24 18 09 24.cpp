******************************
    Author : townboy
    Submit time : 2013-01-24 18:09:24
    Judge Status : Accepted
    HDOJ Runid : 7541020
    Problem id : 3661
    Exe.time : 203MS
    Exe.memory : 236K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int a[1100],b[1100];

int main()
{
    int sum,n,t,i;
    while(scanf("%d%d",&n,&t)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
            scanf("%d",&b[i]);
        qsort(a,n,sizeof(a[0]),cmp);
        qsort(b,n,sizeof(b[0]),cmp);
        sum=0;
        for(i=0;i<n;i++)
            sum+=max(0,a[i]+b[n-1-i]-t);        
        printf("%d\n",sum);
    }
    return 0;
}
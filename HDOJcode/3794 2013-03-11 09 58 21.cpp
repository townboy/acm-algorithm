******************************
    Author : townboy
    Submit time : 2013-03-11 09:58:21
    Judge Status : Accepted
    HDOJ Runid : 7735345
    Problem id : 3794
    Exe.time : 171MS
    Exe.memory : 1768K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int aval[1100000],bval[1100000];
int a,b;

int cmp(const void*a,const void *b)
{
    return *(int*)b-*(int*)a;
}

int check(int a,int b)
{
    return (__int64)a*b>0?1:0;
}

int main()
{
    __int64 ans;
    int i;
    while(scanf("%d",&a),a>=0)
    {
        ans=0;
        for(i=0;i<a;i++)
            scanf("%d",aval+i);
        scanf("%d",&b);
        for(i=0;i<b;i++)
            scanf("%d",bval+i);
        qsort(aval,a,sizeof(aval[0]),cmp);
        qsort(bval,b,sizeof(bval[0]),cmp);
        for(i=0;i<min(a,b);i++)
            if(1 == check(aval[i],bval[i]) && aval[i] > 0)
                ans+=(__int64)aval[i]*bval[i];
            else
                break;
        
        for(i=0;i<min(a,b);i++)
            if(1 == check(aval[a-1-i],bval[b-1-i]) && aval[a-1-i] < 0)
                ans+=(__int64)aval[a-1-i]*bval[b-1-i];
            else
                break;
        printf("%I64d\n",ans);
    }
    return 0;
}
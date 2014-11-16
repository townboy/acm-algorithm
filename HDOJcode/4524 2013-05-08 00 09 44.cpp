******************************
    Author : townboy
    Submit time : 2013-05-08 00:09:44
    Judge Status : Accepted
    HDOJ Runid : 8258067
    Problem id : 4524
    Exe.time : 109MS
    Exe.memory : 396K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#define maxn 100010

using namespace std;

int que[maxn];

int main()
{
    int n,f;
    int cas,i;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d",&n);
        for(f=0;f<n;f++)
            scanf("%d",que+f);
        for(f=n-1;f>0;f--)
        {
            if(que[f] > 0)
                que[f-1]-=que[f];
            else if(que[f] < 0)
                break;
        }
        if(0!=f || 0!=que[f])
            puts("I will never go out T_T");
        else
            puts("yeah~ I escaped ^_^");
    }
    return 0;
}
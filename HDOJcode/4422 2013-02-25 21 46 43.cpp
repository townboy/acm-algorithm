******************************
    Author : townboy
    Submit time : 2013-02-25 21:46:43
    Judge Status : Accepted
    HDOJ Runid : 7652944
    Problem id : 4422
    Exe.time : 15MS
    Exe.memory : 248K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>

using namespace std;

int val[5],sum,n,ans;

void check()
{
    int i,f,g;
    for(i=0;i<n;i++)
        for(f=i+1;f<n;f++)
            for(g=f+1;g<n;g++)
                if(0 == (val[i]+val[f]+val[g])%1024)
                    ans=max(ans,(sum-val[i]-val[f]-val[g]-1)%1024+1);
}

void fun()
{
    int i,f,ans=-1;
    for(i=0;i<n;i++)
        for(f=i+1;f<n;f++)
            ans=max(ans,(val[i]+val[f]-1)%1024+1);
    printf("%d\n",ans);        
}

int main()
{
    int i;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&val[i]);
            sum+=val[i];
        }
        if(n < 4)
        {
            printf("1024\n");
            continue;
        }
        if(5 == n)
        {
            ans=0;
            check();
            printf("%d\n",ans);
        }
        else
        {
            ans=-1;
            check();
            if(-1 != ans)
                printf("1024\n");
            else
                fun();
        }        
    }
    return 0;
}
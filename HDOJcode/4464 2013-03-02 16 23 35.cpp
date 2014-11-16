******************************
    Author : townboy
    Submit time : 2013-03-02 16:23:35
    Judge Status : Accepted
    HDOJ Runid : 7676370
    Problem id : 4464
    Exe.time : 0MS
    Exe.memory : 256K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>

using namespace std;

char ch[1100];

int main()
{
    int f,sum,i,n,ans,cas=0;
    while(scanf("%d",&n)!=EOF)
    {
        cas++;
        getchar();
        ans=-1;
        for(i=0;i<n;i++)
        {
            gets(ch);
            sum=0;
            for(f=0;ch[f];f++)
            {
                sum+=ch[f];
            }
            ans=max(ans,sum);
        }
        printf("Case %d: %d\n",cas,ans);    
    }
    return 0;
}
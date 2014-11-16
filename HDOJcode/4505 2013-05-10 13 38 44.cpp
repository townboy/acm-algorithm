******************************
    Author : townboy
    Submit time : 2013-05-10 13:38:44
    Judge Status : Accepted
    HDOJ Runid : 8275410
    Problem id : 4505
    Exe.time : 0MS
    Exe.memory : 264K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
    int n,floor[20],last;
    int ans,cas,i,f;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d",&n);
        for(f=0;f<n;f++)
            scanf("%d",floor+f);
        sort(floor,floor+f);
        ans=0;
        last=0;
        for(f=0;f<n;f++)
            if(last == floor[f])
                ans++;
            else
            {
                ans+=6*(floor[f]-last)+6;
                last=floor[f];
            }
        ans+=last*4;
        printf("%d\n",ans);
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-12-02 01:04:24
    Judge Status : Accepted
    HDOJ Runid : 7309189
    Problem id : 4476
    Exe.time : 156MS
    Exe.memory : 1112K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>

using namespace std;

int n;
int cut[110000],ji[110000];

void chu()
{
    memset(cut,0,sizeof(cut));
}

int main()
{
    int ans,sum,i,cas,f,k;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d",&n);
        chu();
        for(f=0;f<n;f++)
        {
            scanf("%d",&k);
            cut[k]++;
        }
        sum=0;
        for(f=1;f<=100000;f++)
        {
            sum+=cut[f];
            ji[f]=sum;            
        }
        ans=0;
        for(f=1;f<=100000;f++)
        {
            if(0 == cut[f])
            {
                continue;
            }            
            k=f/2+(f%2==0?-1:0);
            ans=max(ans,n+cut[f]-ji[k]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
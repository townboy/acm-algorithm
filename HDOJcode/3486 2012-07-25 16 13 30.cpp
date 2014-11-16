******************************
    Author : townboy
    Submit time : 2012-07-25 16:13:30
    Judge Status : Accepted
    HDOJ Runid : 6326722
    Problem id : 3486
    Exe.time : 765MS
    Exe.memory : 15960K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
#include<iostream>
#include<memory.h>
using namespace std;

int dp[210000][20],n,k;

void st()
{
    int t,i,f,k,m;
    k=(int)(log((double)(n))/log(2.0));
    for(f=1;f<=k;f++)
    {
        for(i=1;i+(1<<f)-1 <= n;i++)
        {
            m=i+(1<<(f-1));
            dp[i][f]=max(dp[i][f-1],dp[m][f-1]);    
        }
    }
}

int rmq(int a,int b)
{
    int k=(int)(log((double)(b-a+1))/log(2.0));
    return max(dp[a][k],dp[b-(1<<k)+1][k]);
}

int check(int x)
{
    int i,ans=0,fen=n/x;
    for(i=1;i<=x;i++)
    {
        ans+=rmq(fen*(i-1)+1,fen*i);
        if(ans > k)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int i,sum,big,l,r,mid;
    while(scanf("%d%d",&n,&k),!(n<0&&k<0))
    {
        sum=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&dp[i][0]);
            sum+=dp[i][0];
        }
        if(sum <= k)
        {
            printf("-1\n");
            continue;
        }
        st();
        
        l=0;
        r=n;
        while(l != r-1)
        {
            mid=(l+r)>>1;
            if(1 == check(mid))
            {
                r=mid;
            }
            else
            {
                l=mid;
            }
        }
        printf("%d\n",r);
    }
    return 0;
}
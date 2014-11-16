******************************
    Author : townboy
    Submit time : 2013-05-10 15:12:19
    Judge Status : Accepted
    HDOJ Runid : 8276038
    Problem id : 4506
    Exe.time : 15MS
    Exe.memory : 348K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#define maxn 10010
#define mod 1000000007

using namespace std;

__int64 ji,k,a[maxn];
int n,t;

int pos(int a,int b)
{
    int ans=a-(b%n);
    while(ans < 0)
        ans+=n;
    return ans;
}

void ans()
{
    int i;
    for(i=0;i<n;i++)
    {
        if(0 != i)
            printf(" ");
        printf("%I64d",(a[pos(i,t)]*ji)%mod);
    }
    puts("");
}

void init(){
    ji=1;
    int tt = t;
    __int64 kk = k;
    while(0 != tt)
    {
        if(1 == (tt&1))
            ji=(ji*kk)%mod;
        tt>>=1;
        kk=(kk*kk)%mod;
    }
}

int main()
{
    int f,cas,i;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d%d",&n,&t,&k);
        init();
        for(f=0;f<n;f++)
            scanf("%d",a+f);
        ans();
    }
    return 0;
}
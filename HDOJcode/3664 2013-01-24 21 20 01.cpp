******************************
    Author : townboy
    Submit time : 2013-01-24 21:20:01
    Judge Status : Accepted
    HDOJ Runid : 7542037
    Problem id : 3664
    Exe.time : 15MS
    Exe.memory : 7180K
    https://github.com/townboy
******************************


#include<stdio.h>
#define mod 1000000007 

__int64 f[1010][1010];

void chu()
{
    int i,g;
    for(i=1;i<=1000;i++)
        for(g=0;g<=i;g++)
            if(i == g)
                f[i][g]=0;
            else if(0 == g)
                f[i][g]=1;
            else
                f[i][g]=((1+g)*f[i-1][g]+(i-g)*f[i-1][g-1])%mod;    
}

int main()
{
    int n,k;

    chu();
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        printf("%I64d\n",f[n][k]);
    }
    return 0;
}
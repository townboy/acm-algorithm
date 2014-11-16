******************************
    Author : townboy
    Submit time : 2011-10-30 01:04:42
    Judge Status : Accepted
    HDOJ Runid : 4854155
    Problem id : 2070
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main (void)
{
    int i,n,max;
    __int64 f[55];
    max=1;
    f[0]=0;
    f[1]=1;
    while(scanf("%d",&n),!(n==-1))
    {
        if(n<=max)
            printf("%I64d\n",f[n]);
        else
        {
            for(i=max+1;i<=n;i++)
            {
            f[i]=f[i-1]+f[i-2];
            }
            printf("%I64d\n",f[n]);
            max=n;
        }
    
    
    
    }
    return 0;
}




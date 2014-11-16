******************************
    Author : townboy
    Submit time : 2012-05-28 14:09:22
    Judge Status : Accepted
    HDOJ Runid : 6010504
    Problem id : 4243
    Exe.time : 15MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>

__int64 c(int x)
{
    __int64 fan=1;
    int j=1;
    while(x > j)
    {
        j++;
        fan*=j;
    }
    return fan;
}

int main()
{
    int i,num,k,n,j,f;
    __int64 ans;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&j);
        printf("%d ",j);

        scanf("%d%d",&n,&k);
        if(1 == k)
        {
            printf("%I64d\n",c(n-1));
            continue;
        }
        ans=0;
        for(f=2;f<=k;f++)
        {    
            ans+=(c(k-2)/c(k-f)/c(f-2)*c(f-1)*c(n-f));
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
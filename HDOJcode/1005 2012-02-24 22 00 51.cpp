******************************
    Author : townboy
    Submit time : 2012-02-24 22:00:51
    Judge Status : Accepted
    HDOJ Runid : 5408519
    Problem id : 1005
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
int f[200],jie,chu;
int check(int x)
{
    int i;
    for(i=1;i<x;i++)
    {
        if(f[i]==f[x]&&f[i+1]==f[x+1])
        {
            chu=i;
            jie=x-i;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int a,b,n,i;
    f[1]=1;
    f[2]=1;
    while(scanf("%d%d%d",&a,&b,&n),!(0==a&&0==b&&0==n))
    {
        for(i=3;;i++)
        {
            f[i]=(a*f[i-1]+b*f[i-2])%7;
            if(1==check(i-1))
            {
                break;
            }
        }
         if(n<chu)
        {
            printf("%d\n",f[n]);
        }
        else
        {
            printf("%d\n",f[(n-chu)%jie+chu]);
        }
    }
    return 0;
}
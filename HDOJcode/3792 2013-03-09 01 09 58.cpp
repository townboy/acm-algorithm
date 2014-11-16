******************************
    Author : townboy
    Submit time : 2013-03-09 01:09:58
    Judge Status : Accepted
    HDOJ Runid : 7717390
    Problem id : 3792
    Exe.time : 46MS
    Exe.memory : 1060K
    https://github.com/townboy
******************************


#include<stdio.h>

int n;
int su[110000];
int ans[110000];

void yu()
{
    int i,f,last=2;
    for(i=2;i<=1000;i++)
    {
        if(1 == su[i])
            continue;
        for(f=i*i;f<=100000;f+=i)
            su[f]=1;
    }
    for(i=3;i<=100000;i++)
        if(0 == su[i])
        {
            if(last == i-2)
                ans[i]++;
            last=i;
        }
    for(i=1;i<=100000;i++)
        ans[i]+=ans[i-1];
}

int main()
{
    int i;
    yu();
    while(scanf("%d",&n),n>=0)
    {
        printf("%d\n",ans[n]);
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2013-04-03 01:17:49
    Judge Status : Accepted
    HDOJ Runid : 7973488
    Problem id : 2110
    Exe.time : 15MS
    Exe.memory : 240K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int p[110],m[110];
int num[3100],sum;

void init()
{
    memset(num,0,sizeof(num));
    num[0]=1;
    sum=0;
}

void fun(int pos)
{
    int i,f;
    for(i=sum/3;i>0;i--)
    {
        for(f=1;f<=m[pos];f++)
        {
            if(i-f*p[pos] < 0)    break;
                num[i]+=num[i-f*p[pos]];
            num[i]%=10000;
        }
    }
}

int main()
{
    int i,n;
    while(scanf("%d",&n),n)
    {
        init();
        for(i=0;i<n;i++)
        {
            scanf("%d%d",p+i,m+i);
            sum+=p[i]*m[i];
        }
        if(0 != sum%3)
        {
            printf("sorry\n");
            continue;
        }
        for(i=0;i<n;i++)
            fun(i);
        if(0 == num[sum/3])
            printf("sorry\n");
        else
            printf("%d\n",num[sum/3]%10000);
    }
    return 0;
}
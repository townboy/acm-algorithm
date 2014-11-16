******************************
    Author : townboy
    Submit time : 2012-07-16 21:00:22
    Judge Status : Accepted
    HDOJ Runid : 6233140
    Problem id : 2838
    Exe.time : 31MS
    Exe.memory : 1920K
    https://github.com/townboy
******************************


#include<memory.h>
#include<stdio.h>

__int64 in[110000];
__int64 old[110000];

void chu()
{
    memset(in,0,sizeof(in));
    memset(old,0,sizeof(old));        
}

int lowbit(int t)
{
    return t&(-t);
}

void plus(int pos,int v)
{
    while(pos <= 100000)
    {
        old[pos]+=1;
        in[pos]+=v;
        pos+=lowbit(pos);
    }
}

__int64 sum(int end)
{
    __int64 sum=0;
    while(end > 0)
    {
        sum+=in[end];
        end-=lowbit(end);    
    }
    return sum;    
}

__int64 sum2(int end)
{
    __int64 sum=0;
    while(end > 0)
    {
        sum+=old[end];
        end-=lowbit(end);    
    }
    return sum;    
}

int main()
{
    __int64 summ,x;
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        summ=0;
        chu();
        for(i=0;i<n;i++)
        {
            scanf("%I64d",&x);
            summ+=sum(100000)-sum(x);
            summ+=(sum2(100000)-sum2(x))*x;
            plus(x,x);
        }
        printf("%I64d\n",summ);
    }
    return 0;
}
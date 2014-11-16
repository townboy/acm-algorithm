******************************
    Author : townboy
    Submit time : 2012-07-11 21:15:58
    Judge Status : Accepted
    HDOJ Runid : 6184850
    Problem id : 1556
    Exe.time : 421MS
    Exe.memory : 624K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int in[110000],maxn=100005;

int lowbit(int t)
{
    return t&(-t);
}

void chu()
{
    memset(in,0,sizeof(in));
}

void  plus(int end,int v)
{
    while(end <= maxn)
    {
        in[end]+=v;
        end+=lowbit(end);
    }
}

int sum(int end)
{
    int sum=0;
    while(end > 0)
    {    
        sum+=in[end];
        end-=lowbit(end);
    }
    return sum;
}

int main()
{
    int n,i,a,b;
    while(scanf("%d",&n),n)
    {
        chu();
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            plus(a,1);
            plus(b+1,-1);
        }
        for(i=1;i<=n;i++)
        {
            if(1 != i)
            {
                printf(" ");
            }
            printf("%d",sum(i));
        }
        printf("\n");
    }
    return 0;
}
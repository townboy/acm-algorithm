******************************
    Author : townboy
    Submit time : 2012-07-12 16:59:23
    Judge Status : Accepted
    HDOJ Runid : 6192008
    Problem id : 4217
    Exe.time : 968MS
    Exe.memory : 1564K
    https://github.com/townboy
******************************


#include<stdio.h>

int in[400000],maxn=350000,n;

int lowbit(int t)
{
    return t&(-t);
}

void chu()
{
    int i;
    for(i=1;i<=350000;i++)
    {
        in[i]=lowbit(i);
    }
}

int sum(int end)
{
    int sum=0;
    if(0 == end)
    {
        return 0;
    }
    while(end > 0)
    {
        sum+=in[end];
        end-=lowbit(end);
    }
    return sum;
}

int bs(int k)
{
    int l=0,r=n,mid;
    while(r != l+1)
    {
        mid=(l+r)>>1;
        if(sum(mid) >= k)
        {
            r=mid;
        }
        else
        {
            l=mid;
        }        
    }
    return r;
}

void plus(int pos,int v)
{
    while(pos <= n)
    {
        in[pos]+=v;
        pos+=lowbit(pos);
    }
}

int main()
{
    __int64 sum;
    int num,i,f,k,p,x;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("Case %d: ",i+1);
        sum=0;
        scanf("%d%d",&n,&k);
        chu();
        for(f=0;f<k;f++)
        {
            scanf("%d",&x);
            p=bs(x);
            sum+=p;
            plus(p,-1);
//            printf("%d\n",p);
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
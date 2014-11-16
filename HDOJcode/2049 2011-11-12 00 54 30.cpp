******************************
    Author : townboy
    Submit time : 2011-11-12 00:54:30
    Judge Status : Accepted
    HDOJ Runid : 4952983
    Problem id : 2049
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
__int64 cun(__int64 x);
__int64 buc(__int64 x);
__int64 cun(__int64 x)
{
    if((1==x)||(2==x))
    {
        return 1;
    }
    else
    {
        return (x-1)*cun(x-1)+buc(x-1);
    }
    

}

__int64 buc(__int64 x)
{
    return (x-1)*cun(x-1);
}

__int64 jie(__int64 x)
{
    __int64 fan=1;
    int i;
    for(i=1;i<=x;i++)
    {
        fan=fan*i;
    }
    return fan;
}

int main(void)
{
    int num,i;
    __int64 m,n,jie1,jie2;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%I64d%I64d",&n,&m);
        jie1=buc(m);
        jie2=jie(n)/(jie(n-m)*jie(m));
        printf("%I64d\n",jie1*jie2);    
     
    }
    return 0;
}
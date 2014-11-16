******************************
    Author : townboy
    Submit time : 2011-11-11 00:29:11
    Judge Status : Accepted
    HDOJ Runid : 4947537
    Problem id : 2048
    Exe.time : 0MS
    Exe.memory : 220K
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
    __int64 shang,xia,f;
    int i,num;
    double shu;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%I64d",&f);
        shang=buc(f);
        xia=jie(f);
        shu=(double)shang/xia*100;
        printf("%.2lf%%\n",shu);
    }
    return 0;
}
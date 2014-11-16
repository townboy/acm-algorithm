******************************
    Author : townboy
    Submit time : 2012-05-04 12:00:44
    Judge Status : Accepted
    HDOJ Runid : 5892008
    Problem id : 2446
    Exe.time : 31MS
    Exe.memory : 252K
    https://github.com/townboy
******************************


#include<stdio.h>

__int64 x;

void check()
{
    __int64 yu;
    __int64 l,r,mid,z;
    l=0;
    r=4000000;
    while(l+1!=r)
    {
        mid=(l+r)>>1;
        if((double)mid*(mid+1)*(mid+2)/6 < x)
        {
            l=mid;
        } 
        else
        {
            r=mid;
        }
    }

    yu=x-l*(l+1)*(l+2)/6;
    printf("%I64d ",l+1);

    l=0;
    r=4000000;
    while(l+1!=r)
    {
        mid=(l+r)>>1;
        if((double)mid*(mid+1)/2 < yu)
        {
            l=mid;
        } 
        else
        {
            r=mid;
        }
    }
    z=yu-l*(l+1)/2;
    printf("%I64d %I64d\n",l+1,z);
}

int main()
{
    int num,i;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%I64d",&x);
        check();
    }
    return 0;
}

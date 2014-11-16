******************************
    Author : townboy
    Submit time : 2011-11-18 22:24:19
    Judge Status : Accepted
    HDOJ Runid : 5014791
    Problem id : 1061
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
__int64 ge;
void suan(__int64 n,__int64 x)
{
    if(n==1)
    {
        ge=ge*x;
        ge=ge%10;
    }
    else
    {
        if(0==n%2)
        {
            ge=ge*ge;
            ge=ge%10;
            suan(n/2,x);
        }
        else
        {
            x=x*ge;
            x=x%10;
            ge=ge*ge;
            ge=ge%10;
            suan(n/2,x);
        }
    }
}
int main(void)
{
    __int64 n;
    int num,i;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%I64d",&n);
        ge=n%10;
        suan(n,1);
        printf("%d\n",ge);
    }
return 0;
}
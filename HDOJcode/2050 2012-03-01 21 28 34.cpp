******************************
    Author : townboy
    Submit time : 2012-03-01 21:28:34
    Judge Status : Accepted
    HDOJ Runid : 5445627
    Problem id : 2050
    Exe.time : 0MS
    Exe.memory : 276K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    __int64 jie[12000],i;
    int n,num;
    jie[1]=2;
    for(i=2;i<=10010;i++)
    {
        jie[i]=jie[i-1]+4*(i-1)+1;
    }
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        printf("%I64d\n",jie[n]);
    }
    return 0;
}
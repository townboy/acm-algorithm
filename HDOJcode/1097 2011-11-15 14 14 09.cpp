******************************
    Author : townboy
    Submit time : 2011-11-15 14:14:09
    Judge Status : Accepted
    HDOJ Runid : 4981707
    Problem id : 1097
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int ge,yu;
int sum(int num)
{
    if(1==num%2)
    {
        yu=yu*ge;
        yu=yu%10;
    }
    ge=(ge*ge)%10;
    num=num/2;
    return num;
}
int main(void)
{
    int result,a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        ge=a%10;
        yu=1;
        result=b;
        while(1!=result)
        {
            result=sum(result);
        }
        printf("%d\n",(yu*ge)%10);
    }


    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-01-12 20:19:13
    Judge Status : Accepted
    HDOJ Runid : 5249610
    Problem id : 1877
    Exe.time : 15MS
    Exe.memory : 156K
    https://github.com/townboy
******************************


#include<stdio.h>
void me(__int64 x,int m)
{
    int i,ji,zan[100];
    ji=0;
    if(0==x)
    {
        printf("0\n");
        return ;
    }
    while(0!=x)
    {
        zan[ji]=x%m;
        x=x/m;
        ji++;
    }
    for(i=ji-1;i>=0;i--)
    {
        printf("%d",zan[i]);
    }
    printf("\n");
} 
int main(void)
{
    int m;
    __int64 a,b;
    while(scanf("%d",&m),m)
    {
        scanf("%I64d%I64d",&a,&b);
        me(a+b,m);
    }
return 0;
}
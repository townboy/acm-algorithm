******************************
    Author : townboy
    Submit time : 2011-12-21 00:25:28
    Judge Status : Accepted
    HDOJ Runid : 5189094
    Problem id : 1517
    Exe.time : 140MS
    Exe.memory : 156K
    https://github.com/townboy
******************************


#include<stdio.h>
int num;
int np(__int64 x)
{
    int flag,i;
    if(x>=num)
    {
        return 0;
    }
    flag=0;
    for(i=9;i>=2;i--)
    {
        if(np(x*i)==0)
        {
            flag=1;
            break;
        }
    }
    return flag;
}
int main(void)
{
    int flag;
    while(scanf("%d",&num)!=EOF)
    {
        flag=np(1);
        if(1==flag)
        {
            printf("Stan wins.\n");
        }
        else
        {
            printf("Ollie wins.\n");
        }
    }
return 0;
}

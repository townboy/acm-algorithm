******************************
    Author : townboy
    Submit time : 2012-06-27 11:47:14
    Judge Status : Accepted
    HDOJ Runid : 6103073
    Problem id : 2674
    Exe.time : 31MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int yu,x,i;
    while(scanf("%d",&x)!=EOF)
    {
        yu=1;
        for(i=2;i<=x;i++)
        {
            yu=(yu*i)%2009;
            if(0 == yu)
            {
                break;
            }
        }
        printf("%d\n",yu);
    }
    return 0;
}
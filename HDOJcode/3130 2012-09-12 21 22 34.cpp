******************************
    Author : townboy
    Submit time : 2012-09-12 21:22:34
    Judge Status : Accepted
    HDOJ Runid : 6753114
    Problem id : 3130
    Exe.time : 0MS
    Exe.memory : 236K
    https://github.com/townboy
******************************


#include<stdio.h>

int main()
{
    int f,i,a,b,l,r;
    for(i=100;i<=999;i++)
    {
        for(f=i+1;f<=999;f++)
        {
            r=i%10;
            l=f/100;
            a=i/10;;
            b=f%100;
            if(r != l)
            {
                continue;
            }
            if(i*b == f*a)
            {
                printf("%d / %d = %d / %d\n",i,f,a,b);
            }
        }
    }
    return 0;
}
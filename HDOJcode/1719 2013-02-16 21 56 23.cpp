******************************
    Author : townboy
    Submit time : 2013-02-16 21:56:23
    Judge Status : Accepted
    HDOJ Runid : 7621123
    Problem id : 1719
    Exe.time : 15MS
    Exe.memory : 232K
    https://github.com/townboy
******************************


#include<stdio.h>

int check(int tem)
{
    if(0 == tem)
        return 0;
    tem++;
    while(0 == tem%2)
        tem>>=1;
    while(0 == tem%3)
        tem/=3;
    if(1 == tem)
        return 1;
    return 0;        
}

int main()
{
    int tem;
    while(scanf("%d",&tem)!=EOF)
    {
        if(1 == check(tem))
            printf("YES!\n");
        else
            printf("NO!\n");
    }
    return 0;
}
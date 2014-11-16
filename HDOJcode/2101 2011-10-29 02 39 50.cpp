******************************
    Author : townboy
    Submit time : 2011-10-29 02:39:50
    Judge Status : Accepted
    HDOJ Runid : 4845887
    Problem id : 2101
    Exe.time : 15MS
    Exe.memory : 212K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        if((x+y)%86==0)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
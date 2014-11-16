******************************
    Author : townboy
    Submit time : 2011-10-22 23:46:12
    Judge Status : Accepted
    HDOJ Runid : 4805947
    Problem id : 2004
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
void main ()
{   int x;
    while(scanf("%d",&x)!=EOF)
    {
        if(x<=100&&x>=90)
            printf("A\n");
        else if(x<=89&&x>=80)
            printf("B\n");
        else if(x<=79&&x>=70)
            printf("C\n");
        else if(x<=69&&x>=60)
            printf("D\n");
        else if(x<=59&&x>=0)
            printf("E\n");
        else
            printf("Score is error!\n");

    }
}
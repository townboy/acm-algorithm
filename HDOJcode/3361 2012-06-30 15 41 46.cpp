******************************
    Author : townboy
    Submit time : 2012-06-30 15:41:46
    Judge Status : Accepted
    HDOJ Runid : 6110600
    Problem id : 3361
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int num,x,i;
    while(scanf("%d",&num)!=EOF)
    {
        for(i=0;i<num;i++)
        {    
            scanf("%d",&x);
            printf("%c",x);
        }
    }
    return 0;
}
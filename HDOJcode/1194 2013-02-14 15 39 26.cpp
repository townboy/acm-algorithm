******************************
    Author : townboy
    Submit time : 2013-02-14 15:39:26
    Judge Status : Accepted
    HDOJ Runid : 7614684
    Problem id : 1194
    Exe.time : 15MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>

int check(int tem)
{
    if(0 != (1&tem))
        return 0;
    if(tem < 0)
        return 0;
    return 1;  
} 

int main()
{
    int sum,diff;
    int i,cas;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d",&sum,&diff);
        if(1 == check(sum+diff) && 1 == check(sum-diff))
            printf("%d %d\n",(sum+diff)/2,(sum-diff)/2);
        else
            printf("impossible\n"); 
    }
    return 0;
} 
******************************
    Author : townboy
    Submit time : 2011-11-06 10:17:29
    Judge Status : Accepted
    HDOJ Runid : 4911277
    Problem id : 2107
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{

    int max,x,num,i;
    while(scanf("%d",&num),num)
    {
        scanf("%d",&x);
        max=x;
        for(i=1;i<num;i++)
        {
            scanf("%d",&x);
            if(x>max)
                max=x;
        }
        printf("%d\n",max);
    }
    
    return 0;
}
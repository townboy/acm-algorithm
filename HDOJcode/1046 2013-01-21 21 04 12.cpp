******************************
    Author : townboy
    Submit time : 2013-01-21 21:04:12
    Judge Status : Accepted
    HDOJ Runid : 7527142
    Problem id : 1046
    Exe.time : 15MS
    Exe.memory : 276K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int a,b;
    int i,cas;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d",&a,&b);
        printf("Scenario #%d:\n",i+1);
        if(0 == a%2 || 0 == b%2)
            printf("%d.00\n",a*b);
        else
            printf("%d.41\n",a*b);
        printf("\n");
    }
    return 0;
}
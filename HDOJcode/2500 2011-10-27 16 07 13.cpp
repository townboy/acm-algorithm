******************************
    Author : townboy
    Submit time : 2011-10-27 16:07:13
    Judge Status : Accepted
    HDOJ Runid : 4834615
    Problem id : 2500
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main (void)
{   
    int num,i,big,hang,lie;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&big);
        for(hang=0;hang<big*3;hang++)
        {
            for(lie=0;lie<big;lie++)
            {
                printf("HDU");
            }
            printf("\n");
        }
    }

return 0;
}
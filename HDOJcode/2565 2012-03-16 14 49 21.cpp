******************************
    Author : townboy
    Submit time : 2012-03-16 14:49:21
    Judge Status : Accepted
    HDOJ Runid : 5560687
    Problem id : 2565
    Exe.time : 15MS
    Exe.memory : 212K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int num,x,f,i,g;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&x);
        for(f=1;f<=x/2;f++)
        {
            for(g=0;g<f-1;g++)
            {
                printf(" ");
            }
            printf("X");
            for(g=0;g<x-2*f;g++)
            {
                printf(" ");
            }
            printf("X");
            printf("\n");
        }  
        for(f=0;f<x/2;f++)
        {
            printf(" ");
        }
        printf("X\n");
        for(f=x/2;f>=1;f--)
        {
            for(g=0;g<f-1;g++)
            {
                printf(" ");
            }
            printf("X");
            for(g=0;g<x-2*f;g++)
            {
                printf(" ");
            }
            printf("X");
            printf("\n");
        } 
        printf("\n");
    }
    return 0;
}
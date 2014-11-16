******************************
    Author : townboy
    Submit time : 2011-12-08 15:43:20
    Judge Status : Accepted
    HDOJ Runid : 5135167
    Problem id : 2123
    Exe.time : 0MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int num,n,i,f,g;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        for(f=1;f<=n;f++)
        {
            for(g=1;g<=n;g++)
            {
                if(g!=1)
                {
                    printf(" ");
                }
                printf("%d",f*g);
            }
            printf("\n");
        }
    
    }
return 0;
}
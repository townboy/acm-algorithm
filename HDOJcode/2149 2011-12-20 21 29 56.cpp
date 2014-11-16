******************************
    Author : townboy
    Submit time : 2011-12-20 21:29:56
    Judge Status : Accepted
    HDOJ Runid : 5188517
    Problem id : 2149
    Exe.time : 0MS
    Exe.memory : 156K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int i,m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(m<=n)
        {
            for(i=m;i<=n;i++)
            {
                if(i!=m)
                {
                    printf(" ");
                }
                printf("%d",i);
            }
            printf("\n");
        }
        else if(0==m%(n+1))
        {
            printf("none\n");
        }
        else
        {
            printf("%d\n",m%(n+1));
        }
    
    }
    return 0;
}
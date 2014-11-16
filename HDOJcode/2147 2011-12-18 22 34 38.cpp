******************************
    Author : townboy
    Submit time : 2011-12-18 22:34:38
    Judge Status : Accepted
    HDOJ Runid : 5182065
    Problem id : 2147
    Exe.time : 15MS
    Exe.memory : 156K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int n,m;
    while(scanf("%d%d",&m,&n),!(0==n&&0==m))
    {
        if(n%2==0)
        {
            printf("Wonderful!\n");
        }
        else if(m%2==1)
        {
            printf("What a pity!\n");
        }
        else
        {
            printf("Wonderful!\n");
        }
    }
return 0;
}
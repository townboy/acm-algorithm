******************************
    Author : townboy
    Submit time : 2011-11-12 23:13:54
    Judge Status : Accepted
    HDOJ Runid : 4960313
    Problem id : 1037
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int a[3],i,flag;
    while(scanf("%d%d%d",&a[0],&a[1],&a[2])!=EOF)
    {
        flag=0;
        for(i=0;i<3;i++)
        {
            if(a[i]<=168)
            {
                flag=1;
                printf("CRASH %d\n",a[i]);
                break;
            }
        }

        if(0==flag)
        {
            printf("NO CRASH\n");
        }
    
    }
    return 0;
}
        

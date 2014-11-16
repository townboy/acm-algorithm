******************************
    Author : townboy
    Submit time : 2011-11-18 21:30:51
    Judge Status : Accepted
    HDOJ Runid : 5014271
    Problem id : 1279
    Exe.time : 0MS
    Exe.memory : 556K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int num,i,x,n,ji,a[90000],f;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        x=1;
        scanf("%d",&n);
        a[0]=n;
        while(n!=1)
        {
            if(1==n%2)
            {
                n=n*3+1;
            }
            else
            {
                n=n/2;
            }
            a[x]=n;
            x++;
        }
        ji=0;
        for(f=0;f<x-1;f++)
        {
            if(1==a[f]%2)
            {
                if(ji!=0)
                {
                    printf(" ");
                }
                printf("%d",a[f]);
                ji++;
            }
        }
        if(0==ji)
        {
            printf("No number can be output !");
        }
        printf("\n");
    }
return 0;
}
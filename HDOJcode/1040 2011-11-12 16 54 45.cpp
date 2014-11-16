******************************
    Author : townboy
    Submit time : 2011-11-12 16:54:45
    Judge Status : Accepted
    HDOJ Runid : 4956834
    Problem id : 1040
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int num,n,f,g,tem,i,a[1200];
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        
        for(f=0;f<n;f++)
        {
            scanf("%d",&a[f]);
        }

        for(f=0;f<n-1;f++)
        {
            for(g=f;g<n;g++)
            {
                if(a[f]>a[g])
                {
                    tem=a[f];
                    a[f]=a[g];
                    a[g]=tem;
                }          
            }
        }

        for(f=0;f<n;f++)
        {
            printf("%d",a[f]);
            if(f!=n-1)
            {
                printf(" ");
            }
        }
        printf("\n");
    
    }
    return 0;
}
        
    

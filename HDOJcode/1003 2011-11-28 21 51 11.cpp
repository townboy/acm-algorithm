******************************
    Author : townboy
    Submit time : 2011-11-28 21:51:11
    Judge Status : Accepted
    HDOJ Runid : 5075860
    Problem id : 1003
    Exe.time : 15MS
    Exe.memory : 1348K
    https://github.com/townboy
******************************


#include<stdio.h>
__int64 a[100100];
int b[100100];
int main(void)
{
    int num,i,f,n,end,max;
    
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        end=n-1;
        b[n-1]=n-1;
        for(f=0;f<n;f++)
        {
            scanf("%I64d",&a[f]);
        }
        for(f=n-2;f>=0;f--)
        {
            if(a[f+1]>0)
            {
                a[f]=a[f]+a[f+1];
                b[f]=end;
            }
            else
            {
                b[f]=f;
                end=f;
            }
        }
        max=0;
        for(f=1;f<n;f++)
        {
            if(a[f]>a[max])
            {
                max=f;
            }
        }
        if(i!=0)
        {
            printf("\n");
        }
        printf("Case %d:\n",i+1);
        printf("%I64d %d %d\n",a[max],max+1,b[max]+1);

        
    }

return 0;
}
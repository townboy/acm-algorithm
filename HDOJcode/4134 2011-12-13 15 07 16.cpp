******************************
    Author : townboy
    Submit time : 2011-12-13 15:07:16
    Judge Status : Accepted
    HDOJ Runid : 5159401
    Problem id : 4134
    Exe.time : 0MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int num,i,f,n,a[120];
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        for(f=0;f<n;f++)
        {
            scanf("%d",&a[f]);
        }
        while(n!=2)
        {
            if(0==n%2)
            {
                for(f=0;f<n/2;f++)
                {
                    a[f]=a[f]+a[n-f-1];
                }
                n=n/2;
            }
            else
            {
                for(f=0;f<=n/2;f++)
                {
                    a[f]=a[f]+a[n-f-1];   
                }
                n=n/2+1;
            }
        }
        if(a[0]>a[1])
        {
            printf("Case #%d: Alice\n",i+1);
        }
        else
        {
            printf("Case #%d: Bob\n",i+1);
        }
    
    }
return 0;
}
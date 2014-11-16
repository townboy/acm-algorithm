******************************
    Author : townboy
    Submit time : 2011-10-29 23:19:15
    Judge Status : Accepted
    HDOJ Runid : 4853669
    Problem id : 2186
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main (void)
{
    int num,a[5],i,f,sum,n;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        a[0]=n/2;
        n=n-a[0];
        a[1]=(n*2)/3;
        n=n-a[1];
        a[2]=n;
        sum=0;
           for(f=0;f<3;f++)
           {
               if(a[f]%10==0)
                   sum=sum+a[f]/10;
               else
                   sum=sum+(a[f]+10)/10;
           }
    
        printf("%d\n",sum);
    
    
    }


    return 0;
}
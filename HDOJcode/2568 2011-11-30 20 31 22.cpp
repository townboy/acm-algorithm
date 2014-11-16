******************************
    Author : townboy
    Submit time : 2011-11-30 20:31:22
    Judge Status : Accepted
    HDOJ Runid : 5087439
    Problem id : 2568
    Exe.time : 0MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int num,i,ji,n;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        ji=0;
        while(0!=n)
        {
            if(n%2==0)
            {
                n=n/2;
            }
            else
            {
                n=n-1;
                ji++;
            }
        }
        printf("%d\n",ji);
            
    }
return 0;
    
}
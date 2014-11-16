******************************
    Author : townboy
    Submit time : 2011-10-28 00:18:34
    Judge Status : Accepted
    HDOJ Runid : 4838436
    Problem id : 1008
    Exe.time : 15MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int main(void)
{
    int sum,i,a[200],num;
    while(scanf("%d",&num),num)
    {
        sum=0;
        a[0]=0;
        for(i=1;i<num+1;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>a[i-1])
            {
                sum=sum+6*(a[i]-a[i-1])+5;
            }
            else
            {
                sum=sum+4*(a[i-1]-a[i])+5;
            }
       
        }

    
    printf("%d\n",sum);
    
    
    }
  return 0;
}


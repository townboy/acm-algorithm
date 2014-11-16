******************************
    Author : townboy
    Submit time : 2011-11-22 16:30:35
    Judge Status : Accepted
    HDOJ Runid : 5033210
    Problem id : 1164
    Exe.time : 31MS
    Exe.memory : 388K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
int main(void)
{
    int ji,flag,i,f,num,a[40000],jie[10000],j;
    ji=0;
    for(i=2;i<65536;i++)
    {
        flag=1;
        for(f=2;f<=sqrt(i);f++)
        {
            if(0==i%f)
            {
                flag=0;
                break;
            }
        }
        if(1==flag)
        {
            a[ji]=i;
            ji++;
        }
    }
    while(scanf("%d",&num)!=EOF)
    {
        j=0;
        i=0;
        while(num!=1)
        {

                if(num%a[i]==0)
                {
                    num=num/a[i];
                    jie[j]=a[i];
                    j++;
                }
                else
                {
                    i++;
                }
        }
        printf("%d",jie[0]);
            
        for(f=1;f<j;f++)
        {
                printf("*%d",jie[f]);
        }
        printf("\n");
        

    }

return 0;
}
******************************
    Author : townboy
    Submit time : 2011-10-24 23:59:11
    Judge Status : Accepted
    HDOJ Runid : 4818185
    Problem id : 2098
    Exe.time : 906MS
    Exe.memory : 220K
    https://github.com/townboy
******************************


#include<stdio.h>
int main (void)
{   
    int ji=0,flag,i,f,x,su[4000],num;
    for(i=2;i<10001;i++)
    {  
       flag=1;
       for(f=2;f<i;f++)
           if(i%f==0)
           {
           flag=0;
           break;
           }
        if(flag==1)
        {
        su[ji]=i;
        ji++;
        }
    }
    while(scanf("%d",&x),x)
    {   
        num=0;
        for(i=0;i<ji;i++)
        {
            for(f=0;f<ji;f++)
            {
                if((su[i]+su[f]==x)&&(i!=f))
                {
                    num++;
                    break;
                }
            }

        }
        printf("%d\n",num/2);

    }
    return 0;
}
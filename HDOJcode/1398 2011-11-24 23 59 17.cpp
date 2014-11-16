******************************
    Author : townboy
    Submit time : 2011-11-24 23:59:17
    Judge Status : Accepted
    HDOJ Runid : 5050051
    Problem id : 1398
    Exe.time : 15MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int num,i,f,k;
    __int64    c1[400],c2[400];
    while(scanf("%d",&num),num)
    {
        for(i=0;i<=num;i++)
        {
            c1[i]=1;
            c2[i]=0;
        }
        for(i=2;i<=17;i++)
        {
            for(f=0;f<=num;f++)
            {
                for(k=0;k+f<=num;k=k+i*i)
                {
                    c2[k+f]=c2[k+f]+c1[f];
                }
            }
            for(f=0;f<=num;f++)
            {
                c1[f]=c2[f];
                c2[f]=0;
            }
        }
        printf("%I64d\n",c1[num]);
    }
    return 0;
} 

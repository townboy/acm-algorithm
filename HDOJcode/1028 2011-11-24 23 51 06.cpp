******************************
    Author : townboy
    Submit time : 2011-11-24 23:51:06
    Judge Status : Accepted
    HDOJ Runid : 5050009
    Problem id : 1028
    Exe.time : 15MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int num,i,f,k;
    __int64    c1[200],c2[200];
    while(scanf("%d",&num)!=EOF)
    {
        for(i=0;i<=num;i++)
        {
            c1[i]=1;
            c2[i]=0;
        }
        for(i=2;i<=num;i++)
        {
            for(f=0;f<=num;f++)
            {
                for(k=0;k+f<=num;k=k+i)
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

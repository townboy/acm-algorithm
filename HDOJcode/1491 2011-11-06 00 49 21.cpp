******************************
    Author : townboy
    Submit time : 2011-11-06 00:49:21
    Judge Status : Accepted
    HDOJ Runid : 4910383
    Problem id : 1491
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int a[11]={0,31,28,31,30,31,30,31,31,30,21},num,n,m,i,f,sum;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        sum=0;
        scanf("%d%d",&n,&m);
        if(n>10)
            printf("What a pity, it has passed!\n");            
        else if(n<10)
        {
            for(f=n;f<=10;f++)
            {
                sum=sum+a[f];
            }
            printf("%d\n",sum-m);
        }

        else if(m==21)
            printf("It's today!!\n");
        else if(m>21)
            printf("What a pity, it has passed!\n");
        else if(m<21)
            printf("%d\n",21-m);
    }
    return 0;
}
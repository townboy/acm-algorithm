******************************
    Author : townboy
    Submit time : 2011-10-23 23:53:19
    Judge Status : Accepted
    HDOJ Runid : 4812345
    Problem id : 2096
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int a,b,sum,num,i;
    scanf("%d",&num);
        for(i=0;i<num;i++)
        {   sum=0;
            scanf("%d%d",&a,&b);
            sum=a%100+b%100;
            sum=sum%100;
            printf("%d\n",sum);
        }
    

return 0;
}
******************************
    Author : townboy
    Submit time : 2011-11-30 21:54:20
    Judge Status : Accepted
    HDOJ Runid : 5088439
    Problem id : 2502
    Exe.time : 0MS
    Exe.memory : 216K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
int main(void)
{
    int jie,num,i,n;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        jie=pow(2,n-1)+(n-1)*pow(2,n-2);
        printf("%d\n",jie);

    }
return 0;
    
}
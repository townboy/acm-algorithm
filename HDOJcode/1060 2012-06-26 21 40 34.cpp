******************************
    Author : townboy
    Submit time : 2012-06-26 21:40:34
    Judge Status : Accepted
    HDOJ Runid : 6102223
    Problem id : 1060
    Exe.time : 0MS
    Exe.memory : 264K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>

int main()
{
    __int64 x; 
    double s,m; 
    int num,i;
    scanf("%d",&num); 
    for(i=0;i<num;i++)
    {
        scanf("%I64d",&x);
        m=x*log10(x)-(__int64)(x*log10(x));
        s=pow(10,m);
        while(s < 1)
        {
            printf("daole\n"); 
            s*=10; 
        }    
        x=s; 
        printf("%d\n",x);      
    } 
    return 0; 
} 

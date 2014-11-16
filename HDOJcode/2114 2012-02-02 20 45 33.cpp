******************************
    Author : townboy
    Submit time : 2012-02-02 20:45:33
    Judge Status : Accepted
    HDOJ Runid : 5307509
    Problem id : 2114
    Exe.time : 31MS
    Exe.memory : 184K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int sum,num,s[11000],i;
    s[0]=0;
    for(i=1;i<11000;i++)
    {
        s[i]=((int)(s[i-1]+((i*i)%10000)*i))%10000;
    }
    while(scanf("%d",&num)!=EOF)
    {
        sum=((num/10000)*s[9999]+s[num%10000])%10000;
        if(sum<10)
        {
            printf("000%d\n",sum);
        }
        else if(sum<100)
        {
            printf("00%d\n",sum);
        }
        else if(sum<1000)
        {
            printf("0%d\n",sum);
        }
        else
        {
            printf("%d\n",sum);
        }
    }
    return 0;
}

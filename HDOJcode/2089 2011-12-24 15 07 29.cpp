******************************
    Author : townboy
    Submit time : 2011-12-24 15:07:29
    Judge Status : Accepted
    HDOJ Runid : 5201630
    Problem id : 2089
    Exe.time : 156MS
    Exe.memory : 4076K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int me[11000000];
int main(void)
{
    int a,b,i,x,sum,ji;
    char ch1[5]="26",ch2[5]="4",zan[20];
    for(i=1;i<=1000010;i++)
    {
        x=i;
        ji=0;
        while(x!=0)
        {
            zan[ji]=x%10+'0';
            x=x/10;
            ji++;
        }
        zan[ji]='\0';
        if(strstr(zan,ch1)||strstr(zan,ch2))
        {
            me[i]=1;
        }
        else
        {
            me[i]=0;
        }
    }
    while(scanf("%d%d",&a,&b),!(0==a&&0==b))
    {
        sum=0;
        for(i=a;i<=b;i++)
        {
            if(0==me[i])
            {
                sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}

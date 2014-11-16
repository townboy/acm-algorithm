******************************
    Author : townboy
    Submit time : 2012-01-05 00:57:19
    Judge Status : Accepted
    HDOJ Runid : 5230192
    Problem id : 2139
    Exe.time : 265MS
    Exe.memory : 224K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
__int64 tem,a[5000];
int main(void)
{
    int num,i;
    tem=pow(2,33);
    a[1]=1;
    for(i=3;;i=i+2)
    {
        a[i]=a[i-2]+i*i;
        if(a[i]>tem)
        {
            break;
        }
    }
    while(scanf("%d",&num)!=EOF)
    {
        printf("%I64d\n",a[num]);
    }


return 0;
}
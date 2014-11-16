******************************
    Author : townboy
    Submit time : 2011-10-11 00:22:04
    Judge Status : Accepted
    HDOJ Runid : 4735496
    Problem id : 2006
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main (void)
{
int c,a[60],b,i;
while(scanf("%d",&c)!=EOF)
{b=1;
    for(i=0;i<c;i++)
{
scanf("%d",&a[i]);
if (a[i]%2!=0)
b=b*a[i];
    }    
printf("%d\n",b);
}
return 0;
}

******************************
    Author : townboy
    Submit time : 2011-10-17 00:25:19
    Judge Status : Accepted
    HDOJ Runid : 4769788
    Problem id : 2016
    Exe.time : 0MS
    Exe.memory : 184K
    https://github.com/townboy
******************************


#include<stdio.h>
void main()
{
    int n,min,a[1000],i,T;
while(scanf("%d",&n),n)
{scanf("%d",&a[0]);
min=a[0];
for(i=1;i<n;i++)
{
scanf("%d",&a[i]);
if(a[i]<min)
min=a[i];
}
for(i=0;i<n;i++)
{
if(min==a[i])
{
T=a[i];
a[i]=a[0];
a[0]=T;
break;
}
}
printf("%d",a[0]);
for(i=1;i<n;i++)
printf(" %d",a[i]);
printf("\n");
}
}
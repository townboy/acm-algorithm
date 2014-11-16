******************************
    Author : townboy
    Submit time : 2011-10-10 21:55:58
    Judge Status : Accepted
    HDOJ Runid : 4734746
    Problem id : 2075
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main (void)
{
int a,b,c,i;
scanf("%d",&a);
for(i=0;i<a;i++)
{scanf("%d%d",&b,&c);
if (b%c==0)
printf("YES\n");
else printf("NO\n");
}
return 0;
}

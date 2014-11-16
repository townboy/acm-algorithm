******************************
    Author : townboy
    Submit time : 2011-10-17 00:40:49
    Judge Status : Accepted
    HDOJ Runid : 4769814
    Problem id : 2017
    Exe.time : 0MS
    Exe.memory : 184K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
void main()
{
    int n,num,i,g;
    char a[1000];
scanf("%d",&n);

for(i=0;i<n;i++)
{
    num=0;
scanf("%s",a);
for(g=0;g<strlen(a);g++)
{
if(a[g]>=48&&a[g]<=57)
num++;
}

printf("%d\n",num);
}
}
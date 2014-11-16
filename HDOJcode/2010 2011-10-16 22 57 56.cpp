******************************
    Author : townboy
    Submit time : 2011-10-16 22:57:56
    Judge Status : Accepted
    HDOJ Runid : 4769437
    Problem id : 2010
    Exe.time : 0MS
    Exe.memory : 184K
    https://github.com/townboy
******************************


#include<stdio.h>
void main()
{
    int min,max,i,ge,shi,bai,num,jieguo[20];
while(scanf("%d%d",&min,&max)!=EOF)
{
    num=0;
    for(i=min;i<=max;i++)
    {

ge=i%10;
shi=(i%100)/10;
bai=i/100;
if(i==((ge*ge*ge)+(shi*shi*shi)+(bai*bai*bai)))
{//printf("%d ",i);
jieguo[num]=i;
num++;}
}

    if (num==0)
printf("no\n");
    else if(num==1)
        printf("%d\n",jieguo[0]);
else
{printf("%d",jieguo[0]);
for(i=1;i<=num-1;i++)
printf(" %d",jieguo[i]);
printf("\n");
}
        
        
        //printf("\n");
}
}
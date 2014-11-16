******************************
    Author : townboy
    Submit time : 2011-10-16 00:42:55
    Judge Status : Accepted
    HDOJ Runid : 4763954
    Problem id : 2009
    Exe.time : 0MS
    Exe.memory : 204K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
void main()
{
    int ci,i;
float he,chu;
while(scanf("%f",&chu)!=EOF)
{
    scanf("%d",&ci);
    he=0;
    for(i=0;i<ci;i++)
    {
    he=he+chu;
    chu=sqrt(chu);
    }
printf("%.2f\n",he);
}
}
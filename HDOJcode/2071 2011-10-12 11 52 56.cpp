******************************
    Author : townboy
    Submit time : 2011-10-12 11:52:56
    Judge Status : Accepted
    HDOJ Runid : 4741829
    Problem id : 2071
    Exe.time : 46MS
    Exe.memory : 220K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int num,a,i,n;
    float b,height;
    scanf("%d",&num);
for (a=0;a<num;a++)
{
    height=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
{
    scanf("%f",&b);
    if(b>height)
        height=b;
}
printf("%.2f\n",height);
}
return 0;
}
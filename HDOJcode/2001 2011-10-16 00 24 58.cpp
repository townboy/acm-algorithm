******************************
    Author : townboy
    Submit time : 2011-10-16 00:24:58
    Judge Status : Accepted
    HDOJ Runid : 4763895
    Problem id : 2001
    Exe.time : 0MS
    Exe.memory : 204K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
void main()
{
float num,x1,x2,y1,y2;
while(scanf("%f%f%f%f",&x1,&y1,&x2,&y2)!=EOF)
{
    num=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    printf("%.2f\n",num);
}
}
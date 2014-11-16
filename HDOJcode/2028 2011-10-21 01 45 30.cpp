******************************
    Author : townboy
    Submit time : 2011-10-21 01:45:30
    Judge Status : Accepted
    HDOJ Runid : 4793526
    Problem id : 2028
    Exe.time : 140MS
    Exe.memory : 184K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
void main ()
{   
    int i,b,num,flag;
     int  a[50];
    while(scanf("%d",&num)!=EOF)
    {
    for(i=0;i<num;i++)
        scanf("%d",&a[i]);
    
    for(i=a[0];;i++)
    {
        flag=0;
    for(b=0;b<num;b++)
    {
    if(i%a[b]==0)
      flag++;
    }
    if(flag==num)
    {
    printf("%d\n",i);
    break;
    }
    
    }    
    
    
    
    }
}
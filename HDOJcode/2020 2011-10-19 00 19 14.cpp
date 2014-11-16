******************************
    Author : townboy
    Submit time : 2011-10-19 00:19:14
    Judge Status : Accepted
    HDOJ Runid : 4779585
    Problem id : 2020
    Exe.time : 0MS
    Exe.memory : 184K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
void main()
{
  int num,a[102],i,b,zhong;
  while(scanf("%d",&num),num)
  {
  for(i=0;i<num;i++)
  {
      scanf("%d",&a[i]);}
  
  
  for(b=0;b<num-1;b++)
  {for(i=0;i<num-1;i++)
  if(abs(a[i])<abs(a[i+1]))
  {zhong=a[i];
  a[i]=a[i+1];
  a[i+1]=zhong;}
  }
  
  
  for(b=0;b<num;b++)
  {  if(b!=num-1)
      printf("%d ",a[b]);
     if(b==num-1)
         printf("%d\n",a[b]);}
  }

}


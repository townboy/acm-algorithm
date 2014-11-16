******************************
    Author : townboy
    Submit time : 2011-10-22 22:20:57
    Judge Status : Accepted
    HDOJ Runid : 4805443
    Problem id : 2030
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
void main ()
{
    int i,num,sum,a,len;
    char ch[1000];
   scanf("%d",&num);
    getchar();
   for(i=0;i<num;i++)
   {
     
       gets(ch);
      sum=0;
      len=strlen(ch);
      for(a=0;a<len;a++)
      {
          if(ch[a]<0)
          {
          sum++;
          }
      
      }
      printf("%d\n",sum/2);
   
   
   
   }
   




}
******************************
    Author : townboy
    Submit time : 2011-12-13 15:52:23
    Judge Status : Accepted
    HDOJ Runid : 5159559
    Problem id : 2163
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int main(void)
{
    int len,ji,i;
    char ch[10000],chy[10000],tem;
    ji=0;
     while(gets(ch),strcmp(ch,"STOP"))
     {
         ji++;
         len=strlen(ch);
         strcpy(chy,ch);
         for(i=0;i<len/2;i++)
         {
             tem=ch[i];
             ch[i]=ch[len-1-i];
             ch[len-1-i]=tem;
         }
         if(strcmp(ch,chy))
         {
             printf("#%d: NO\n",ji);
         }
         else
         {
             printf("#%d: YES\n",ji);
         }
     }
return 0;
}
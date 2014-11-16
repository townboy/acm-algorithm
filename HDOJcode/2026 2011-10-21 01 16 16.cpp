******************************
    Author : townboy
    Submit time : 2011-10-21 01:16:16
    Judge Status : Accepted
    HDOJ Runid : 4793488
    Problem id : 2026
    Exe.time : 0MS
    Exe.memory : 180K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
void main ()
{   
    int i,a;
    char ch[100];
    while(gets(ch)!=NULL)
    {
       ch[0]=ch[0]-32;
       a=strlen(ch);
       for(i=0;i<a-1;i++)
       {
       if (ch[i]==' ')
       {
       ch[i+1]=ch[i+1]-32;
       }
       }
       for(i=0;i<a;i++)
       {
       printf("%c",ch[i]);
       }
    printf("\n");
    }
}
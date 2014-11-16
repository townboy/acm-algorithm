******************************
    Author : townboy
    Submit time : 2011-10-21 01:00:33
    Judge Status : Accepted
    HDOJ Runid : 4793471
    Problem id : 2025
    Exe.time : 0MS
    Exe.memory : 184K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
void main ()
{   
    int i,max,a;
        char ch[100];
    while(scanf("%s",ch)!=EOF)
    {
        max=ch[0];
        a=strlen(ch);
    for(i=0;i<a;i++)
    {
    if(max<ch[i])
       max=ch[i];
    }
    for(i=0;i<a;i++)
    {
    if(max==ch[i])
       printf("%c(max)",ch[i]);
    else
       printf("%c",ch[i]);
    }
    printf("\n");
    
    
    }
}
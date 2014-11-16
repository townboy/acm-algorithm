******************************
    Author : townboy
    Submit time : 2011-10-26 00:15:09
    Judge Status : Accepted
    HDOJ Runid : 4824102
    Problem id : 2029
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int main (void)
{   
    int num,i,b,a,flag;
        char ch[5000];
    scanf("%d",&num);
    getchar();
    for(i=0;i<num;i++)
    {
    scanf("%s",ch);
    a=strlen(ch);
    flag=1;
    if(a%2==0)
    {
        for(b=0;b<=a/2-1;b++)
        {
         if(ch[b]==ch[a-1-b])
             ;
         else
         {   
             flag=0;
             printf("no\n");
         break;
         }
    
        }
        if(flag==1)
         printf("yes\n");
    }
    else
    {
        
            for(b=0;b<=(a-1)/2-1;b++)
        {
         if(ch[b]==ch[a-1-b])
             ;
         else
         {   
             flag=0;
             printf("no\n");
         break;
         }
    
        }
        if(flag==1)
         printf("yes\n");
    
    
    }
    
    
    
    
    }
return 0;
}
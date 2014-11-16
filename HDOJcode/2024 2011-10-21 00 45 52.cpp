******************************
    Author : townboy
    Submit time : 2011-10-21 00:45:52
    Judge Status : Accepted
    HDOJ Runid : 4793452
    Problem id : 2024
    Exe.time : 0MS
    Exe.memory : 192K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
void main ()
{   
    char ch[60];
    int num,i,a,flag,b;
    scanf("%d",&num);
    getchar();
    for(i=0;i<num;i++)
    {
        flag=1;

    gets(ch);
    b=strlen(ch);
    if(ch[0]==95||(ch[0]>=65&&ch[0]<=90)||(ch[0]>=97&&ch[0]<=122))
    {
    for(a=1;a<b;a++)
        
    {
        if(ch[a]==95||(ch[a]>=65&&ch[a]<=90)||(ch[a]>=48&&ch[a]<=57)||(ch[a]>=97&&ch[a]<=122))
         ;
        else 
        {    printf("no\n");
        flag=0;
            break;
        }
    }
    }
    else
    {printf("no\n");
    flag=0;
    }  
    if(flag==1)
     printf("yes\n");

    
    
    }

    

}
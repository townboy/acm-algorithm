******************************
    Author : townboy
    Submit time : 2013-02-22 17:23:00
    Judge Status : Accepted
    HDOJ Runid : 7641711
    Problem id : 3787
    Exe.time : 0MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>

int a,b;
char ch1[50],ch2[50];

void fun()
{
    int i,flag=0;
    int len1=strlen(ch1),len2=strlen(ch2);
    a=0;
    for(i=0;i<len1;i++)
    {
        if('-' == ch1[i])
            flag=1;
        else if(',' == ch1[i])
            continue;
        else
        {
            a*=10;
            a+=ch1[i]-'0';        
        }                
    }
    if(1 == flag)
        a=-a;

    flag=b=0;
    for(i=0;i<len2;i++)
    {
        if('-' == ch2[i])
            flag=1;
        else if(',' == ch2[i])
            continue;
        else
        {
            b*=10;
            b+=ch2[i]-'0';        
        }                
    }
    if(1 == flag)
        b=-b;    
}

int main()
{
    while(scanf("%s%s",ch1,ch2)!=EOF)
    {
        fun();    
        printf("%d\n",a+b);
    }
    return 0;
}
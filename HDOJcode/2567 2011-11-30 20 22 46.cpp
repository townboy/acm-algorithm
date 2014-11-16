******************************
    Author : townboy
    Submit time : 2011-11-30 20:22:46
    Judge Status : Accepted
    HDOJ Runid : 5087335
    Problem id : 2567
    Exe.time : 0MS
    Exe.memory : 180K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int main(void)
{
    int i,f,num,len;
    char ch1[200],ch2[200];
    scanf("%d",&num);
    getchar();
    for(i=0;i<num;i++)
    {
        gets(ch1);
        gets(ch2);
        len=strlen(ch1);
        for(f=0;f<len/2;f++)
        {
            printf("%c",ch1[f]);
        }
        printf("%s",ch2);
        for(f=len/2;f<len;f++)
        {
            printf("%c",ch1[f]);
        }
        printf("\n");
    }
return 0;
    
}
******************************
    Author : townboy
    Submit time : 2011-12-07 15:40:57
    Judge Status : Accepted
    HDOJ Runid : 5127892
    Problem id : 2562
    Exe.time : 0MS
    Exe.memory : 180K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int main(void)
{
    int i,len,num,f;
    char ch[100];
    scanf("%d",&num);
    getchar();
    for(i=0;i<num;i++)
    {
        gets(ch);
        len=strlen (ch);
        for(f=0;f<len/2;f++)
        {
            printf("%c",ch[f*2+1]);
            printf("%c",ch[f*2]);
        }
        printf("\n");
    }
return 0;
}

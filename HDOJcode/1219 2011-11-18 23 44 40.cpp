******************************
    Author : townboy
    Submit time : 2011-11-18 23:44:40
    Judge Status : Accepted
    HDOJ Runid : 5015435
    Problem id : 1219
    Exe.time : 0MS
    Exe.memory : 240K
    https://github.com/townboy
******************************


#include<stdio.h>
char ch[110000];
int main(void)
{
    int i,len;
    int a[30];
    while(gets(ch)!=NULL)
    {
        for(i=0;i<26;i++)
        {
            a[i]=0;
        }
        len=strlen(ch);
        for(i=0;i<len;i++)
        {
            if((ch[i]>='a')&&(ch[i]<='z'))
            {
                a[ch[i]-'a']++;
            }
        }
        for(i=0;i<26;i++)
        {
            printf("%c:%d\n",i+'a',a[i]);    
        }
        printf("\n");
    }
return 0;
}
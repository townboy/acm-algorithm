******************************
    Author : townboy
    Submit time : 2013-02-05 17:59:35
    Judge Status : Accepted
    HDOJ Runid : 7596516
    Problem id : 1321
    Exe.time : 15MS
    Exe.memory : 248K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>

char ch[80];

int main()
{
    int len,f;
    int i,cas;
    scanf("%d",&cas);
    getchar();
    for(i=0;i<cas;i++)
    {
        gets(ch);
        len=strlen(ch);
        for(f=len-1;f>=0;f--)
            printf("%c",ch[f]);
        printf("\n");    
    }
    return 0;
}
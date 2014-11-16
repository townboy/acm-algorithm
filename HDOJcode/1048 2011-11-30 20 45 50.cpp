******************************
    Author : townboy
    Submit time : 2011-11-30 20:45:50
    Judge Status : Accepted
    HDOJ Runid : 5087625
    Problem id : 1048
    Exe.time : 0MS
    Exe.memory : 196K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int main(void)
{
    int len,i;
    char a[50]="VWXYZABCDEFGHIJKLMNOPQRSTU",end[20]="ENDOFINPUT",ch1[10000],ch2[10000],ch3[10000];
    while(gets(ch1),strcmp(end,ch1))
    {
        gets(ch2);
        len=strlen(ch2);
        for(i=0;i<len;i++)
        {
            if((ch2[i]>='A')&&(ch2[i]<='Z'))
            {
                printf("%c",a[ch2[i]-'A']);
            }
            else
            {
                printf("%c",ch2[i]);
            }
        }
        printf("\n");
        gets(ch3);
    }
return 0;
    
}
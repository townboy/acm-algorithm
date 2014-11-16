******************************
    Author : townboy
    Submit time : 2011-11-18 21:53:43
    Judge Status : Accepted
    HDOJ Runid : 5014515
    Problem id : 1870
    Exe.time : 0MS
    Exe.memory : 204K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    char ch[2000];
    int len,i,ji;
    while(gets(ch)!=NULL)
    {
        len=strlen(ch);
        ji=0;
        for(i=0;i<len;i++)
        {
            if(ch[i]=='B')
            {
                break;
            }
            else if(ch[i]=='(')
            {
                ji++;
            }
            else
            {
                ji--;
            }
        }
        printf("%d\n",ji);
    }
    
return 0;
}
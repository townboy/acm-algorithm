******************************
    Author : townboy
    Submit time : 2013-02-22 20:22:30
    Judge Status : Accepted
    HDOJ Runid : 7642246
    Problem id : 1860
    Exe.time : 0MS
    Exe.memory : 224K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>

char ch1[10],ch2[100];

int main()
{
    int i,sum,f;
    int len1,len2;
    while(gets(ch1)!=NULL)
    {
        if(0 == strcmp(ch1,"#"))
            break;
        gets(ch2);
        len1=strlen(ch1);
        len2=strlen(ch2);
        for(i=0;i<len1;i++)
        {
            sum=0;
            for(f=0;f<len2;f++)
            {
                if(ch1[i] == ch2[f])
                    sum++;        
            }
            printf("%c %d\n",ch1[i],sum);            
        }
    }
    return 0;
}
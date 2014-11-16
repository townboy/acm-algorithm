******************************
    Author : townboy
    Submit time : 2012-12-23 18:52:04
    Judge Status : Accepted
    HDOJ Runid : 7434633
    Problem id : 4485
    Exe.time : 656MS
    Exe.memory : 7156K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>

int cas;
char ch[11000000];

int main()
{
    int k,base;
    int i,f,cas,len;
    int yu;
    
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d",&k,&base);
        scanf("%s",ch);    
        
        yu=0;
        len=strlen(ch);
        
        for(f=0;f<len;f++)
        {
            yu*=base;
            yu+=(ch[f]-'0');
            yu%=(base-1);                    
        }
        printf("%d %d\n",k,yu);
    }
    return 0;
}
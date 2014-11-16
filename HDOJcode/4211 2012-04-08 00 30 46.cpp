******************************
    Author : townboy
    Submit time : 2012-04-08 00:30:46
    Judge Status : Accepted
    HDOJ Runid : 5728477
    Problem id : 4211
    Exe.time : 0MS
    Exe.memory : 184K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<memory.h>
int main()
{
    int len,flag,i,hash[30];
    char ch[100];
    while(gets(ch)!=NULL)
    {
        if(0==strcmp("END",ch))
        {
            break;
        }
        flag=1;
        memset(hash,0,sizeof(hash));
        len=strlen(ch);
        for(i=0;i<len;i++)
        {
            if(' '==ch[i])
            {
                continue;
            }
            if(1==hash[ch[i]-'A'])
            {
                flag=0;
                break;
            }
            hash[ch[i]-'A']=1;
        }
        if(1==flag)
        {
            printf("%s\n",ch);
        }
    }
    return 0;
}

******************************
    Author : townboy
    Submit time : 2012-03-16 14:30:52
    Judge Status : Accepted
    HDOJ Runid : 5560595
    Problem id : 2564
    Exe.time : 0MS
    Exe.memory : 224K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
char zan[10005],ch[100005];
int main()
{
    int num,i,f,ji,flag,len;
    scanf("%d",&num);
    getchar();
    for(i=0;i<num;i++)
    { 
        ji=0;
        gets(ch);
        len=strlen(ch);
        flag=1;
        for(f=0;f<len;f++)
        {
            if(1==flag)
            {
                if(' '==ch[f])
                {
                    continue;
                }
                else
                {
                    if(ch[f]<='z'&&ch[f]>='a')
                    {
                        zan[ji]=ch[f]+('A'-'a');
                        ji++;
                        flag=0;
                    }
                    else
                    {
                        zan[ji]=ch[f];
                        ji++;
                        flag=0;
                    }
                }
            }
            else
            {
                if(' '==ch[f])
                {
                    flag=1;
                    continue;
                }
                else
                {
                    continue;
                }
            }
        }
        for(f=0;f<ji;f++)
        {
            printf("%c",zan[f]);
        }
        printf("\n");
    }
    return 0;
}
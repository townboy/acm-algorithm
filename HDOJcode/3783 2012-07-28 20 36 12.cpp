******************************
    Author : townboy
    Submit time : 2012-07-28 20:36:12
    Judge Status : Accepted
    HDOJ Runid : 6365329
    Problem id : 3783
    Exe.time : 0MS
    Exe.memory : 232K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<memory.h>

char ch[1000];
char pr[10];
int zan[3];

int check()
{
    int i;
    for(i=0;i<3;i++)
    {
        if(0 != zan[i])
        return 0;
    }
    return 1;
}

int main()
{
    int i,len,flag;
    strcpy(pr,"ZOJ");
    while(scanf("%s",&ch)!=EOF)
    {
        if(0 == strcmp(ch,"E"))
            break;
        len=strlen(ch);
        memset(zan,0,sizeof(zan));
        for(i=0;i<len;i++)
        {
            if('Z' == ch[i])
                zan[0]++;
            else if('O' == ch[i])
                zan[1]++;
            else
                zan[2]++;
        }
        flag=0;
        while(1)
        {
            for(i=0;i<3;i++)
            {
                if(0 != zan[i])
                {
                    printf("%c",pr[i]);                
                    zan[i]--;
                    if(0 == zan[i])
                    {
                        if(1 == check())
                        {
                            flag=1;
                            break;
                        }
                    }
                }
            }
            if(1 == flag)
                break;
        }
        printf("\n");
    }
    return 0;
}
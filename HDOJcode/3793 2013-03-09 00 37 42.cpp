******************************
    Author : townboy
    Submit time : 2013-03-09 00:37:42
    Judge Status : Accepted
    HDOJ Runid : 7717294
    Problem id : 3793
    Exe.time : 15MS
    Exe.memory : 264K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>

int len;
char ch[110];

void move()
{
    int i,tem=ch[0];
    for(i=0;i<len-1;i++)
        ch[i]=ch[i+1];
    ch[i]=tem;
}

int check()
{
    int i;
    for(i=1;i<=len/2;i++)
        if(ch[len/2+i] != ch[len/2-i])
            return 0;
    return 1;
}

int main()
{
    int i;
    while(gets(ch)!=NULL)
    {
        if(0 == strcmp("#",ch))
            break;
        len=strlen(ch);
        for(i=0;i<len;i++)
        {
            if(1 == check())
            {
                printf("YES %d\n",(i+len/2)%len);
                break;
            }
            move();    
        }
        if(i == len)
            printf("NO\n");
    }
    return 0;
}
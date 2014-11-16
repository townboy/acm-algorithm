******************************
    Author : townboy
    Submit time : 2012-12-02 22:09:17
    Judge Status : Accepted
    HDOJ Runid : 7316362
    Problem id : 1513
    Exe.time : 281MS
    Exe.memory : 336K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>

using namespace std;

char ch[5100],chn[5100];
int len,com[2][5100];

int dp()
{
    int i,f,now,last;
    for(i=1;i<=len;i++)
    {
        for(f=1;f<=len;f++)
        {
            now=i&1;
            last=1^now;
            if(ch[i-1] == chn[f-1])
            {
                com[now][f]=com[last][f-1]+1;    
            }
            else
            {
                com[now][f]=max(com[last][f],com[now][f-1]);
            }
        }
    }
    return len-com[len&1][len];
}

void chu()
{
    memset(com,0,sizeof(com));
}

int main()
{
    int i;
    while(scanf("%d",&len)!=EOF)
    {
        chu();
        scanf("%s",ch);
        for(i=0;i<len;i++)
        {
            chn[i]=ch[len-1-i];
        }
        printf("%d\n",dp());
    }
    return 0;
}
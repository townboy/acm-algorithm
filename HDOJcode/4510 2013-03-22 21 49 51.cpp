******************************
    Author : townboy
    Submit time : 2013-03-22 21:49:51
    Judge Status : Accepted
    HDOJ Runid : 7844625
    Problem id : 4510
    Exe.time : 15MS
    Exe.memory : 260K
    https://github.com/townboy
******************************


#include<stdio.h>

int now,jian;
char ch[110];

int num(int pos)
{
    return ch[pos]-'0';
}

void init()
{
    now=jian=0;
    now=(num(0)*10+num(1))*3600+(num(3)*10+num(4))*60+num(6)*10+num(7);
    jian=(num(9)*10+num(10))*3600+(num(12)*10+num(13))*60+num(15)*10+num(16);
}

void fun()
{
    int fen,miao,shi;
    int ans=now-jian;
    while(ans < 0)
        ans+=12*60*60;
    miao=ans%60;
    ans/=60;
    fen=ans%60;
    ans/=60;
    shi=ans;
    printf("%02d:%02d:%02d\n",shi,fen,miao);
}

int main()
{
    int cas,i;
    scanf("%d",&cas);
    getchar();
    for(i=0;i<cas;i++)
    {    
        gets(ch);
        init();
        fun();
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2013-05-15 16:56:13
    Judge Status : Accepted
    HDOJ Runid : 8307877
    Problem id : 1984
    Exe.time : 0MS
    Exe.memory : 268K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>

using namespace std;

char ch[110];

int main()
{
    int i,cas,no,f;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        printf("%d ",i+1);
        scanf("%d%s",&no,ch);
        no--;
        for(f=0;ch[f];f++)
            if(f != no)    printf("%c",ch[f]);
        puts("");
    }
    return 0;
}
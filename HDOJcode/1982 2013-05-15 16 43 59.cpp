******************************
    Author : townboy
    Submit time : 2013-05-15 16:43:59
    Judge Status : Accepted
    HDOJ Runid : 8307705
    Problem id : 1982
    Exe.time : 15MS
    Exe.memory : 280K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<memory.h>
#include<iostream>

using namespace std;

char ch[11000];

int isdig(int x){
    if(x >= '0' && x <= '9')
        return 1;
    return 0;
}

int turn(int a,int b){
    a-='0';
    b-='0';
    return a*10+b;
}

int main()
{
    int f,cas,i;
    scanf("%d",&cas);
    getchar();
    for(i=0;i<cas;i++)
    {
        gets(ch);
        for(f=0;ch[f];f++)
        {
            if('#' == ch[f]){
                printf(" ");
                continue;
            }
            if('-' == ch[f])
                continue;
            if(ch[f+1]!=0 && 1==isdig(ch[f+1])){
                printf("%c",'A'+turn(ch[f],ch[f+1])-1);
                f++;
            }
            else
                printf("%c",'A'+ch[f]-'0'-1);
        }
        puts("");
    }
    return 0;
}
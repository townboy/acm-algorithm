******************************
    Author : townboy
    Submit time : 2013-04-05 15:40:00
    Judge Status : Accepted
    HDOJ Runid : 8006599
    Problem id : 1015
    Exe.time : 31MS
    Exe.memory : 264K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int len,hash[20];
char tem[20];
int tar;
string ans;
string alp="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int dfs(int pos,int sum,string str)
{
    int f,i,add;
    if(6 == pos)
    {
        if(tar == sum)
        {
            cout<<str<<endl;
            return 1;
        }
        return 0;
    }
    for(i=0;i<len;i++)
    {
        if(1 == hash[i])    continue;
        hash[i]=1;
        add=1;
        for(f=0;f<pos;f++)
            add*=(tem[i]-'A'+1);
        if(pos%2 == 0)
            add=-add;
        if(1 == dfs(pos+1,add+sum,str+alp[tem[i]-'A']))
            return 1;
        hash[i]=0;
    }
    return 0;
}

bool cmp(char a,char b)
{
    return a>b;
}

int main()
{
    int i,flag;
    while(scanf("%d%s",&tar,tem),tar)
    {
        memset(hash,0,sizeof(hash));
        len=strlen(tem);
        ans="";
        sort(tem,tem+len,cmp);
        flag=dfs(1,0,"");
        if(0 == flag)
            printf("no solution\n");
    }
    return 0;
}
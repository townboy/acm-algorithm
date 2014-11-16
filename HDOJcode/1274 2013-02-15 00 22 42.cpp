******************************
    Author : townboy
    Submit time : 2013-02-15 00:22:42
    Judge Status : Accepted
    HDOJ Runid : 7616022
    Problem id : 1274
    Exe.time : 0MS
    Exe.memory : 276K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>

using namespace std;

int len;
char ch[310];

int find(int pos)
{
    int i,sum=0;
    if('(' != ch[pos+1])
        return pos+1;
    for(i=pos+1;;i++)
    {
        if('(' == ch[i])
            sum++;
        else if(')' == ch[i])
            sum--;
        if(0 == sum)
            return i;
    }
}

string fun(int st,int ed)
{
    string tem,s;
    int t,i,f;    
    for(i=st;i<=ed;i++)
    {
        if(ch[i] <= '9' && ch[i] >= '0')
        {
            t=find(i);
            tem=fun(i+1,t);
            for(f=0;f<ch[i]-'0';f++)
                s+=tem;
            i=t;
        }
        else if('(' == ch[i] || ')' == ch[i])
            continue;
        else
            s+=ch[i];
    }
    return s;
}

int main()
{
    int i,cas;
    scanf("%d",&cas);
    getchar();
    for(i=0;i<cas;i++)
    {
        gets(ch);
        len=strlen(ch);        
        cout<<fun(0,len-1)<<endl;
    }
    return 0;
}    
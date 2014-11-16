******************************
    Author : townboy
    Submit time : 2012-10-07 21:51:47
    Judge Status : Accepted
    HDOJ Runid : 6884889
    Problem id : 2094
    Exe.time : 15MS
    Exe.memory : 252K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<map>
#include<memory.h>
#include<string>
#include<iostream>
using namespace std;

int ru[1100],id;
map<string,int>mp;

int name(string ch)
{
    if(0 == mp[ch])
    {
        id++;
        mp[ch]=id;
    }
    return mp[ch];
}

void chu()
{
    memset(ru,0,sizeof(ru));
    id=0;
    mp.clear();
}

int main()
{
    int sum,i,n;
    string ch1,ch2;
    while(scanf("%d",&n),n)
    {
        chu();
        for(i=0;i<n;i++)
        {
            cin>>ch1>>ch2;        
            name(ch1);
            ru[name(ch2)]++;
        }
        sum=0;
        for(i=1;i<=id;i++)
        {
            if(0 == ru[i])
            {
                sum++;    
            }
        }
        if(1 == sum)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
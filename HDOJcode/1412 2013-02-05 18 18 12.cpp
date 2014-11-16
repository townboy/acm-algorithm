******************************
    Author : townboy
    Submit time : 2013-02-05 18:18:12
    Judge Status : Accepted
    HDOJ Runid : 7596558
    Problem id : 1412
    Exe.time : 31MS
    Exe.memory : 892K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<map>
#include<iostream>

using namespace std;

map<int,int>mp;
int a,b;

int main()
{
    int flag;
    int i,tem;
    map<int,int>::iterator it;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        mp.clear();
        for(i=0;i<a;i++)
        {
            scanf("%d",&tem);
            mp[tem]=1;
        }
        for(i=0;i<b;i++)
        {
            scanf("%d",&tem);
            mp[tem]=1;
        }
        flag=0;
        for(it=mp.begin();it!=mp.end();it++)
        {
            if(1 == flag)
                printf(" ");
            flag=1;
            printf("%d",it->first);
        }
        printf("\n");
    }
    return 0;
}
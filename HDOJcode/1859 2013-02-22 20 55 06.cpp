******************************
    Author : townboy
    Submit time : 2013-02-22 20:55:06
    Judge Status : Accepted
    HDOJ Runid : 7642386
    Problem id : 1859
    Exe.time : 15MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>

using namespace std;

int hengs,hengb,sus,sub;

void chu()
{
    hengs=300;
    hengb=-300;
    sus=300;
    sub=-300;
}

void fun(int x,int y)
{
    hengs=min(hengs,x);
    hengb=max(hengb,x);        
    sus=min(sus,y);
    sub=max(sub,y);        
}

int main()
{
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        if(0 == x && 0 == y)
            break;
        chu();        
        fun(x,y);
        while(scanf("%d%d",&x,&y),!(0 == x && 0 == y))
        {
            fun(x,y);    
        }
        printf("%d %d %d %d\n",hengs,sus,hengb,sub);
    }
    return 0;
}
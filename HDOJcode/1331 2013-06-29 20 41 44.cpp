******************************
    Author : townboy
    Submit time : 2013-06-29 20:41:44
    Judge Status : Accepted
    HDOJ Runid : 8508863
    Problem id : 1331
    Exe.time : 15MS
    Exe.memory : 284K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#define INF 0x3f3f3f3f

using namespace std;

int val[21][21][21];

int fun(int a,int b,int c){
    if(a<=0 || b<= 0 || c<= 0)
        return 1;
    if(a>20 || b>20 || c>20)
        return fun(20,20,20);
    if(INF != val[a][b][c])
        return val[a][b][c];
    if(a < b && b < c)
        return val[a][b][c] = fun(a,b,c-1)+fun(a,b-1,c)-fun(a,b-1,c-1);
    return val[a][b][c] = fun(a-1, b, c) + fun(a-1, b-1, c) + fun(a-1, b, c-1) - fun(a-1, b-1, c-1);
}

int main()
{
    int a,b,c;
    memset(val,0x3f,sizeof(val));
    while(scanf("%d %d %d",&a,&b,&c),!(-1==a&&-1==b&&-1==c)){
        printf("w(%d, %d, %d) = %d\n",a,b,c,fun(a,b,c));
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2013-05-03 13:01:19
    Judge Status : Accepted
    HDOJ Runid : 8223142
    Problem id : 1080
    Exe.time : 0MS
    Exe.memory : 316K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<string.h>
#include<memory.h>
#define maxn 110

using namespace std;

int len1,len2;
char ch1[maxn],ch2[maxn];
int dp[maxn][maxn];

int map[4][4]={{5,-1,-2,-1},{-1,5,-3,-2},{-2,-3,5,-2},{-1,-2,-2,5}};
int dan[4]={-3,-4,-2,-1};

int id(int x){
    if('A' == x)    return 0;
    if('C' == x)    return 1;
    if('G' == x)    return 2;
    if('T' == x)    return 3;    
}

void fun(int x,int y){
    if(0 != x)
        dp[x][y]=max(dp[x][y],dp[x-1][y]+dan[id(ch1[x-1])] );
    if(0 != y)
        dp[x][y]=max(dp[x][y],dp[x][y-1]+dan[id(ch2[y-1])] );
    if(0!=x && 0!=y)
        dp[x][y]=max(dp[x][y],dp[x-1][y-1]+map[id(ch1[x-1])][id(ch2[y-1])] );    
}

int main()
{
    int cas,i,f,g;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%s",&len1,ch1);
        scanf("%d%s",&len2,ch2);
        memset(dp,0x80,sizeof(dp));
        dp[0][0]=0;
        for(f=0;f<=len1;f++)
            for(g=0;g<=len2;g++){
                if(0==f && 0==g)    continue;
                fun(f,g);
            }
        printf("%d\n",dp[len1][len2]);
    }
    return 0;
}
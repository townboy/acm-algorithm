******************************
    Author : townboy
    Submit time : 2012-11-23 14:37:06
    Judge Status : Accepted
    HDOJ Runid : 7231358
    Problem id : 2577
    Exe.time : 0MS
    Exe.memory : 292K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<string.h>
#define INF 0x7fffffff

using namespace std;

int dis[110][2],len;
char ch[110];

void chu()
{
    int i;
    for(i=0;i<=len;i++)
    {
        dis[i][0]=dis[i][1]=INF;
    }
}

void dp()
{
    int i;
    dis[0][0]=0;
    dis[0][1]=1;
    for(i=1;i<=len;i++)
    {
        if(ch[i-1] >= 'a' && ch[i-1] <= 'z')
        {
            dis[i][0]=min(dis[i-1][0]+1,dis[i][0]);
            dis[i][0]=min(dis[i-1][1]+2,dis[i][0]);
            dis[i][1]=min(dis[i-1][0]+2,dis[i][1]);
            dis[i][1]=min(dis[i-1][1]+2,dis[i][1]);
        }
        else
        {
            dis[i][0]=min(dis[i-1][0]+2,dis[i][0]);
            dis[i][0]=min(dis[i-1][1]+2,dis[i][0]);
            dis[i][1]=min(dis[i-1][0]+2,dis[i][1]);
            dis[i][1]=min(dis[i-1][1]+1,dis[i][1]);        
        }
    }
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
        chu();
        dp();
        printf("%d\n",dis[len][0]);
    }
    return 0;
}
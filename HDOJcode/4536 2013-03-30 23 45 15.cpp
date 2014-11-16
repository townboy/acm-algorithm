******************************
    Author : townboy
    Submit time : 2013-03-30 23:45:15
    Judge Status : Accepted
    HDOJ Runid : 7941884
    Problem id : 4536
    Exe.time : 15MS
    Exe.memory : 236K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int n,m,att;
int num[5],sta[5][16];
int k[16];
int a[110][3];
int belong[110];
int ans;
int yu[3][2]={1,2,0,2,0,1};

void init()
{
    ans=0;
    memset(num,0,sizeof(num));
}

int fun(int tem)
{
    int i,s=belong[tem];
    for(i=0;i<num[s];i++)
    {
        if(sta[s][i] == tem)
            k[sta[s][i]]++;
        k[sta[s][i]]++;
        if(k[sta[s][i]] > 5)
            return 0;
    }
    return 1;
}

void dfs(int pos)
{
    int i,tem[16];
    ans=max(ans,pos);
    if(pos == att)
        return ;
    for(i=0;i<3;i++)
    {
        memcpy(tem,k,sizeof(k));
        k[a[pos][i]]=max(1,k[a[pos][i]]-2);
        if(1 == fun(a[pos][yu[i][0]]) && 1 == fun(a[pos][yu[i][1]]) ) 
            dfs(pos+1);
        memcpy(k,tem,sizeof(k));
    }
}

void debug()
{
    int i,f;
    for(i=0;i<5;i++)
    {
        for(f=0;f<num[i];f++)
            printf("%d ",sta[i][f]);
        printf("\n");
    }
}

int main()
{
    int f;
    int i,cas,tem;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        init();
        scanf("%d%d%d",&n,&m,&att);
        for(f=0;f<n;f++)
        {
            scanf("%d",&tem);
            belong[f]=tem;
            sta[tem][num[tem]++]=f;
        }
        for(f=0;f<n;f++)
            scanf("%d",k+f);
        for(f=0;f<att;f++)
            scanf("%d%d%d",&a[f][0],&a[f][1],&a[f][2]);
        dfs(0);
        printf("Case #%d: %d\n",i+1,ans);
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2013-03-08 22:38:23
    Judge Status : Accepted
    HDOJ Runid : 7716588
    Problem id : 1710
    Exe.time : 15MS
    Exe.memory : 296K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<malloc.h>
#include<iostream>
#include<string>

using namespace std;

int n;
int pre[1100],in[1100];
int cixupre[1100];
int tree[1100][2];
int ans[1100],ji;

void dfs(int rt,int le,int ri)
{
    int i,minn=0,pos;
    for(i=le;i<=ri;i++)
        if(rt == in[i])
            break;
    pos=i;
    for(i++;i<=ri;i++)
    {
        if(cixupre[minn] > cixupre[in[i]])
            minn=in[i];
    }
    if(pos != le)
    {
        tree[rt][0]=pre[cixupre[rt]+1];
        dfs(tree[rt][0],le,pos-1);
    }
    if(pos != ri)
    {
        tree[rt][1]=minn;
        dfs(minn,pos+1,ri);
    }
}

void chu()
{
    memset(tree,-1,sizeof(tree));
    cixupre[0]=1000000;    
    ji=0;
}

void dfsans(int rt)
{
    if(-1 != tree[rt][0])
        dfsans(tree[rt][0]);
    if(-1 != tree[rt][1])
        dfsans(tree[rt][1]);
    ans[ji]=rt;
    ji++;
}

int main()
{
    int i;
    while(scanf("%d",&n)!=EOF)
    {
        chu();
        for(i=0;i<n;i++)
        {
            scanf("%d",pre+i);    
            cixupre[pre[i]]=i;
        }
        for(i=0;i<n;i++)
            scanf("%d",in+i);
        dfs(pre[0],0,n-1);
        dfsans(pre[0]);
        printf("%d",ans[0]);
        for(i=1;i<n;i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}
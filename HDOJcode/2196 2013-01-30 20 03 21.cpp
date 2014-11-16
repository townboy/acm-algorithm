******************************
    Author : townboy
    Submit time : 2013-01-30 20:03:21
    Judge Status : Accepted
    HDOJ Runid : 7570550
    Problem id : 2196
    Exe.time : 31MS
    Exe.memory : 724K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int longid[10100];
int longest[10100],shang[10100],second[10100];
int n,length[10100];
vector<int>map[10100];

void chu()
{
    int i;
    for(i=1;i<=n;i++)
        map[i].clear();
    memset(longest,0,sizeof(longest));
    memset(second,0,sizeof(second));
    memset(shang,0,sizeof(shang));
}

void dfs1(int root)
{
    int son,i,size=map[root].size();
    for(i=0;i<size;i++)
    {
        son=map[root][i];
        dfs1(son);
        if(longest[son]+length[son] > longest[root])
        {
            second[root]=longest[root];
            longest[root]=longest[son]+length[son];
            longid[root]=son;
        }
        else if(longest[son]+length[son] > second[root])
            second[root]=longest[son]+length[son];
    }
}

void dfs2(int root)
{
    int son,i,size=map[root].size();
    for(i=0;i<size;i++)
    {
        son=map[root][i];
        if(longid[root] == son)
            shang[son]=max(shang[root],second[root])+length[son];
        else
            shang[son]=max(shang[root],longest[root])+length[son];
        dfs2(son);
    }
}

int main()
{
    int i,fa,len;
    while(scanf("%d",&n)!=EOF)
    {
        chu();
        for(i=2;i<=n;i++)
        {
            scanf("%d%d",&fa,&len);
            map[fa].push_back(i);
            length[i]=len;
        }
        dfs1(1);
        dfs2(1);
        for(i=1;i<=n;i++)
            printf("%d\n",max(longest[i],shang[i]));
    }
    return 0;
}
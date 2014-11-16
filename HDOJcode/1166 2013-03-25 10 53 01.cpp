******************************
    Author : townboy
    Submit time : 2013-03-25 10:53:01
    Judge Status : Accepted
    HDOJ Runid : 7874604
    Problem id : 1166
    Exe.time : 218MS
    Exe.memory : 1596K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>

#define INF 0x3f3f3f3f
#define maxn 50010
#define keyTree son[ son[rt][1] ][0]

using namespace std;

int n,tem[maxn];

struct SplayTree
{
    int size,rt,sum[maxn];
    int num[maxn],son[maxn][2],fa[maxn],val[maxn];
    
    void Link(int x,int y,int c)
    {
        fa[x]=y;
        son[y][c]=x;
    }
    
    void Rotate(int x,int c)
    {
        int y=fa[x];
        Link(x,fa[y],son[fa[y]][1]==y);
        Link(son[x][!c],y,c);
        Link(y,x,!c);
        Update(y);
    }
    
    void Splay(int x,int g)
    {
        int y,cx,cy;
        for(;fa[x]!=g;)
        {
            y=fa[x];
            cx=(son[y][1]==x);
            cy=(son[fa[y]][1]==y);
            if(fa[y] == g)    Rotate(x,cx);
            else
            {
                if(cx == cy)    Rotate(y,cy);
                else    Rotate(x,cx);
                Rotate(x,cy);
            }
        }
        Update(x);
        if(0 == g)
            rt=x;
    };
    
    void Select(int k,int g)
    {
        int x=rt;
        while(num[son[x][0]] != k)
        {
            if(k < num[son[x][0]])
                x=son[x][0];
            else
            {
                k-=1+num[son[x][0]];
                x=son[x][1];
            }
        }
        Splay(x,g);
    }
    
    void NewNode(int y,int &x,int tem)
    {
        x=++size;
        fa[x]=y;
        val[x]=tem;
        num[x]=1;
        son[x][0]=son[x][1]=0;
    }
    
    void makeTree(int l,int r,int &x,int f)
    {
        int m=(l+r)>>1;
        if(l > r)    return ;
        NewNode(f,x,tem[m]);
        makeTree(l,m-1,son[x][0],x);
        makeTree(m+1,r,son[x][1],x);
        Update(x);
    }
    
    void Init()
    {
        num[0]=0;
        val[0]=0;
        NewNode(size=0,rt,0);
        NewNode(rt,son[rt][1],0);
        makeTree(0,n-1,keyTree,son[rt][1]);
        Update(son[rt][1]);
        Update(rt);
    }
    
    void Update(int x)
    {
        num[x]=num[son[x][0]]+num[son[x][1]]+1;
        sum[x]=sum[son[x][0]]+sum[son[x][1]]+val[x];
    }
    
    void Add(int x,int y)
    {
        Select(x,0);
        val[rt]+=y;
        Update(rt);
    }
    
    void Ans(int x,int y)
    {
        Select(x-1,0);
        Select(y+1,rt);
        printf("%d\n",sum[keyTree]);
    }
    
    void debug()
    {
        printf("Root == %d\n",rt);
        dfs(rt);
    }
    
    void dfs(int x)
    {
        if(0 == x)
            return ;
        dfs(son[x][0]);
        printf("½áµã%2d: ×ó¶ù×Ó%2d  ÓÒ¶ù×Ó%2d  ¸¸½áµã%2d val =%2d size =%2d\n",x,son[x][0],son[x][1],fa[x],val[x],num[x]);
        dfs(son[x][1]);
    }
};
struct SplayTree spt;

int main()
{
    char ch[10];
    int i,x,y,cas,f;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        printf("Case %d:\n",i+1);
        scanf("%d",&n);
        for(f=0;f<n;f++)
            scanf("%d",tem+f);
         spt.Init();
        getchar();
        while(scanf("%s",ch)!=EOF)
        {
            if('E' == ch[0])    break;
            scanf("%d%d",&x,&y);
            if('Q' == ch[0])
                spt.Ans(x,y);
            else if('A' == ch[0])
                spt.Add(x,y);
            else if('S' == ch[0])
                spt.Add(x,-y);
        }
    }
    return 0;
}
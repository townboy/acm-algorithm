******************************
    Author : townboy
    Submit time : 2013-03-26 22:17:54
    Judge Status : Accepted
    HDOJ Runid : 7894780
    Problem id : 1698
    Exe.time : 1546MS
    Exe.memory : 2968K
    https://github.com/townboy
******************************


#include<stdio.h>

#define keyTree son[son[rt][1]][0]
#define maxn 100010
int n,m;                // Push_Down() µÄ×÷ÓÃÊÇÈÃlazy±ê¼Ç´«µÝÏÂÈ¥
                        // Update() µÄ×÷ÓÃÊÇ±£Ö¤¸Ã½ÚµãµÄ×´Ì¬ÕýÈ·¡£
struct SplayTree         // lazy´ú±íÒÔxÎª¸ù½ÚµãµÄ×ÓÊ÷Ëù¾ßÓÐµÄµÄÐÔÖÊ¡£
{
    int size,rt,num[maxn];
    int son[maxn][2],fa[maxn],val[maxn],lazy[maxn],sum[maxn];
    
    void Link(int x,int y,int c)
    {
        fa[x]=y;
        son[y][c]=x;
    }
    
    void Rotate(int x,int c)
    {
        int y=fa[x];
        Push_Down(y);
        Push_Down(x);
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
    
    void Update(int x)
    {
        num[x]=1+num[son[x][0]]+num[son[x][1]];
        sum[x]=val[x];
        if(0 == son[x][0])
        {}
        if(0 == lazy[son[x][0]])
            sum[x]+=sum[son[x][0]];
        else 
            sum[x]+=num[son[x][0]]*lazy[son[x][0]];
        if(0 == son[x][1])
        {}
        if(0 == lazy[son[x][1]])
            sum[x]+=sum[son[x][1]];
        else 
            sum[x]+=num[son[x][1]]*lazy[son[x][1]];
    }
    
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
        lazy[x]=0;
    }
    
    void makeTree(int l,int r,int &x,int f)
    {
        int m=(l+r)>>1;
        if(l > r)    return ;
        NewNode(f,x,1);
        makeTree(l,m-1,son[x][0],x);
        makeTree(m+1,r,son[x][1],x);
        Update(x);
    }
    
    void Init()
    {
        val[0]=0;
        num[0]=0;
        NewNode(size=0,rt,0);
        NewNode(rt,son[rt][1],0);
        makeTree(0,n-1,keyTree,son[rt][1]);
        Update(son[rt][1]);
        Update(rt);
    }
    
    void Ans(int tem)
    {
        Select(0,0);
        Select(n+1,rt);
        Push_Down(keyTree);
        printf("Case %d: The total value of the hook is %d.\n",tem,sum[keyTree]);
    }
    
    void Push_Down(int x)        //º¬ÒåÊÇ½²µ±Ç°µÄlzay±ê¼Ç´«µÝÏÂÈ¥
    {
        if(0 != lazy[x])
        {
            val[x]=lazy[x];
            sum[x]=num[x]*lazy[x];
            lazy[son[x][0]]=lazy[son[x][1]]=lazy[x];
        }
        lazy[x]=0;
    }
    
    void Change(int x,int y,int val)
    {
        Select(x-1,0);
        Select(y+1,rt);
        lazy[keyTree]=val;
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
    int i,cas,f,x,y,val;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d",&n,&m);
        spt.Init();
        for(f=0;f<m;f++)
        {
            scanf("%d%d%d",&x,&y,&val);
            spt.Change(x,y,val);
        }
        spt.Ans(i+1);
    }
    return 0;
}
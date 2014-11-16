******************************
    Author : townboy
    Submit time : 2013-03-09 00:09:29
    Judge Status : Accepted
    HDOJ Runid : 7717183
    Problem id : 3791
    Exe.time : 0MS
    Exe.memory : 272K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int cas;
int tree[20][2],stdand[20][2];
int root,stdrt;

int compare()
{
    int i;
    if(stdrt != root)
        return 0;
    for(i=0;i<10;i++)
        if(tree[i][0] != stdand[i][0] || tree[i][1] != stdand[i][1])
            return 0;
    return 1;
}

void init()
{
    memset(tree,-1,sizeof(tree));
}

void add(int tem,int rt)
{
    if(rt == tem)
        return ;
    if(rt < tem)
    {
        if(-1 == tree[rt][0])
            tree[rt][0]=tem;
        else
            add(tem,tree[rt][0]);
    }
    else
    {
        if(-1 == tree[rt][1])
            tree[rt][1]=tem;
        else
            add(tem,tree[rt][1]);
    }
}

void build()
{
    int i;
    char tem[20];
    gets(tem);
    init();
    root=tem[0]-'0';
    for(i=1;tem[i];i++)
        add(tem[i]-'0',root);
}

int main()
{
    int i;
    while(scanf("%d",&cas),cas)
    {
        getchar();
        
        build();
        for(i=0;i<10;i++)
        {
            stdand[i][0]=tree[i][0];
            stdand[i][1]=tree[i][1];
        }
        stdrt=root;
        
        for(i=0;i<cas;i++)
        {
            build();
            if(1 == compare())
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
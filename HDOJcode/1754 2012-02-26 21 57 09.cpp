******************************
    Author : townboy
    Submit time : 2012-02-26 21:57:09
    Judge Status : Accepted
    HDOJ Runid : 5420678
    Problem id : 1754
    Exe.time : 515MS
    Exe.memory : 7148K
    https://github.com/townboy
******************************


#include<stdio.h>
int zan[300000];
struct node 
{
    int l;
    int r;
    int max;
}; 
struct node que[1000000];
void pushup(int rt)
{
    if(que[rt*2].max>que[rt*2+1].max)
    {
        que[rt].max=que[rt*2].max;
    }
    else
    {
        que[rt].max=que[rt*2+1].max;
    }
}
void update(int rt)
{
    if(1!=rt)
    {
        pushup(rt);
        rt=rt/2;
        update(rt);
    }
    else
    {
        pushup(rt);
    }
}
void build(int l,int r,int rt)
{
    int m;
    if(l==r)
    {
        que[rt].r=r;
        que[rt].l=l;
        que[rt].max=zan[l];
        return ;
    }
    m=(l+r)/2;
    que[rt].l=l;
    que[rt].r=r;
    build(l,m,rt*2);
    build(m+1,r,rt*2+1);
    pushup(rt);
}
void same(int x,int val,int rt)
{
    int m;
    if(que[rt].l==que[rt].r)
    {
        que[rt].max=val;
        update(rt/2);
        return ;
    }
    m=(que[rt].l+que[rt].r)/2;
    if(x<=m)
    {
        same(x,val,rt*2);
    }
    else
    {
        same(x,val,rt*2+1);
    }
}
int query(int l,int r,int rt)
{
    int max=0,m,j;
    m=(que[rt].l+que[rt].r)/2;
    if(l<=que[rt].l&&r>=que[rt].r)
    {
        return que[rt].max;
    }
    if(l<=m)
    {
        j=query(l,r,rt*2);
        if(max<j)
        {
            max=j;
        }
    }
    if(r>m)
    {
        j=query(l,r,rt*2+1);
        if(max<j)
        {
            max=j;
        }
    }
    return max;
} 
int main()
{
    int n,z,i,z1,z2,res;
    char ch[100];
    while(scanf("%d%d",&n,&z)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&zan[i]);
        }
        build(1,n,1);
        for(i=0;i<z;i++)
        {
            scanf("%s%d%d",ch,&z1,&z2);
            if('U'==ch[0])
            {
                same(z1,z2,1);
            }
            else
            {
                res=query(z1,z2,1);
                printf("%d\n",res);
            }
        }
    }
    return 0;
}

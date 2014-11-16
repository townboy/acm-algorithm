******************************
    Author : townboy
    Submit time : 2012-02-26 22:03:58
    Judge Status : Accepted
    HDOJ Runid : 5420738
    Problem id : 1754
    Exe.time : 500MS
    Exe.memory : 7148K
    https://github.com/townboy
******************************


#include<stdio.h>
#define rtl rt<<1
#define rtr rt<<1|1
#define rtf rt>>1
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
    if(que[rtl].max>que[rtr].max)
    {
        que[rt].max=que[rtl].max;
    }
    else
    {
        que[rt].max=que[rtr].max;
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
    build(l,m,rtl);
    build(m+1,r,rtr);
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
        same(x,val,rtl);
    }
    else
    {
        same(x,val,rtr);
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
        j=query(l,r,rtl);
        if(max<j)
        {
            max=j;
        }
    }
    if(r>m)
    {
        j=query(l,r,rtr);
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

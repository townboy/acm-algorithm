******************************
    Author : townboy
    Submit time : 2012-02-29 19:25:19
    Judge Status : Accepted
    HDOJ Runid : 5437414
    Problem id : 2795
    Exe.time : 1765MS
    Exe.memory : 6360K
    https://github.com/townboy
******************************


#include<stdio.h>
int h,w,n;
struct node 
{
    int l;
    int r;
    int max;
};
struct node q[210000*4];
void build(int l,int r,int rt)
{
    int m;
    q[rt].l=l;
    q[rt].r=r;
    q[rt].max=w;
    if(l==r)
    {
        return ;
    }
    m=(l+r)>>1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
}
void update(int rt)
{
    if(0==rt)
    {
        return ;
    }
    if(q[rt<<1].max>q[rt<<1|1].max)
    {
        q[rt].max=q[rt<<1].max;
    }
    else
    {
        q[rt].max=q[rt<<1|1].max;    
    }
    if(1==rt)
    {
        return ;
    }
    update(rt>>1);
}
int query(int x,int rt)
{
    int m;
    if(x>q[rt].max)
    {
        return -1;
    }
    if(q[rt].l==q[rt].r)
    {
        q[rt].max=q[rt].max-x;
        update(rt>>1);
        return q[rt].l;
    }
    m=(q[rt].l+q[rt].r)>>1;
    if(x<=q[rt<<1].max)
    {
        return query(x,rt<<1);
    }
    if(x<=q[rt<<1|1].max)
    {
        return query(x,rt<<1|1);
    }
}
int main()
{
    int i,x;
    while(scanf("%d%d%d",&h,&w,&n)!=EOF)
    {
        if(h<=n)
        {
            build(1,h,1);
        }
        else
        {
            build(1,n,1);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            printf("%d\n",query(x,1));
        }
    }
    return 0;
}
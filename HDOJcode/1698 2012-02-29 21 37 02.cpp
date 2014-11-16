******************************
    Author : townboy
    Submit time : 2012-02-29 21:37:02
    Judge Status : Accepted
    HDOJ Runid : 5438963
    Problem id : 1698
    Exe.time : 484MS
    Exe.memory : 3280K
    https://github.com/townboy
******************************


#include<stdio.h>
struct node 
{
    int l;
    int r;
    int c;
};
struct node q[101000*4];
void build(int l,int r,int rt)
{
    int m;
    q[rt].l=l;
    q[rt].r=r;
    q[rt].c=1;
    if(l==r)
    {
        return ;
    }
    m=(l+r)>>1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
}
void add(int l,int r,int col,int rt)
{
    int m;
    if(q[rt].l>=l&&q[rt].r<=r)
    {
        q[rt].c=col;
        return ;
    }
    if(-1!=q[rt].c)
    {
        q[rt<<1].c=q[rt].c;
        q[rt<<1|1].c=q[rt].c;
        if(q[rt].c!=col)
        {
            q[rt].c=-1;
        }
    }
    m=(q[rt].l+q[rt].r)>>1;
    if(l<=m)
    {
        add(l,r,col,rt<<1);
    }
    if(r>m)
    {
        add(l,r,col,rt<<1|1);
    }
}
int query(int l,int r,int rt)
{
    int fan;
    fan=0;
    if(-1!=q[rt].c)
    {
        return (q[rt].r-q[rt].l+1)*q[rt].c;
    }
    fan=query(l,r,rt<<1)+query(l,r,rt<<1|1);
    return fan;
}
int main()
{
    int i,f,n,num,k,l,r,col;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        build(1,n,1);
        scanf("%d",&k);
        for(f=0;f<k;f++)
        {
            scanf("%d%d%d",&l,&r,&col);
            add(l,r,col,1);
        }
        printf("Case %d: The total value of the hook is %d.\n",i+1,query(1,n,1));
    }
    return 0;
}
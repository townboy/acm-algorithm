******************************
    Author : townboy
    Submit time : 2012-02-29 00:25:06
    Judge Status : Accepted
    HDOJ Runid : 5433382
    Problem id : 1394
    Exe.time : 46MS
    Exe.memory : 268K
    https://github.com/townboy
******************************


#include<stdio.h>
struct node 
{
    int l;
    int r;
    int sum;
};
struct node que[6000*4];
void build(int l,int r,int rt)
{
    int m;
    que[rt].l=l;
    que[rt].r=r;
    que[rt].sum=0;
    if(l==r)
    {
        return ;
    }
    m=(l+r)>>1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
}
int query(int l,int r,int rt)
{
    int m,fan;
    if(que[rt].l>=l&&que[rt].r<=r)
    {
        return que[rt].sum;
    }
    fan=0;
    m=(que[rt].l+que[rt].r)>>1;
    if(l<=m)
    {
        fan=fan+query(l,r,rt<<1);
    }
    if(r>m)
    {
        fan=fan+query(l,r,rt<<1|1);    
    }
    return fan;
}
void update(int rt)
{
    if(1!=rt)
    {
        que[rt].sum=que[rt<<1].sum+que[rt<<1|1].sum;
        update(rt>>1);
    }
    else
    {
        que[rt].sum=que[rt<<1].sum+que[rt<<1|1].sum;
        return ;
    }
}
void add(int x,int rt)
{
    int m;
    if(que[rt].l==que[rt].r)
    {
        que[rt].sum++;
        update(rt>>1);
        return ;
    }
    m=(que[rt].l+que[rt].r)>>1;
    if(x<=m)
    { 
        add(x,rt<<1);
    }
    else
    {
        add(x,rt<<1|1);
    }
}
int main()
{
    int sum,res,i,zan[6000],n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&zan[i]);
        }
        build(0,n-1,1);
        add(zan[0],1);
        sum=0;
        for(i=1;i<n;i++)
        {
            sum=sum+query(zan[i]+1,n-1,1);
            add(zan[i],1);
        }
        res=sum;
        for(i=0;i<n-1;i++)
        {      
            sum=sum-zan[i]+(n-1-zan[i]);
            if(sum<res)
            {
                res=sum;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-03-05 22:24:08
    Judge Status : Accepted
    HDOJ Runid : 5476718
    Problem id : 3308
    Exe.time : 281MS
    Exe.memory : 5752K
    https://github.com/townboy
******************************


#include<stdio.h>
struct node 
{
    int l;
    int r;
    int lm;
    int rm;
    int mm;
};
struct node q[110000*4];
int val[110000];

int max(int a,int b,int c)
{
    int max;
    max=a;
    if(b>max)
    {
        max=b;
    }
    if(c>max)
    {
        max=c;
    }
    return max;
}

int min(int a,int b)
{
    if(a<b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void pushup(int rt)
{
    int m;
    m=(q[rt].l+q[rt].r)>>1;
    if(val[m]<val[m+1])
    {
        if(q[rt<<1].lm==(m-q[rt].l+1))
        {
            q[rt].lm=q[rt<<1].lm+q[rt<<1|1].lm;
        }
        else
        {
            q[rt].lm=q[rt<<1].lm;
        }
        if(q[rt<<1|1].rm==(q[rt].r-m))
        {
            q[rt].rm=q[rt<<1].rm+q[rt<<1|1].rm;
        }   
        else
        {
            q[rt].rm=q[rt<<1|1].rm;
        }
        q[rt].mm=max(q[rt<<1].mm,q[rt<<1|1].mm,q[rt<<1].rm+q[rt<<1|1].lm);
    }
    else
    {
        q[rt].lm=q[rt<<1].lm;
        q[rt].rm=q[rt<<1|1].rm;
        q[rt].mm=max(q[rt<<1].mm,q[rt<<1|1].mm,0);
    }
}

void build(int l,int r,int rt)
{
    int m;
    q[rt].l=l;
    q[rt].r=r;
    if(l==r)
    {
        q[rt].lm=1;
        q[rt].rm=1;
        q[rt].mm=1;
        return ;
    }
    m=(l+r)>>1;
    q[rt].lm=0;
    q[rt].rm=0;
    q[rt].mm=0;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushup(rt);
}

void update(int rt)
{
    while(0!=rt)
    {
        pushup(rt);
        rt=rt>>1;
    }
}
 
void rep(int x,int n,int rt)
{
    int m;
    if(q[rt].l==q[rt].r)
    {
        val[q[rt].l]=x;
        update(rt>>1);
        return ;
    }
    m=(q[rt].l+q[rt].r)>>1;
    if(n<=m)
    {
        rep(x,n,rt<<1);
    }
    else
    {
        rep(x,n,rt<<1|1);
    }
}

int  query(int l,int r,int rt)
{
    int m,lm,rm,mm;
    m=(q[rt].l+q[rt].r)>>1;
    if(l<=q[rt].l&&r>=q[rt].r)
    {
        return q[rt].mm;
    }
    else if(r<=m)
    {
        return query(l,r,rt<<1);
    }
    else if(l>m)
    {
        return query(l,r,rt<<1|1);
    }
    else
    {
        lm=query(l,r,rt<<1);
        rm=query(l,r,rt<<1|1);
        mm=max(lm,rm,0);
        if(val[m]<val[m+1])
        {
            mm=max(lm,rm,min(q[rt<<1].rm,m-l+1)+min(q[rt<<1|1].lm,r-m));
        }
        return mm;
    }
}

int main()
{
    int num,i,f,n,k,a,b,res;
    char ch[10];
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&n,&k);
        for(f=0;f<n;f++)
        {
            scanf("%d",&val[f]);
        }
        build(0,n-1,1);
        for(f=0;f<k;f++)
        {
            scanf("%s%d%d",ch,&a,&b);
            if('Q'==ch[0])
            {
                res=query(a,b,1);
                printf("%d\n",res);
            }
            else
            {
                rep(b,a,1);
            }
        }
    }
    return 0;
}
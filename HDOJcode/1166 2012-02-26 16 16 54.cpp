******************************
    Author : townboy
    Submit time : 2012-02-26 16:16:54
    Judge Status : Accepted
    HDOJ Runid : 5418220
    Problem id : 1166
    Exe.time : 46MS
    Exe.memory : 1940K
    https://github.com/townboy
******************************


#include<stdio.h>
int zan[60000];
struct node
{
    int l;
    int r;
    int max;
};
struct node que[4*60000];
void pushup(int rt)
{
    que[rt].max=que[rt*2].max+que[rt*2+1].max;
}
int query(int l,int r,int rt)
{
    int fan,m;
    if(l<=que[rt].l&&r>=que[rt].r)
    {
        return que[rt].max;
    }
    fan=0;
    m=(que[rt].l+que[rt].r)/2;
    if(l<=m)
    {
        fan=fan+query(l,r,rt*2);
    }
    if(r>m)
    {
        fan=fan+query(l,r,rt*2+1);
    }
    return fan;
}
void build(int l,int r,int rt)
{
    int m;
    if(l==r)
    {
        que[rt].l=l;
        que[rt].r=r;
        que[rt].max=zan[l];
        return ;
    }
    que[rt].l=l;
    que[rt].r=r;
    m=(l+r)/2;
    build(l,m,rt*2);
    build(m+1,r,rt*2+1);
    pushup(rt);
}
void add(int z,int x,int rt)
{
    int m;
    if(que[rt].l==que[rt].r)
    {
        que[rt].max=que[rt].max+z;
        return ;
    }
    m=(que[rt].l+que[rt].r)/2;
    que[rt].max=que[rt].max+z;
    if(x<=m)
    {
        add(z,x,rt*2);
    }
    else
    {
        add(z,x,rt*2+1);
    }
}
int main()
{
    int num,i,f,res,n,z1,z2;
    char ch[100];
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        printf("Case %d:\n",i+1);
        for(f=1;f<=n;f++)
        {
            scanf("%d",&zan[f]);
        }
        build(1,n,1);
        while(scanf("%s",ch),ch[0]!='E')
        {
            scanf("%d%d",&z1,&z2);
            if('A'==ch[0])
            { 
                add(z2,z1,1);
            }
            else if('S'==ch[0])
            {
                add(-z2,z1,1);
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
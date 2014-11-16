******************************
    Author : townboy
    Submit time : 2012-03-07 13:43:53
    Judge Status : Accepted
    HDOJ Runid : 5489043
    Problem id : 1542
    Exe.time : 15MS
    Exe.memory : 248K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
int ji;
double h[270],z[270];

int max1(int a,int b)
{
    if(a<b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int min1(int a,int b)
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


int cmp1(const void *a,const void *b)
{
    if(*(double *)a>*(double *)b)
    {
        return 1;    
    }
    else
    {
        return -1;
    }
}

int cmp3(const void *a,const void *b)
{
    if(*(double *)a<*(double *)b)
    {
        return 1;    
    }
    else
    {
        return -1;
    }
}

struct bian 
{
    double l;
    double r;
    double z;
    int type;
};
struct bian q[300];

struct node 
{
    int l;
    int r;
    int cnt;
};
struct node que[300*4];

int cmp2(const void *a,const void *b)
{
    if((*(struct bian *)a).z<(*(struct bian *)b).z)
    {
        return 1;    
    }
    else
    {
        return -1;
    }
}

void build(int l,int r,int rt)
{
    int m;
    que[rt].l=l;
    que[rt].r=r;
    que[rt].cnt=0;
    if(l==r)
    {
        return ;
    }
    m=(l+r)>>1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
}

void add(int x,int l,int r,int rt)
{
    int m;
    m = (que[rt].l+que[rt].r)>>1;
    if(l<=que[rt].l&&r>=que[rt].r)
    {
        if(-1!=que[rt].cnt)
        {
            que[rt].cnt=que[rt].cnt+x;
        }
        else
        {
            add(x,l,r,rt<<1);
            add(x,l,r,rt<<1|1);
        }
    }
    else
    {
        if(-1!=que[rt].cnt)
        {
            que[rt<<1].cnt=que[rt].cnt;
            que[rt<<1|1].cnt=que[rt].cnt;
            que[rt].cnt=-1;
        }
        if(l<=m)
        {
            add(x,l,r,rt<<1);
        }
        if(r>m)
        {
            add(x,l,r,rt<<1|1);
        }
    }
}
 
double query(int l,int r,int rt)
{
    int m;
    double fan;
    if(-1 != que[rt].cnt)
    {
        if(0==que[rt].cnt)
        {
            return 0;
        }
        else
        {
            fan=h[min1(r,que[rt].r)+1]-h[max1(l,que[rt].l)];
            return fan;
        }
    }
    else
    {
        fan=0;
        m = (que[rt].l+que[rt].r)>>1;
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
}

int find(double x)
{
    int l,r,mid;
    l=0;
    r=ji-1;
    while(r>=l)
    {
        mid=(l+r)>>1;
        if(x==h[mid])
        {
            return mid;
        }
        else
        {
            if(x<h[mid])
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
    }
    return -1;
}

int main()
{
    int i,num,tex;
    double sum,x1,x2,y1,y2;
    tex=0;
    while(scanf("%d",&num),num)
    {
        tex++;
        ji=0;
        for(i=0;i<num;i++)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            q[ji].l = x1;
            q[ji+1].l = x1;
            q[ji].r = x2;
            q[ji+1].r = x2;
            q[ji].z = y1;
            q[ji].type = -1;
            q[ji+1].z = y2;
            q[ji+1].type = 1;
            h[ji] = x1;
            h[ji+1] = x2;
            z[ji] = y1;
            z[ji+1] = y2;
            ji = ji+2;
        }
        qsort(q,ji,sizeof(q[0]),cmp2);
        qsort(h,ji,sizeof(h[0]),cmp1);
        qsort(z,ji,sizeof(z[0]),cmp3);
        build(0,ji-2,1);
        sum=0;
        for(i=0;i<ji-1;i++)
        {
            add(q[i].type,find(q[i].l),find(q[i].r)-1,1);
            sum=sum+(z[i]-z[i+1])*query(0,ji-1,1);
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n",tex,sum);
        printf("\n");
    }
    return 0;
}
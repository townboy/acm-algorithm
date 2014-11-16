******************************
    Author : townboy
    Submit time : 2012-03-07 14:39:38
    Judge Status : Accepted
    HDOJ Runid : 5489412
    Problem id : 1542
    Exe.time : 46MS
    Exe.memory : 472K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>

int map[300][300],num;
double h[300],z[300];

struct node 
{
    double x1;
    double x2;
    double y1;
    double y2;
};
struct node que[200];

void chu(int x)
{
    int i,f;
    for(i=0;i<=x;i++)
    {
        for(f=0;f<=x;f++)
        {
            map[i][f]=0;
        }
    }
}
int cmp(const void *a,const void *b)
{ 
    if(*(double *)a-*(double *)b>0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int find2(double x)
{
    int l,r,mid;
    l=0;
    r=2*num-1;
    while(r>=l)
    {
        mid=(l+r)>>1;
        if(x==z[mid])
        {
            return mid;
        }
        else
        {
            if(x<z[mid])
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
    }
}

int find1(double x)
{
    int l,r,mid;
    l=0;
    r=2*num-1;
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
    int ji,i,f,g;
    double sum,x1,x2,y1,y2;
    ji=0;
    while(scanf("%d",&num),num)
    {
        ji++;
        chu(num*2);
        for(i=0;i<num;i++)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            que[i].x1=x1;
            que[i].x2=x2;
            que[i].y1=y1;
            que[i].y2=y2;
            h[2*i]=x1;
            h[2*i+1]=x2;
            z[2*i]=y1;
            z[2*i+1]=y2;
        }
        qsort(h,num*2,sizeof(h[0]),cmp);
        qsort(z,num*2,sizeof(z[0]),cmp);
        for(i=0;i<num;i++)
        {
            for(f=find1(que[i].x1);f<=find1(que[i].x2)-1;f++)
            {
                for(g=find2(que[i].y1);g<=find2(que[i].y2)-1;g++)
                {
                   map[f][g]=1;
                }
            }
            sum=0;
        }
        for(f=0;f<=2*num-2;f++)
        {
            for(g=0;g<=2*num-2;g++)
            {
                if(1==map[f][g])
                {
                    sum=sum+(h[f+1]-h[f])*(z[g+1]-z[g]);
                }
            }
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n",ji,sum);
    }
    return 0;
}
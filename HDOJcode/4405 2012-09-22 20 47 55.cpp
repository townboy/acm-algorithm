******************************
    Author : townboy
    Submit time : 2012-09-22 20:47:55
    Judge Status : Accepted
    HDOJ Runid : 6817796
    Problem id : 4405
    Exe.time : 0MS
    Exe.memory : 1308K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int n,m,set[110000];
double p[110000];

void chu()
{
    int i;
    for(i=0;i<=n;i++)
    {
        set[i]=i;
    }
}

int find(int x)
{
    return x==set[x]?x:set[x]=find(set[x]);
}

void merge(int a,int b)
{
    set[a]=b;
}

int main()
{
    double sum;
    int l,r,i,f;
    while(scanf("%d%d",&n,&m),n+m)
    {
        chu();
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&l,&r);
            merge(find(l),find(r));
        }
        for(i=n;i<n+6;i++)
        {
            p[i]=0;
        }
        for(i=n-1;i>=0;i--)
        {
            if(set[i] != i)
            {
                p[i]=p[find(i)];
                continue;            
            }
            sum=0;
            for(f=1;f<=6;f++)
            {
                sum+=p[i+f];
            }
            p[i]=sum/6+1;
        }
        printf("%.4lf\n",p[0]);
    }
    return 0;
}
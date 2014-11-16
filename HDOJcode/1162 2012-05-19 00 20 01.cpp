******************************
    Author : townboy
    Submit time : 2012-05-19 00:20:01
    Judge Status : Accepted
    HDOJ Runid : 5963754
    Problem id : 1162
    Exe.time : 0MS
    Exe.memory : 292K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int set[110],ru,ji,n;
double sum;

struct point 
{
    double x;
    double y;
};
struct point q[110];

struct node 
{
    int x;
    int y;
    double len;
};
struct node bian[6000];

int cmp(const void *a,const void *b)
{
     if((*(struct node *)a).len-(*(struct node *)b).len > 0)
     {
        return 1;
     }
     return -1;
}

void chu()
{
    int i;
    for(i=0;i<n;i++)
    {
        set[i]=i;
    }
    ji=-1;
    sum=0;
    ru=0;
}

int find(int x)
{
    while(x != set[x])
    {
        x=set[x];
    }
    return x;
}

void merge(int a,int b)
{
    set[a]=b;
}

int main()
{
    int i,f;
    while(scanf("%d",&n)!=EOF)
    {
        chu();
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf",&q[i].x,&q[i].y);
        }
        for(i=0;i<n;i++)
        {
            for(f=i+1;f<n;f++)
            {
                ji++;
                bian[ji].x=i;
                bian[ji].y=f;
                bian[ji].len=sqrt((q[i].x-q[f].x)*(q[i].x-q[f].x)+(q[i].y-q[f].y)*(q[i].y-q[f].y));
            }
        }
        ji++;
        qsort(bian,ji,sizeof(bian[0]),cmp);
        
        for(i=0;;i++)
        {
            if(find(bian[i].x) == find(bian[i].y) )
            {
                continue;
            }
            ru++;
            sum+=bian[i].len;
            merge(find(bian[i].x),find(bian[i].y));
            if(ru == n-1)
            {
                break;
            }
        }    
        printf("%.2lf\n",sum);
    }
    return 0;
}
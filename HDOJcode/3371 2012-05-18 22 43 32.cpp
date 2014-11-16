******************************
    Author : townboy
    Submit time : 2012-05-18 22:43:32
    Judge Status : Accepted
    HDOJ Runid : 5963213
    Problem id : 3371
    Exe.time : 578MS
    Exe.memory : 432K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int x;
    int y;
    int len;
};
struct node q[30000];

int cmp(const void *a,const void *b)
{    
    return (*(struct node *)a).len-(*(struct node *)b).len;
}

int sum,set[600],n,ji;

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        set[i]=i;
    }
    sum=0;
    ji=0;
}

int find(int x)
{
    int root=x,q;
    while(root!=set[root])
    {
        root=set[root];
    }
    return root;
}

void merge(int a,int b)
{
    set[b]=a;
}

int main()
{
    int m,j,x,y,num,f,i,g,k,a,b;
    scanf("%d",&num);
    
    for(i=0;i<num;i++)
    {
        scanf("%d%d%d",&n,&m,&k);
        
        chu();
        for(f=0;f<m;f++)
        {
            scanf("%d%d%d",&q[f].x,&q[f].y,&q[f].len);
        }
        qsort(q,m,sizeof(q[0]),cmp);
        for(f=0;f<k;f++) 
        {
            scanf("%d%d",&j,&x);
            for(g=0;g<j-1;g++)
            {
                scanf("%d",&y);
                merge(find(x),find(y));
            }
        }
        for(f=1;f<=n;f++)
        {
            if(f == set[f])
            {
                ji++;
            }
        }
        j=0;
        if(1 == ji)
        {
            printf("0\n");
            continue;
        }
        for(f=0;f<m;f++)
        {
            a=find(q[f].x);
            b=find(q[f].y);
            if(a == b)
            {
                continue;
            }
    
            j++;
            sum+=q[f].len;
            merge(a,b);
            if(j == ji-1)
            {
                break;
            }
        }
        if(m == f)
        {
            printf("-1\n");    
        }
        else
        {
            printf("%d\n",sum);
        }
    }
    return 0;
}
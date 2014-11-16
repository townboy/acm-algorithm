******************************
    Author : townboy
    Submit time : 2012-06-15 14:51:01
    Judge Status : Accepted
    HDOJ Runid : 6069076
    Problem id : 1301
    Exe.time : 0MS
    Exe.memory : 200K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

struct node 
{
    int s;
    int e;
    int w;
};
struct node q[1000],zan;

int cmp(const void *a,const void *b)
{
    return (*(struct node *)a).w-(*(struct node *)b).w;
}

int set[30],sum,ji,ans,n;

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

void chu()
{
    int i;
    sum=0;
    ans=0;
    ji=0;
    for(i=0;i<n;i++)
    {
        set[i]=i;
    }
}

int main()
{
    char x,e;
    int num,i,f,w;
    int l,r;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%d",&n),n)
    {
        chu();
        getchar();
        for(i=0;i<n-1;i++)
        {
            getchar();
            getchar();
            scanf("%d",&num);
            for(f=0;f<num;f++)
            {
                scanf("%c%c%c%d",&x,&e,&x,&w);
                zan.s=i;
                zan.e=e-'A';
                zan.w=w;
                q[ji++]=zan;            
            }
        }
        qsort(q,ji,sizeof(q[0]),cmp);
            
        
        for(i=0;i<ji;i++)
        {
            l=find(q[i].s);
            r=find(q[i].e);
            if(l != r)
            {
                ans++;
                merge(l,r);
                sum+=q[i].w;
            }
            if(n-1 == ans)
            {
                break;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
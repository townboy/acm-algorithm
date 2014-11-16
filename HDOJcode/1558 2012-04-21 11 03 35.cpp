******************************
    Author : townboy
    Submit time : 2012-04-21 11:03:35
    Judge Status : Accepted
    HDOJ Runid : 5814982
    Problem id : 1558
    Exe.time : 109MS
    Exe.memory : 236K
    https://github.com/townboy
******************************


#include<stdio.h>

struct nodea 
{
    double x1;
    double x2;
    double y1;
    double y2;
};
struct nodea q[1100];

struct nodeb
{
    int sum;
    int head;
};
struct nodeb set[1100];

int check(struct nodea a,struct nodea b)
{
    if( ( (a.x2-a.x1)*(b.y1-a.y1)-(a.y2-a.y1)*(b.x1-a.x1) )*( (a.x2-a.x1)*(b.y2-a.y1)-(a.y2-a.y1)*(b.x2-a.x1) )>0 )
    {
        return 0;
    }
    if( ( (b.x2-b.x1)*(a.y1-b.y1)-(b.y2-b.y1)*(a.x1-b.x1) )*( (b.x2-b.x1)*(a.y2-b.y1)-(b.y2-b.y1)*(a.x2-b.x1) ) >0 )
    {
        return 0;
    }
    return 1;
}

int find(int x)
{
    while(x!=set[x].head)
    { 
        x=set[x].head;
    }
    return x;
}

void merge(int a,int b)
{
    set[a].sum+=set[b].sum;
    set[b].head=a;
} 

void chu()
{
    int i;
    for(i=0;i<1050;i++)
    {
        set[i].sum=1;
        set[i].head=i;
    }
}

int main()
{
    char ch;
    int x,num,ji,g,i,n,f;
//    freopen("D:\\in.txt","r",stdin);
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        if(0!=i)
        {
            printf("\n");
        }
        scanf("%d",&n);
        getchar();

        chu();
        ji=0;        
        for(f=0;f<n;f++)
        {
            scanf("%c",&ch);
            if('P'==ch)
            {    
                ji++;
                scanf("%lf%lf%lf%lf",&q[ji].x1,&q[ji].y1,&q[ji].x2,&q[ji].y2);
                getchar();
                for(g=1;g<ji;g++)
                {
                    if(1==check(q[g],q[ji]))
                    {
                        if(find(ji)!=find(g))
                        {
                            merge(find(ji),find(g));
                        }
                    }
                }
            }
            else
            {
                scanf("%d",&x);
                getchar();
                printf("%d\n",set[find(x)].sum);
            }
        }
    }
    return 0;
}
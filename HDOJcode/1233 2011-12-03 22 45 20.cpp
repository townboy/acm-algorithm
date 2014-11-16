******************************
    Author : townboy
    Submit time : 2011-12-03 22:45:20
    Judge Status : Accepted
    HDOJ Runid : 5107457
    Problem id : 1233
    Exe.time : 125MS
    Exe.memory : 244K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
struct node
{
        int a;
        int b;
        int dis;
};
struct node n[10000];
int g[200];
int cmp(const void *a,const void *b)
{
    return ((*(struct node *)a).dis-(*(struct node *)b).dis);
}
int find(int x)
{
    while(g[x]!=x)
    {
        x=g[x];
    }
    return x;
}
void merge(int x,int y)
{
    g[x]=y;
}
int main(void)
{
    int num,i,ji,sum;
    while(scanf("%d",&num),num)
    {
        for(i=0;i<((num*(num-1))/2);i++)
        {
            scanf("%d%d%d",&n[i].a,&n[i].b,&n[i].dis);
        }
        qsort(n,num*(num-1)/2,sizeof(n[0]),cmp);
        for(i=1;i<=num;i++)
        {
            g[i]=i;
        }
        ji=0;
        sum=0;
        for(i=0;ji<num-1;i++)
        {
            if(find(n[i].a)!=find(n[i].b))
            {
                merge(find(n[i].a),find(n[i].b));
                ji++;
                sum=sum+n[i].dis;
            }
        }
        printf("%d\n",sum);
    }        
    


return 0;
}
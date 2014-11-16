******************************
    Author : townboy
    Submit time : 2013-02-25 17:32:45
    Judge Status : Accepted
    HDOJ Runid : 7651873
    Problem id : 1871
    Exe.time : 31MS
    Exe.memory : 260K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int cap;
    int pri;
    int id;
};
struct node que[1100]; 
int n,t;

int cmp(const void *a,const void *b)
{
    return (*(struct node *)a).pri-(*(struct node *)b).pri;
}

int main()
{
    int tem,g;
    int i,f,cas;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d",&n);
        for(f=0;f<n;f++)
            scanf("%d%d%d",&que[f].id,&que[f].cap,&que[f].pri);
        qsort(que,n,sizeof(que[0]),cmp);
        scanf("%d",&t);
        for(f=0;f<t;f++)
        {
            scanf("%d",&tem);
            for(g=0;g<n;g++)
            {
                if(que[g].cap >= tem)
                {
                    que[g].cap-=tem;
                    printf("%d\n",que[g].id);    
                    break;
                }
            }
            if(g == n)
                printf("sorry\n");
        }
    }
    return 0;
}
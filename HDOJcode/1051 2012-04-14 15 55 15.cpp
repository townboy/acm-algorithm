******************************
    Author : townboy
    Submit time : 2012-04-14 15:55:15
    Judge Status : Accepted
    HDOJ Runid : 5774067
    Problem id : 1051
    Exe.time : 15MS
    Exe.memory : 372K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<stdlib.h>
using namespace std;

int n;

struct node 
{
    int l;
    int w;
};
struct node que[6000],tem,last;

int cmp(const void *a,const void *b)
{
    if((*(struct node *)a).l>(*(struct node *)b).l)
    {
        return 1;
    }
    if((*(struct node *)a).l<(*(struct node *)b).l)
    {
        return -1;
    }
    if((*(struct node *)a).w>(*(struct node *)b).w)
    {
        return 1;
    } 
    else 
    {
        return -1;
    }
}

int fun()
{
    int i,chu,ji,left;
    queue<node> q;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&que[i].l,&que[i].w);
    }

    qsort(que,n,sizeof(que[0]),cmp);
    for(i=0;i<n;i++)
    {
        q.push(que[i]);
    }
    left=n;
    ji=0;
    while(0!=left)
    {
        ji++;
        last=q.front();
        q.pop();
        chu=1;
        for(i=0;i<left-1;i++)
        {
            tem=q.front();
            q.pop();
            if(tem.l>=last.l&&tem.w>=last.w)
            {
                chu++;
                last=tem;
            }
            else
            {
                q.push(tem);
            }
        }
        left-=chu;
    }
    return ji;
}

int main()
{
    int res,i,num;
//    freopen("D:\\in.txt","r",stdin);
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        res=fun();
        printf("%d\n",res);
    }
    return 0;
}
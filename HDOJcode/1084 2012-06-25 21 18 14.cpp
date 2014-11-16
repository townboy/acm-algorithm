******************************
    Author : townboy
    Submit time : 2012-06-25 21:18:14
    Judge Status : Accepted
    HDOJ Runid : 6098817
    Problem id : 1084
    Exe.time : 0MS
    Exe.memory : 236K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

int id[1000];
int hash[6],ever[6];
struct node 
{
    int id;
    int val;
    int sum;
};

int cmp(const void *a,const void *b)
{
    if((*(struct node *)a).val > (*(struct node *)b).val)
    {
        return 1;
    }
    if((*(struct node *)a).val < (*(struct node *)b).val)
    {
        return -1;
    }
    if((*(struct node *)a).sum < (*(struct node *)b).sum)
    {
        return 1;
    }
    if((*(struct node *)a).sum > (*(struct node *)b).sum)
    {
        return -1;
    }    
    return 0;
}

struct node que[11000],tem;

int main()
{
    int num,h,s,m,i;
    while(scanf("%d",&num),num>0)
    {
        memset(hash,0,sizeof(hash));
        memset(ever,0,sizeof(ever));
        for(i=0;i<num;i++)
        {
            scanf("%d%d:%d:%d",&que[i].val,&h,&m,&s);
            que[i].sum=3600*h+60*m+s;
            hash[que[i].val]++;
            que[i].id=i;
        }
        qsort(que,num,sizeof(que[0]),cmp);
        for(i=num;i>=0;i--)
        {
            if(5 == que[i].val)
            {
                id[que[i].id]=100;
                continue;
            }
            if(0 == que[i].val)
            {
                id[que[i].id]=50;
                continue;
            }
            ever[que[i].val]++;
            if(ever[que[i].val] <= hash[que[i].val]/2)
            {
                id[que[i].id]=50+10*que[i].val+5;
            }
            else
            {
                id[que[i].id]=50+10*que[i].val;
            }
        }
        for(i=0;i<num;i++)
        {
            printf("%d\n",id[i]);
        }    
        printf("\n");
    }
    return 0;
}
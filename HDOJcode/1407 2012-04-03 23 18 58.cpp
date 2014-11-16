******************************
    Author : townboy
    Submit time : 2012-04-03 23:18:58
    Judge Status : Accepted
    HDOJ Runid : 5700039
    Problem id : 1407
    Exe.time : 0MS
    Exe.memory : 400K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

struct node
{
    int x;
    int y;
    int z;
    int sum;
};

struct node que[500000];

int cmp(const void *a,const void *b)
{
    return (*(struct node *)a).sum-(*(struct node *)b).sum;
}

int hash[11000],ji;

int find(int x)
{
    int r,l,mid;
    l=0;
    r=ji-1;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(que[mid].sum==x)
        {
            return mid;
        }
        if(que[mid].sum>x)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return -1;
}

int main()
{
    int i,f,g,zan[120],pr,num;
    memset(hash,0,sizeof(hash));
    for(i=1;i<=100;i++)
    {
        zan[i]=i*i;
    }
    
    ji=0;
    for(i=1;i<=100;i++)
    {
        for(f=1;f<=100;f++)
        {
            for(g=1;g<=100;g++)
            {
                if(zan[i]+zan[f]+zan[g]>10010)
                {
                    continue;
                }
                if(1==hash[zan[i]+zan[f]+zan[g]])
                {
                    continue;
                }
                que[ji].x=i;
                que[ji].y=f;
                que[ji].z=g;
                que[ji].sum=zan[i]+zan[f]+zan[g];
                hash[zan[i]+zan[f]+zan[g]]=1;
                ji++;
            }
        }
    }
    qsort(que,ji,sizeof(que[0]),cmp);

    while(scanf("%d",&num)!=EOF)
    {
        pr=find(num);
        printf("%d %d %d\n",que[pr].x,que[pr].y,que[pr].z);
    }
    return 0;
}
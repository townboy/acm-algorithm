******************************
    Author : townboy
    Submit time : 2012-03-10 22:15:46
    Judge Status : Accepted
    HDOJ Runid : 5518583
    Problem id : 1114
    Exe.time : 140MS
    Exe.memory : 264K
    https://github.com/townboy
******************************


#include<stdio.h>
int map[110000];
int val[1000],wei[1000];
int minn(int a,int b)
{
    if(a<0&&b<0)
    {
        return -100000;
    }
    if(a<0)
    {
        return b;
    }
    if(b<0)
    {
        return a;
    }
    return a<b?a:b;
} 

int main()
{
    int i,f,g,w1,w2,w,num,k;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&w1,&w2);
        w=w2-w1;
        scanf("%d",&k);
        for(f=0;f<k;f++)
        {
            scanf("%d%d",&val[f],&wei[f]);
        }
        for(f=0;f<=w;f++)
        {
            map[f]=-100000;
        }
        map[0]=0;
        for(f=0;f<k;f++)
        {
            for(g=0;g<=w;g++)
            {
                if(g<wei[f])
                {
                    continue;
                }
                map[g]=minn(map[g],map[g-wei[f]]+val[f]);
            }
        }
        if(-100000==map[w])
        {
            printf("This is impossible.\n");
        }
        else
        {
            printf("The minimum amount of money in the piggy-bank is %d.\n",map[w]);
        }
    }
    return 0;
}
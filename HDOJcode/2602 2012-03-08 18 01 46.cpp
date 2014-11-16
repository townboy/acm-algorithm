******************************
    Author : townboy
    Submit time : 2012-03-08 18:01:46
    Judge Status : Accepted
    HDOJ Runid : 5499204
    Problem id : 2602
    Exe.time : 46MS
    Exe.memory : 4464K
    https://github.com/townboy
******************************


#include<stdio.h>
struct node 
{
    int val;
    int wei;
};
struct node que[1200];

int map[1100][1100];

int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    int i,f,g,num,n,v;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&n,&v);
        for(f=1;f<=n;f++)
        {
            scanf("%d",&que[f].val);
        }
        for(f=1;f<=n;f++)
        {
            scanf("%d",&que[f].wei);
        }
        for(f=0;f<=v;f++)
        {
            map[0][f]=0;
        }
        for(f=1;f<=n;f++)
        {
            for(g=v;g>=0;g--)
            {
                if(que[f].wei>g)
                {
                    map[f][g]=map[f-1][g];
                }
                else
                {
                    map[f][g]=max(map[f-1][g],map[f-1][g-que[f].wei]+que[f].val);
                }
            }
        }
        printf("%d\n",map[n][v]);
    } 
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-07-08 14:46:52
    Judge Status : Accepted
    HDOJ Runid : 6153233
    Problem id : 3935
    Exe.time : 203MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
#define INF 999999999

int m,n;
int map[110][20],state[110],zan[110];

int countone(int n)
{
    n=(n&0x55555555)+((n>>1)&0x55555555);
    n=(n&0x33333333)+((n>>2)&0x33333333);
    n=(n&0x0f0f0f0f)+((n>>4)&0x0f0f0f0f);
    n=(n&0x00ff00ff)+((n>>8)&0x00ff00ff);
    n=(n&0x0000ffff)+((n>>16)&0x0000ffff);
    return n;
}

void chu(int x)
{
    int i;
    zan[0]=x;
    for(i=1;i<=m;i++)
    {
        zan[i]=state[i];    
    }
}

int main()
{
    int minn,i,f,g,time,tem,inti;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        minn=INF;
        for(i=1;i<=m;i++)
        {
            tem=0;
            for(f=1;f<=n;f++)
            {
                scanf("%d",&map[i][f]);
                map[i][f]=1-map[i][f];        
                tem*=2;
                tem+=map[i][f];    
            }
            state[i]=tem;
        }
        for(i=0;i<(1<<n);i++)
        {
            chu(i);
            time=0;
            for(f=1;f<=m;f++)
            {
                time+=countone(zan[f-1]);
                zan[f]^=zan[f-1];
                zan[f]^=(zan[f-1]>>1);
                zan[f]^=(zan[f-1]<<1);
                zan[f+1]^=zan[f-1];
                zan[f]&=((1<<n)-1);
            }
            if(0 == zan[m])
            {
                if(time  < minn)
                {
                    minn=time;
                }
            }
        }
        if(INF == minn)
        {
            printf("no solution\n");
        }
        else
        {
            printf("%d\n",minn);
        }
    }
    return 0;
}
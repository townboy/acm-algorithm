******************************
    Author : townboy
    Submit time : 2013-04-09 10:49:19
    Judge Status : Accepted
    HDOJ Runid : 8036380
    Problem id : 2153
    Exe.time : 0MS
    Exe.memory : 256K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int ans[10][10];
int dir[4][2]={0,1,1,0,0,-1,-1,0};

void fun(int tem)
{
    int rank=1,x=0,y=0,i,f;
    memset(ans,0,sizeof(ans));
    for(i=0;i<4;i++)
    {
        for(f=0;f<tem-1;f++)
        {
            x+=dir[i][0];
            y+=dir[i][1];
            rank++;
            ans[x][y]=rank;
        }
    }
    ans[0][0]=1;
    for(i=0;i<tem;i++)
    {
        for(f=0;f<tem;f++)
            if(0 == ans[i][f])
                printf("   ");
            else
                printf("%3d",ans[i][f]);
        printf("\n");
    }
}

int main()
{
    int n;
    while(scanf("%d",&n),n)
        fun(n);
    return 0;
}
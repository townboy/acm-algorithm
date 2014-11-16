******************************
    Author : townboy
    Submit time : 2012-01-21 16:08:28
    Judge Status : Accepted
    HDOJ Runid : 5283325
    Problem id : 1241
    Exe.time : 15MS
    Exe.memory : 212K
    https://github.com/townboy
******************************


#include<stdio.h>
int dir[8][2]={0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,1,-1,-1};
char map[120][120];
void dfs(int x,int y)
{
    int i;
    if('@'!=map[x][y])
    {
        return ;
    }
    map[x][y]='*';
    for(i=0;i<8;i++)
    {
        dfs(x+dir[i][0],y+dir[i][1]);
    }
}
int main(void)
{
    int i,f,ji,m,n;
    while(scanf("%d",&m),m!=0)
    {
        ji=0;
        scanf("%d",&n);
        getchar();
        for(i=1;i<=m;i++)
        {
            for(f=1;f<=n;f++)
            {
                scanf("%c",&map[i][f]);
            }
            getchar();
        }
        for(i=1;i<=m;i++)
        {
            for(f=1;f<=n;f++)
            {
                if('@'==map[i][f])
                {
                    ji++;
                    dfs(i,f);
                }
            }
        }
        printf("%d\n",ji);
    }
    return 0;
}
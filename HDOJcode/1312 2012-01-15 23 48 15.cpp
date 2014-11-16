******************************
    Author : townboy
    Submit time : 2012-01-15 23:48:15
    Judge Status : Accepted
    HDOJ Runid : 5262680
    Problem id : 1312
    Exe.time : 15MS
    Exe.memory : 172K
    https://github.com/townboy
******************************


#include<stdio.h>
char map[50][50];
int flag[50][50],dir[4][2]={0,1,0,-1,1,0,-1,0};
void dfs(int x,int y)
{
    int i;
    if(1==flag[x][y])
    {
        return ;
    }
    if('.'==map[x][y]||'@'==map[x][y])
    {
        flag[x][y]=1;
        for(i=0;i<4;i++)
        {
            dfs(x+dir[i][0],y+dir[i][1]);
        }
    }
    
}
int main(void)
{
    int n,m,i,f,ji,x,y;
    while(scanf("%d%d",&n,&m),!(0==m&&0==n))
    {
        getchar();
        for(i=0;i<=25;i++)
        {
            for(f=0;f<=25;f++)
            {
                map[i][f]='#';
            }
        }
        for(i=1;i<=m;i++)
        {
            for(f=1;f<=n;f++)
            {
                scanf("%c",&map[i][f]);
                if('@'==map[i][f])
                {
                    x=i;
                    y=f;
                }
            }
            getchar();
        }
        for(i=1;i<=m;i++)
        {
            for(f=1;f<=n;f++)
            {
                flag[i][f]=0;
            }
        }
        dfs(x,y);
        ji=0;
        for(i=1;i<=m;i++)
        {
            for(f=1;f<=n;f++)
            {
                if(1==flag[i][f])
                {
                    ji++;
                }
            }
        }
        printf("%d\n",ji);
    }
    return 0;
}
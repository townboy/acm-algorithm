******************************
    Author : townboy
    Submit time : 2011-12-28 17:23:24
    Judge Status : Accepted
    HDOJ Runid : 5213777
    Problem id : 1035
    Exe.time : 0MS
    Exe.memory : 212K
    https://github.com/townboy
******************************


#include<stdio.h>
int type,time,time1,time2,n,m,flag[15][15];
char map[15][15];
void dfs(int x,int y,int t)
{
    if(0==x||0==y||n+1==x||m+1==y)
    {
        time=t;
        type=1;
        return ;
    }
    else if(-1!=flag[x][y])
    {
        time1=flag[x][y];
        time2=(t-flag[x][y]);
        type=2;
        return ;
    }
    else
    {
        flag[x][y]=t;
        if(map[x][y]=='W')
        {
            dfs(x,y-1,t+1);
        }
        else if(map[x][y]=='E')
        {
            dfs(x,y+1,t+1);
        }
        else if(map[x][y]=='S')
        {
            dfs(x+1,y,t+1);
        }
        else if(map[x][y]=='N')
        {
            dfs(x-1,y,t+1);
        }
    }
}
int main(void)
{
    int i,f,s;
    while(scanf("%d%d%d",&n,&m,&s),!(0==m&&0==n&&0==s))
    {
        getchar();
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=m;f++)
            {
                scanf("%c",&map[i][f]);
                flag[i][f]=-1;
            }
            getchar();
        }
        dfs(1,s,0);
        if(1==type)
        {
            printf("%d step(s) to exit\n",time);
        }
        else
        {
            printf("%d step(s) before a loop of %d step(s)\n",time1,time2);
        }
    }
return 0;
}
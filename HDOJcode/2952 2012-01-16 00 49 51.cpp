******************************
    Author : townboy
    Submit time : 2012-01-16 00:49:51
    Judge Status : Accepted
    HDOJ Runid : 5262838
    Problem id : 2952
    Exe.time : 31MS
    Exe.memory : 408K
    https://github.com/townboy
******************************


#include<stdio.h>
int dir[4][2]={0,1,0,-1,1,0,-1,0},flag[110][110];
char map[110][110];
void dfs(int x,int y)
{
    int i;
    if(1==flag[x][y])
    {
        return ;
    }
    if('#'!=map[x][y])
    {
        return ;
    }
    flag[x][y]=1;
    for(i=0;i<4;i++)
    {
        dfs(x+dir[i][0],y+dir[i][1]);
    }
}
int main(void)
{
    int num,i,f,g,m,n,ji;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&m,&n);
        getchar();
        for(f=0;f<=m+1;f++)
        {
            for(g=0;g<=n+1;g++)
            {
                map[f][g]='.';
            }
        }
        for(f=1;f<=m;f++)
        {
            for(g=1;g<=n;g++)
            {
                scanf("%c",&map[f][g]);
                flag[f][g]=0;
            }
            getchar();
        }
        ji=1;
        for(f=1;f<=m;f++)
        {
            for(g=1;g<=n;g++)
            {
                if('#'==map[f][g])
                {
                    if(0==flag[f][g])
                    {
                        dfs(f,g);
                        ji++;
                    }
                }
            }
        }
        printf("%d\n",ji-1);
    }
return 0;
}
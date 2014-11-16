******************************
    Author : townboy
    Submit time : 2012-02-16 20:50:52
    Judge Status : Accepted
    HDOJ Runid : 5362686
    Problem id : 1045
    Exe.time : 15MS
    Exe.memory : 196K
    https://github.com/townboy
******************************


#include<stdio.h>
int res,dir[4][2]={0,1,0,-1,1,0,-1,0},hash[8][8];
char map[8][8];
int check(int x,int y)
{
    int i,dep;
    for(i=0;i<4;i++)
    {
        for(dep=1;;dep++)
        {
            if('F'==map[x+dir[i][0]*dep][y+dir[i][1]*dep])
            {
                return 0; 
            }
            if('X'==map[x+dir[i][0]*dep][y+dir[i][1]*dep])
            {
                break; 
            }
        }
    }
    return 1;
}
void dfs(int x,int y,int num)
{
    int i;
    if('X'==map[x][y])
    {
        for(i=0;i<4;i++)
        {
            if(1==hash[x+dir[i][0]][y+dir[i][1]])
            {
                continue;
            }
            hash[x+dir[i][0]][y+dir[i][1]]=1;
            dfs(x+dir[i][0],y+dir[i][1],num);
            hash[x+dir[i][0]][y+dir[i][1]]=0;
        }
        return ;
    }
    if(1==check(x,y))
    {
        map[x][y]='F';
         if(num+1>res)
        {
            res=num+1;
        }
        for(i=0;i<4;i++)
        {
            if(0==hash[x+dir[i][0]][y+dir[i][1]])
            {
                hash[x+dir[i][0]][y+dir[i][1]]=1;
                dfs(x+dir[i][0],y+dir[i][1],num+1);
                hash[x+dir[i][0]][y+dir[i][1]]=0;
            }
        }
        map[x][y]='.';
        for(i=0;i<4;i++)
        {
            if(0==hash[x+dir[i][0]][y+dir[i][1]])
            {
                hash[x+dir[i][0]][y+dir[i][1]]=1;
                dfs(x+dir[i][0],y+dir[i][1],num);
                hash[x+dir[i][0]][y+dir[i][1]]=0;
            }
        }
    }
    else
    {
        for(i=0;i<4;i++)
        {
            if(0==hash[x+dir[i][0]][y+dir[i][1]])
            {
                hash[x+dir[i][0]][y+dir[i][1]]=1;
                dfs(x+dir[i][0],y+dir[i][1],num);
                hash[x+dir[i][0]][y+dir[i][1]]=0;
            }
        }
    }
}
int main()
{
    int i,f,n;
    while(scanf("%d",&n),n)
    {
        getchar();
        for(i=0;i<=n+1;i++)
        {
            for(f=0;f<=n+1;f++)
            {
                map[i][f]='X';
                hash[i][f]=1;;
            }
        }
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=n;f++)
            {
                scanf("%c",&map[i][f]);
                hash[i][f]=0;
            }
            getchar();
        }
        res=0;
        hash[1][1]=1;
        dfs(1,1,0);
        printf("%d\n",res);
    }
    return 0;
}
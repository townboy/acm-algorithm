******************************
    Author : townboy
    Submit time : 2012-07-17 21:20:42
    Judge Status : Accepted
    HDOJ Runid : 6245638
    Problem id : 2821
    Exe.time : 15MS
    Exe.memory : 204K
    https://github.com/townboy
******************************


#include<stdio.h>

int m,n,cx,cy,flag;
int map[30][30],ax,ay,stack[1000],ji;
int dir[4][2]={0,1,0,-1,1,0,-1,0}; 
char dirr[4];

void debug()
{
    int i,f;
    for(i=1;i<=m;i++)
    {
        for(f=1;f<=n;f++)
        {
            printf("%d ",map[i][f]);
        }
        printf("\n");
    }
    printf("\n");
}

int check()
{
    int i,f;
    for(i=1;i<=m;i++)
    {
        for(f=1;f<=n;f++)
        {
            if(0 != map[i][f])
            {
                return 0;
            }
        }
    }    
    return 1;
}

int line(int x,int y,int dd)
{
    int i,nx,ny;
    if(0 != map[x+dir[dd][0]][y+dir[dd][1]])
    {
        return 0;
    }
    for(i=2;;i++)
    {
        nx=x+i*dir[dd][0];
        ny=y+i*dir[dd][1];
        if(nx>m || nx<1 || ny>n || ny<1)
        {
            return 0;
        }
        if(0 != map[nx][ny])
        {
            ax=nx;
            ay=ny;
            return 1;
        }    
    }
    return 0;
}

void print()
{
    int i;
    printf("%d\n%d\n",cx-1,cy-1);
    for(i=0;i<ji;i++)
    {
        printf("%c",dirr[stack[i]]);
    }
    printf("\n");
}

int borad(int x,int y)
{
    if(x<1||x>m||y<1||y>n)
    {
        return 0;
    }
    return 1;
}

void dfs(int x,int y)
{
    int i,temx,temy,temnum;
    if(1 == flag)
    {
        return ;    
    }
    for(i=0;i<4;i++)
    {
        if(0 == line(x,y,i))
        {
            continue;    
        }
        temx=ax;
        temy=ay;
        if(1 != map[temx][temy])
        {
            temnum=map[temx][temy];
            if(0 == borad(temx+dir[i][0],temy+dir[i][1]))
            {
                continue;
            }
            map[temx+dir[i][0]][temy+dir[i][1]]+=(temnum-1);
            map[temx][temy]=0;
            stack[ji]=i;
            ji++;
            dfs(temx,temy);
            ji--;
            map[temx][temy]=temnum;
            map[temx+dir[i][0]][temy+dir[i][1]]-=(temnum-1);
        }
        else
        {
            map[temx][temy]=0;
            stack[ji]=i;
            ji++;
            if(1 == check())
            {
                print();
                flag=1;
                return ;                
            }
            dfs(temx,temy);
            ji--;
            map[temx][temy]=1;
        }
    }     
}

int main()
{
    char ch[100];
    int i,f;
    dirr[0]='R';
    dirr[1]='L';
    dirr[2]='D';
    dirr[3]='U';
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        flag=0;
        for(i=1;i<=m;i++)
        {
            gets(ch);
            for(f=1;f<=n;f++)
            {
                scanf("%c",&ch[f-1]);
                if('.' != ch[f-1])
                {
                    map[i][f]=ch[f-1]-'a'+1;
                }
                else
                {
                    map[i][f]=0;
                }
            }
        }
        ji=0;
        for(i=1;i<=m;i++)
        {
            for(f=1;f<=n;f++)
            {
                cx=i;
                cy=f;
                if(0 == map[i][f])
                {    
                    dfs(i,f);
                }
                if(1 == flag)
                {
                    break;
                }
            }
            if(1 == flag)
            {
                break;
            }
        }
    }
    return 0;
}
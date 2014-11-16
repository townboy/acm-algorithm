******************************
    Author : townboy
    Submit time : 2012-07-18 15:26:22
    Judge Status : Accepted
    HDOJ Runid : 6252809
    Problem id : 3500
    Exe.time : 531MS
    Exe.memory : 204K
    https://github.com/townboy
******************************


#include<stdio.h>

char map[30][30];
int ax,ay,ji,flag,dir[4][2]={-1,0,0,-1,0,1,1,0},cas=0;
char pathd[4];

struct node 
{
    int x;
    int y;
    int dd;
};
struct node path[100];

void debug()
{
    int i,f;
    for(i=0;i<=8;i++)
    {
        for(f=0;f<=9;f++)
        printf("%c",map[i][f]);
        printf("\n");
    }    
    printf("\n");
}

int check(int x,int y,int dd)
{
    int nx,ny,i;
    if('O' == map[x+dir[dd][0]][y+dir[dd][1]])
    {
        return 0;    
    }
    for(i=2;;i++)
    {
        nx=x+i*dir[dd][0];
        ny=y+i*dir[dd][1];
        if(nx<1||nx>7||ny<1||ny>8)
        {
            return 0;
        }            
        if('O' == map[nx][ny])
        {
            return 1;
        }
    }
    
}

void look(int x,int y,int dd)
{
    int i,nx,ny;
    for(i=0;;i++)
    {
        nx=x+i*dir[dd][0];
        ny=y+i*dir[dd][1];
        if('X' == map[nx][ny])
        {
            ax=nx-dir[dd][0];
            ay=ny-dir[dd][1];
            return ;
        }
    }
}

void push(int x,int y,int dd)
{
    int i,nx,ny;
    map[x][y]='X';
    for(i=2;;i++)
    {
        nx=x+i*dir[dd][0];
        ny=y+i*dir[dd][1];
        if(nx<1||nx>7||ny<1||ny>8)
        {
            return ;
        }            
        if('O' == map[nx][ny])
        {
            map[nx-dir[dd][0]][ny-dir[dd][1]]='O';
            look(nx,ny,dd);
//            printf("%d %d \n",ax,ay);
            push(ax,ay,dd);
//            debug();
            break;
        }    
    }
}

void print()
{    
    int i;
    if(1 != cas)
    {
        printf("\n");    
    }
    printf("CASE #%d:\n",cas);
    for(i=0;i<ji;i++)
    {
        printf("%d %d %c\n",path[i].x-1,path[i].y-1,pathd[path[i].dd]);
    }
}

int end()
{
    int i,f,sum=0;
    for(i=1;i<=7;i++)
    {
        for(f=1;f<=8;f++)
        {
            if('O' == map[i][f])
            {
                sum++;
            }
            if(2 == sum)
            {
                return 0;
            }
        }
    }
    return 1;
}

void dfs()
{
    int save[8][9];
    int i,f,g,h,j;
    for(i=1;i<=7;i++)
        for(f=1;f<=8;f++)
            save[i][f]=map[i][f];
    if(1 == flag)
    {
        return ;
    }
    if(1 == end())
    {
        print();
        flag=1;
        return ;
    }
    
    for(i=1;i<=7;i++)
    {
        for(f=1;f<=8;f++)
        {
            if('X' == map[i][f])
            {
                continue;    
            }
            for(g=0;g<4;g++)
            {
                if(0 == check(i,f,g))
                {
                    continue;
                }
                push(i,f,g);
                path[ji].x=i;
                path[ji].y=f;
                path[ji].dd=g;
                ji++;
                dfs();
                ji--;

                for(h=1;h<=7;h++)
                    for(j=1;j<=8;j++)
                        map[h][j]=save[h][j];                            
            }
        }
    }
}



int main()
{
    char ch[20];
    int i,f;
    for(i=0;i<=8;i++)
        for(f=0;f<=9;f++)
            map[i][f]='X';
    pathd[0]='U';
    pathd[1]='L';
    pathd[2]='R';
    pathd[3]='D';
    while(scanf("%s",ch)!=EOF)
    {
        for(i=1;i<=8;i++)
        {
            map[1][i]=ch[i-1];
        }
        cas++;
        ji=0;
        flag=0;
        for(i=2;i<=7;i++)
        {
            scanf("%s",ch);
            for(f=1;f<=8;f++)
            {
                map[i][f]=ch[f-1];
            }
        }
        getchar();    
        dfs();
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-05-16 20:50:38
    Judge Status : Accepted
    HDOJ Runid : 5953614
    Problem id : 1564
    Exe.time : 15MS
    Exe.memory : 192K
    https://github.com/townboy
******************************


/*

´ò±í·¢ÏÖÓëNµÄÆæÅ¼ÐÔÓÐ¹Ø

#include<stdio.h>

int dir[4][2]={0,1,1,0,-1,0,0,-1};

struct node 
{
    int x;
    int y;
    int map[21][21];
    int big;
};
struct node x;

int dfs(struct node x)
{
    int i;
    for(i=0;i<4;i++)
    {
        if(0 == x.map[x.x+dir[i][0]][x.y+dir[i][1]] )
        {
            x.x=x.x+dir[i][0];
            x.y=x.y+dir[i][1];
            x.map[x.x][x.y] = 1;
            if(0 == dfs(x))
            {
                return 1;
            }

            x.map[x.x][x.y] = 0;
            x.x=x.x-dir[i][0];
            x.y=x.y-dir[i][1];
        }
    }
    return 0;
}

void chu(int b)
{
    int i,f;
    
    for(i=0;i<=b+1;i++)
    {
        for(f=0;f<=b+1;f++)
        {
            x.map[i][f]=1;
        }
    }
    for(i=1;i<=b;i++)
    {
        for(f=1;f<b+1;f++)
        {
            x.map[i][f]=0;
        }
    }
    x.map[1][1]=1;
    x.big=b;
    x.x=1;
    x.y=1;
}

int main()
{
    int i;
    
    for(i=1;i<15;i++)
    {
        chu(i);
        printf("%d\n",dfs(x));
    }

    return 0;
}
*/

#include<stdio.h>
int main()
{
    int x;
    while(scanf("%d",&x),x)
    {
        if(0 == (x&1))
        {
            printf("8600\n");
        }
        else
        {
            printf("ailyanlu\n");
        }
    }
    return 0;
}
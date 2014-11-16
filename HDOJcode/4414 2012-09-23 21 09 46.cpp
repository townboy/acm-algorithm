******************************
    Author : townboy
    Submit time : 2012-09-23 21:09:46
    Judge Status : Accepted
    HDOJ Runid : 6823904
    Problem id : 4414
    Exe.time : 0MS
    Exe.memory : 248K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>

using namespace std;

int n,dir[4][2]={-1,0,0,1,1,0,0,-1};
char map[55][55];

int in(int x,int y)
{
    if(x > n || x < 1 || y < 1 || y > n)
    {
        return 0;
    }
    return 1;
} 

int judge(int x,int y,int dirr)
{
    if(0 == in(x,y) || 'o' == map[x][y])
    {
        return 0;
    }
    if(1 == in(x+dir[(dirr+1)%4][0],y+dir[(dirr+1)%4][1]) && '#' == map[x+dir[(dirr+1)%4][0]][y+dir[(dirr+1)%4][1]])
    {
        return 0;
    }
    if(1 == in(x+dir[(dirr+3)%4][0],y+dir[(dirr+3)%4][1]) && '#' == map[x+dir[(dirr+3)%4][0]][y+dir[(dirr+3)%4][1]])
    {
        return 0;
    }
    if(1 == in(x+dir[dirr][0],y+dir[dirr][1]) && '#' == map[x+dir[dirr][0]][y+dir[dirr][1]])
    {
        return 2;
    }
    return 1;
}

int check(int x,int y)
{
    int now,k,i,f;
    if('o' == map[x][y])
    {
        return 0;
    }
    for(i=1;;i++)
    {
        now=1;
        for(f=0;f<4;f++)
        {
            k=judge(x+i*dir[f][0],y+i*dir[f][1],f);
            if(0 == k)
            {
                return 0;
            }
            now=max(now,k);
        }
        if(1 == now)
        {
            return 1;    
        }
    }
}

void debug()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=n;f++)
        {
            printf("%c",map[i][f]);
        }
        printf("\n");
    }
}

int main()
{
    int ans,i,f;
    while(scanf("%d",&n),n)
    {
        for(i=1;i<=n;i++)
        {
            getchar();
            for(f=1;f<=n;f++)
            {
                scanf("%c",&map[i][f]);
            }
        }
        
        ans=0;
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=n;f++)
            {
                if(1 == check(i,f))
                {
                    ans++;
                }
            }
        }
        printf("%d\n",ans);    
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2013-03-28 01:21:52
    Judge Status : Accepted
    HDOJ Runid : 7907607
    Problem id : 4500
    Exe.time : 15MS
    Exe.memory : 236K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int dir[4][2]={0,1,1,0,0,-1,-1,0};
int map[30][30],n,m,val[30][30];

int abs(int x)
{
    return x>0?x:-x;
}

int check(int x,int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m)
        return 0;
    return 1;
}

void cal(int x,int y)
{
    int i,f,tox,toy;
    for(i=0;i<4;i++)
    {
        tox=x+dir[i][0];
        toy=y+dir[i][1];
        if(0 == check(tox,toy))
            continue;
        if(map[x][y]*map[tox][toy] > 0)
            val[x][y]-=abs(map[tox][toy]);
        else
            val[x][y]+=abs(map[tox][toy]);
    }
}

void debug()
{
    int i,f;
    for(i=0;i<n;i++)
    {    
        for(f=0;f<n;f++)
            printf("%d ",val[i][f]);
        printf("\n");
    }
}

int main()
{
    int ansx,ansy;
    int i,f;
    while(scanf("%d%d",&n,&m),n+m)
    {
        memset(val,0,sizeof(val));
        for(i=0;i<n;i++)
            for(f=0;f<m;f++)
                scanf("%d",&map[i][f]);
        for(i=0;i<n;i++)
            for(f=0;f<m;f++)
                cal(i,f);
        ansx=0;
        ansy=0;
        for(i=0;i<n;i++)
            for(f=0;f<m;f++)
                if(val[i][f] > val[ansx][ansy])
                    ansx=i,ansy=f;
        printf("%d %d %d\n",ansx+1,ansy+1,val[ansx][ansy]);
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2013-04-08 10:17:40
    Judge Status : Accepted
    HDOJ Runid : 8028151
    Problem id : 2258
    Exe.time : 15MS
    Exe.memory : 232K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

char map[30][30];
int hash[30][30],n,m;
int cnt,dir[4][2]={0,1,1,0,-1,0,0,-1};

int check(int x,int y)
{
    if(x > n || x < 1 || y > m || y < 1)
        return 0;
    return 1;
}

void find(int x,int y)
{
    int tox,toy;
    int i,color=map[x][y];
    hash[x][y]=1;
    cnt++;
    for(i=0;i<4;i++)
    {
        tox=x+dir[i][0];
        toy=y+dir[i][1];
        if(1 == check(tox,toy) && color == map[tox][toy] && 0 == hash[tox][toy])
            find(tox,toy);
    }
}

void debug()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=m;f++)
            printf("%c",-1==map[i][f]?' ':map[i][f]);
        printf("\n");
    }
    printf("\n");
}

void xiao(int x,int y)
{
    int i,color=map[x][y];
    int tox,toy;
    map[x][y]=-1;
    for(i=0;i<4;i++)
    {
        tox=x+dir[i][0];
        toy=y+dir[i][1];
        if(1 == check(tox,toy) && color == map[tox][toy])
            xiao(tox,toy);
    }
}

void righttoleft(int aim)
{
    int f,i;
    for(f=aim;f<m;f++)
    {
        for(i=1;i<=n;i++)
            map[i][f]=map[i][f+1];
    }
    for(i=1;i<=n;i++)
        map[i][m]=-1;
}

void work(int x,int y)
{
    int rank;
    int i,f,flag;
    xiao(x,y);
    for(f=m;f>=1;f--)
    {
        flag=0;
        rank=n;
        for(i=n;i>=1;i--)
        {
            if(-1 != map[i][f])
            {    
                map[rank][f]=map[i][f];
                rank--;
                flag=1;
            }
        }
        for(i=rank;i>=1;i--)
            map[i][f]=-1;
        if(1 == flag)    continue;
        righttoleft(f);
    }
}

int main()
{
    int ans;
    int i,maxx,posx,posy,f;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%s",&map[i][1]);
        ans=0;
        while(1)
        {
            memset(hash,0,sizeof(hash));
            maxx=1;
            for(i=1;i<=n;i++)
                for(f=1;f<=m;f++)
                {
                    if(1 == hash[i][f] || -1 == map[i][f])    continue;
                    cnt=0;
                    find(i,f);
                    if(cnt > maxx)
                        posx=i,posy=f,maxx=cnt;
                }
            if(1 == maxx)    break;
            ans+=maxx*(maxx-1);
            work(posx,posy);
        }
        printf("%d\n",ans);
    }
    return 0;
}
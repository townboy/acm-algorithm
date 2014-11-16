******************************
    Author : townboy
    Submit time : 2012-09-17 12:08:53
    Judge Status : Accepted
    HDOJ Runid : 6780210
    Problem id : 1198
    Exe.time : 0MS
    Exe.memory : 260K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

char map[55][55];
int dir[4][2]={-1,0,0,1,1,0,0,-1},set[3000];
int dirr[11][4],h1[4],h2[4];
int num[11]={2,2,2,2,2,2,3,3,3,3,4};
int n,m;

void merge(int a,int b)
{
    set[a]=b;
}

int find(int x)
{
    while(x != set[x])
    {
        x=set[x];
    }
    return x;
}

void yu()
{
    dirr[0][0]=0;
    dirr[0][1]=3;
    dirr[1][0]=0;
    dirr[1][1]=1;
    dirr[2][0]=2;
    dirr[2][1]=3;
    dirr[3][0]=1;
    dirr[3][1]=2;
    dirr[4][0]=0;
    dirr[4][1]=2;
    dirr[5][0]=1;
    dirr[5][1]=3;

    dirr[6][0]=0;    
    dirr[6][1]=1;    
    dirr[6][2]=3;
    dirr[7][0]=0;    
    dirr[7][1]=2;    
    dirr[7][2]=3;
    dirr[8][0]=1;    
    dirr[8][1]=2;    
    dirr[8][2]=3;
    dirr[9][0]=0;    
    dirr[9][1]=1;    
    dirr[9][2]=2;

    dirr[10][0]=0;
    dirr[10][1]=1;
    dirr[10][2]=2;
    dirr[10][3]=3;
}

void chu()
{
    memset(h1,0,sizeof(h1));
    memset(h2,0,sizeof(h2));
}

int turn(int x,int y)
{
    return (x-1)*m+y;
}

void debug()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=m;f++)
        {
            printf("%c",map[i][f]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int g,ans;
    int i,f,nx,ny;
    yu();
    while(scanf("%d%d",&n,&m),n+m > 0)
    {        
        for(i=1;i<=n*m;i++)
        {
            set[i]=i;
        }
        for(i=1;i<=n;i++)
        {
            getchar();
            for(f=1;f<=m;f++)
            {
                scanf("%c",&map[i][f]);
            }
        }
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=m;f++)
            {
                chu();
                for(g=0;g<num[map[i][f]-'A'];g++)
                {
                    h1[dirr[map[i][f]-'A'][g]]=1;
                }
                nx=i;
                ny=f+1;
                if(nx <= n && nx >=1 && ny <= m && ny >= 1)
                {
                    for(g=0;g<num[map[nx][ny]-'A'];g++)
                    {
                        h2[dirr[map[nx][ny]-'A'][g]]=1;
                    }
                    
                    if(1 == h1[1] && 1 == h2[3])
                    {
                        merge(find(turn(i,f)),find(turn(nx,ny)));
                    }
                }
                nx=i+1;
                ny=f;
                memset(h2,0,sizeof(h2));
            
                if(nx <= n && nx >=1 && ny <= m && ny >= 1)
                {
                    for(g=0;g<num[map[nx][ny]-'A'];g++)
                    {
                        h2[dirr[map[nx][ny]-'A'][g]]=1;
                    }
                    
                    if(1 == h1[2] && 1 == h2[0])
                    {
                        merge(find(turn(i,f)),find(turn(nx,ny)));
                    }
                }
            }
        }
        ans=0;
        for(i=1;i<=n*m;i++)
        {
            if(i == set[i])
            {
                ans++;
            }
        }
        printf("%d\n",ans);
    }    
    return 0;
}
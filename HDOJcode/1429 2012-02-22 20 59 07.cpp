******************************
    Author : townboy
    Submit time : 2012-02-22 20:59:07
    Judge Status : Accepted
    HDOJ Runid : 5395625
    Problem id : 1429
    Exe.time : 62MS
    Exe.memory : 10420K
    https://github.com/townboy
******************************


#include<stdio.h>
int t,si,sf,dir[4][2]={0,1,0,-1,1,0,-1,0},key[10]={1,2,4,8,16,32,64,128,256,512};
int hash[25][25][2200];
char map[30][30];
struct node 
{
    int x;
    int y;
    int tai;
    int time;
};
struct node que[1000000],tem;
int check(int k,int x)
{
    if(k==(k|key[x]))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int bfs()
{
    int head,tail,i;
    head=0;
    tail=0;
    que[head].x=si;
    que[head].y=sf;
    que[head].tai=0;
    que[head].time=0;
    hash[si][sf][0]=1;
    while(head<=tail)
    {
        tem=que[head];
        head++;
        if(tem.time>=t)
        {
            return -1;
        }
        if('^'==map[tem.x][tem.y])
        {
            return tem.time;
        }
        if('.'==map[tem.x][tem.y])
        {
            for(i=0;i<4;i++)
            {
                if('*'==map[tem.x+dir[i][0]][tem.y+dir[i][1]])
                {
                    continue;
                }
                else 
                {
                    if(1==hash[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.tai])
                    {
                        continue;
                    }
                    hash[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.tai]=1;
                    tail++;
                    que[tail].x=tem.x+dir[i][0];
                    que[tail].y=tem.y+dir[i][1];
                    que[tail].tai=tem.tai;
                    que[tail].time=tem.time+1;
                }
            }
        }
        else if('a'<=map[tem.x][tem.y]&&'j'>=map[tem.x][tem.y])
        {
            for(i=0;i<4;i++)
            {
                if('*'==map[tem.x+dir[i][0]][tem.y+dir[i][1]])
                {
                    continue;
                }
                else
                {
                    if(1==hash[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.tai|key[map[tem.x][tem.y]-'a']])
                    {
                        continue;
                    }
                    hash[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.tai|key[map[tem.x][tem.y]-'a']]=1;
                    tail++;
                    que[tail].x=tem.x+dir[i][0];
                    que[tail].y=tem.y+dir[i][1];
                    que[tail].tai=tem.tai|key[map[tem.x][tem.y]-'a'];
                    que[tail].time=tem.time+1;
                }
            }
        }
        else 
        {
            if(0==check(tem.tai,map[tem.x][tem.y]-'A'))
            {
                continue;
            }
            for(i=0;i<4;i++)
            {
                if('*'==map[tem.x+dir[i][0]][tem.y+dir[i][1]])
                {
                    continue;
                }
                else 
                {
                    if(1==hash[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.tai])
                    {
                        continue;
                    }
                    hash[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.tai]=1;
                    tail++;
                    que[tail].x=tem.x+dir[i][0];
                    que[tail].y=tem.y+dir[i][1];
                    que[tail].tai=tem.tai;
                    que[tail].time=tem.time+1;
                }
            }
        }
    }
    return -1;
}
void chu(int m,int n)
{
    int i,f,g;
    for(i=0;i<=m+1;i++)
    {
        for(f=0;f<=n+1;f++)
        {
            map[i][f]='*';
            for(g=0;g<=2100;g++)
            {
                hash[i][f][g]=0;
            }
        }
    }
}
int main()
{
    int i,f,res,m,n;
    while(scanf("%d%d%d",&m,&n,&t)!=EOF)
    {
        chu(m,n);
        getchar();
        for(i=1;i<=m;i++)
        {
            for(f=1;f<=n;f++)
            {
                scanf("%c",&map[i][f]);
                if('@'==map[i][f])
                {
                    si=i;
                    sf=f;
                    map[i][f]='.';
                }
            }
            getchar();
        }
        res=bfs();
        printf("%d\n",res);
    }
    return 0;
}

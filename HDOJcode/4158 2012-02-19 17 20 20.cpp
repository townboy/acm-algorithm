******************************
    Author : townboy
    Submit time : 2012-02-19 17:20:20
    Judge Status : Accepted
    HDOJ Runid : 5378492
    Problem id : 4158
    Exe.time : 15MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int dir[4][2]={0,1,0,-1,1,0,-1,0},hash[30][30],map[30][30];
struct node 
{
    int x;
    int y;
};
struct node que[1000],tem;
void chu(int n)
{
    int i,f;
    for(i=0;i<=n+1;i++)
    {
        for(f=0;f<=n+1;f++)
        {
            map[i][f]=-1;
            hash[i][f]=0;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=n;f++)
        {
            map[i][f]=0;
        }
    }
}
void clear(int n)
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=n;f++)
        {
            hash[i][f]=0;
        }
    }
}
void tu(int n,int res)
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=n;f++)
        {
            if(1==hash[i][f])
            {
                map[i][f]=res;
            }
            hash[i][f]=0;
        }
    }
}
int bfs(int si,int sf)
{
    int head,tail,i,flag=0;
    head=0;
    tail=0;
    que[head].x=si;
    que[head].y=sf;
    hash[si][sf]=1;
    while(head<=tail)
    {
        tem=que[head];
        head++;
        if(0==map[tem.x][tem.y])
        {
            for(i=0;i<4;i++)
            {
                if(0==map[tem.x+dir[i][0]][tem.y+dir[i][1]])
                {
                    if(1==hash[tem.x+dir[i][0]][tem.y+dir[i][1]])
                    {
                        continue;
                    }
                    hash[tem.x+dir[i][0]][tem.y+dir[i][1]]=1;
                    tail++;
                    que[tail].x=tem.x+dir[i][0];
                    que[tail].y=tem.y+dir[i][1];
                }
                else if(-1==map[tem.x+dir[i][0]][tem.y+dir[i][1]])
                {
                    continue;
                }
                else
                {
                    tail++;
                    que[tail].x=tem.x+dir[i][0];
                    que[tail].y=tem.y+dir[i][1];
                }
            }
        }
        else
        {
            if(0==flag)
            {
                flag=map[tem.x][tem.y];
            }
            else
            {
                if(flag!=map[tem.x][tem.y])
                {
                    return 5;
                }
            }
        }
    }
    return flag;
}
int main()
{
    int i,f,b,w,x,y,s1,s2,res,n;
    while(scanf("%d",&n),n)
    {
        chu(n);
        scanf("%d%d",&b,&w);
        for(i=0;i<b;i++)
        {
            scanf("%d%d",&x,&y);
            map[x][y]=1;
        }
        for(i=0;i<w;i++)
        {
            scanf("%d%d",&x,&y);
            map[x][y]=2;
        }
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=n;f++)
            {
                if(0==map[i][f])
                {
                    res=bfs(i,f);
                    if(5!=res)
                    {
                        tu(n,res+2);
                    }
                    else
                    {
                        clear(n);
                    }
                }
            }
        }
        s1=0;
        s2=0;
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=n;f++)
            {
                if(3==map[i][f])
                {
                    s1++;
                }
                if(4==map[i][f])
                {
                    s2++;
                } 
            }
        }
        if(s1==s2)
        {
            printf("Draw\n");
        }
        else if(s1>s2)
        {
            printf("Black wins by %d\n",s1-s2);
        }
        else
        {
            printf("White wins by %d\n",s2-s1);
        }
    }
    return 0;
}
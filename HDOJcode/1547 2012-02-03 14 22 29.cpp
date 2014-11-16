******************************
    Author : townboy
    Submit time : 2012-02-03 14:22:29
    Judge Status : Accepted
    HDOJ Runid : 5309583
    Problem id : 1547
    Exe.time : 15MS
    Exe.memory : 356K
    https://github.com/townboy
******************************


#include<stdio.h>
char map[110][110];
int dir1[6][2]={-1,0,1,0,0,1,0,-1,1,-1,-1,-1},dir0[6][2]={-1,0,1,0,0,-1,0,1,1,1,-1,1};
int hash[110][110],W,H,w,h,num;
void dfs(int x,int y,int col)
{
    int i;
    if(1==hash[x][y])
    {
        return ;
    }
    if(col!=map[x][y])
    {
        return ;
    }
    hash[x][y]=1;
    num++;
    if(0==x%2)
    {
        for(i=0;i<6;i++)
        {
            dfs(x+dir0[i][0],y+dir0[i][1],col);
        }
    }
    else
    {
        for(i=0;i<6;i++)
        {
            dfs(x+dir1[i][0],y+dir1[i][1],col);
        }
    }
}
void dfs2(int x,int y)
{
    int i;
    if(1==hash[x][y])
    {
        return ;
    }
    hash[x][y]=1;
    if(0==x%2)
    {
        for(i=0;i<6;i++)
        {
            dfs2(x+dir0[i][0],y+dir0[i][1]);
        }
    }
    else
    {
        for(i=0;i<6;i++)
        {
            dfs2(x+dir1[i][0],y+dir1[i][1]);
        }
    }
}
int main(void)
{
    int ji,i,f;
    while(scanf("%d%d%d%d",&H,&W,&h,&w)!=EOF)
    {
        getchar();
        for(i=0;i<=H+1;i++)
        {
            for(f=0;f<=W+1;f++)
            {
                hash[i][f]=1;
            }
        }
        for(i=1;i<=H;i++)
        {
            if(1==i%2)
            {
                for(f=1;f<=W;f++)
                {
                    scanf("%c",&map[i][f]);
                    if('E'!=map[i][f])
                    {
                        hash[i][f]=0;
                    }
                    else
                    {
                        hash[i][f]=1;
                    }
                }
            }
            else
            {
                for(f=1;f<=W-1;f++)
                {
                    scanf("%c",&map[i][f]);
                    if('E'!=map[i][f])
                    {
                        hash[i][f]=0;
                    }
                    else
                    {
                        hash[i][f]=1;
                    }
                }
            }
            getchar();
        }
        num=0;
        dfs(h,w,map[h][w]);
        if(num<3)
        {
            num=0;
            for(i=1;i<=H;i++)
            {
                if(1==i%2)
                {
                    for(f=1;f<=W;f++)
                    {
                        hash[i][f]=0;
                    }
                }
                else
                {
                    for(f=1;f<=W-1;f++)
                    {
                        hash[i][f]=0;
                    }
                }
            }
        }
        for(i=1;i<=W;i++)
        {
            if(0==hash[1][i])
            {
                dfs2(1,i);
            }
        }
        ji=0;
        for(i=1;i<=H;i++)
        {
            if(1==i%2)
            {
                for(f=1;f<=W;f++)
                {
                    if(0==hash[i][f])
                    {
                        ji++;
                    }
                }
            }
            else
            {
                for(f=1;f<=W-1;f++)
                {
                    if(0==hash[i][f])
                    {
                        ji++;
                    }
                }
            }
        }    
        printf("%d\n",ji+num);
    }
    return 0;
}
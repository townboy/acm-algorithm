******************************
    Author : townboy
    Submit time : 2012-01-25 15:15:50
    Judge Status : Accepted
    HDOJ Runid : 5293013
    Problem id : 2782
    Exe.time : 3359MS
    Exe.memory : 1908K
    https://github.com/townboy
******************************


#include<stdio.h>
int res,map[700][700],dir[4][2]={0,1,1,0,0,-1,-1,0},zan,ji;
void dfs(int x,int y,int sum,int type)
{
    int ji;
    ji=0;
    if(0==map[x+dir[type][0]][y+dir[type][1]])
    {
        map[x+dir[type][0]][y+dir[type][1]]=1;
        dfs(x+dir[type][0],y+dir[type][1],sum+1,type);
        map[x+dir[type][0]][y+dir[type][1]]=0;
        return ;
    }
    if(0==map[x+dir[(type+1)%4][0]][y+dir[(type+1)%4][1]])
    {
        map[x+dir[(type+1)%4][0]][y+dir[(type+1)%4][1]]=1;
        ji++;
        dfs(x+dir[(type+1)%4][0],y+dir[(type+1)%4][1],sum+1,(type+1)%4);
        map[x+dir[(type+1)%4][0]][y+dir[(type+1)%4][1]]=0;
    }
    if(0==map[x+dir[(type+3)%4][0]][y+dir[(type+3)%4][1]])
    {
        map[x+dir[(type+3)%4][0]][y+dir[(type+3)%4][1]]=1;
        ji++;
        dfs(x+dir[(type+3)%4][0],y+dir[(type+3)%4][1],sum+1,(type+3)%4);
        map[x+dir[(type+3)%4][0]][y+dir[(type+3)%4][1]]=0;
    }
    if(0==ji)
    {
        if(sum>zan)
        {
            zan=sum;
        }
    }
    return ;
}
int main(void)
{
    int i,f,m,n,a,b,num,x,y,max;
    ji=0;
    while(scanf("%d%d",&m,&n),!(0==m&&0==n))
    {
        ji++;
        for(i=0;i<=m+1;i++)
        {
            for(f=0;f<=n+1;f++)
            {
                map[i][f]=1;
            }
        }
        for(i=1;i<=m;i++)
        {
            for(f=1;f<=n;f++)
            {
                map[i][f]=0;    
            }
        }
        scanf("%d",&num);
        for(i=0;i<num;i++)
        {
            scanf("%d%d",&a,&b);
            map[a+1][b+1]=1;
        }
        res=0;
        max=0;
        x=0;
        y=0;
        for(i=1;i<=m;i++)
        {
            for(f=1;f<=n;f++)
            {
                if(0==map[i][f])
                {
                    map[i][f]=1;
                    if(0==map[i+dir[0][0]][f+dir[0][1]])
                    {
                        zan=0;
                        dfs(i,f,1,0);
                        if(zan>res)
                        {
                            res=zan;
                            max=0;
                            x=i;
                            y=f;
                        }
                    }
                    if(0==map[i+dir[3][0]][f+dir[3][1]])
                    {
                        zan=0;
                        dfs(i,f,1,3);
                        if(zan>res)
                        {
                            res=zan;
                            max=3;
                            x=i;
                            y=f;
                        }
                    }
                    if(0==map[i+dir[1][0]][f+dir[1][1]])
                    {
                        zan=0;
                        dfs(i,f,1,1);
                        if(zan>res)
                        {
                            res=zan;
                            max=1;
                            x=i;
                            y=f;
                        }
                    }
                    if(0==map[i+dir[2][0]][f+dir[2][1]])
                    {
                        zan=0;
                        dfs(i,f,1,2);
                        if(zan>res)
                        {
                            res=zan;
                            max=2;
                            x=i;
                            y=f;
                        }
                    }
                    map[i][f]=0;
                }
            }
        }    
        printf("Case %d: %d %d %d ",ji,res,x-1,y-1);
        if(0==max)
        {
            printf("E\n");
        }
        else if(1==max)
        {
            printf("S\n");
        }
        else if(2==max)
        {
            printf("W\n");
        }
        else
        {
            printf("N\n");
        }
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-02-13 21:28:09
    Judge Status : Accepted
    HDOJ Runid : 5349557
    Problem id : 1175
    Exe.time : 46MS
    Exe.memory : 2368K
    https://github.com/townboy
******************************


#include<stdio.h>
int dir[4][2]={0,1,1,0,0,-1,-1,0},map[1100][1100],flag,si,sf,ei,ef;
void dfs(int x,int y,int num,int tai)
{
    int i,kr;
    if(1==flag)
    {
        return ;
    }
    if(x==ei&&y==ef)
    {
        flag=1;
        return ;
    }
    if(2==num)
    {
        if(!(0==ei-x||0==ef-y))
        {
            return ;
        }
        else
        {
            if(0==map[x+dir[tai][0]][y+dir[tai][1]])
            {
                map[x+dir[tai][0]][y+dir[tai][1]]=-1;
                dfs(x+dir[tai][0],y+dir[tai][1],num,tai);
                map[x+dir[tai][0]][y+dir[tai][1]]=0;
            }
            return ;
        }
    }
    if(1==num)
    {
        if((ei-x)*dir[tai][0]<0||(ef-y)*dir[tai][1]<0)
        {
            return ;
        }
    }
    for(i=0;i<=3;i++)
    {
        if(2==i)
        {
            continue ;
        }
        if(1==i||3==i)
        {
            kr=num+1;
        }
        else
        {
            kr=num;
        }
        if(0==map[x+dir[(tai+i)%4][0]][y+dir[(tai+i)%4][1]])
        { 
            map[x+dir[(tai+i)%4][0]][y+dir[(tai+i)%4][1]]=-1;
            dfs(x+dir[(tai+i)%4][0],y+dir[(tai+i)%4][1],kr,(tai+i)%4);
            map[x+dir[(tai+i)%4][0]][y+dir[(tai+i)%4][1]]=0;
        }
    }
}
int main()
{
    int i,f,num,m,n,tem;
    while(scanf("%d%d",&m,&n),!(0==n&&0==m))
    {
        for(i=0;i<=m+1;i++)
        {
            for(f=0;f<=n+1;f++)
            {
                map[i][f]=-1;
            }
        }
        for(i=1;i<=m;i++)
        {
            for(f=1;f<=n;f++)
            {
                scanf("%d",&map[i][f]);
            }
        }
        scanf("%d",&num);
        for(i=0;i<num;i++)
        {
            scanf("%d%d%d%d",&si,&sf,&ei,&ef);
            if(map[si][sf]==map[ei][ef]&&0!=map[ei][ef])
            {
                flag=0;
                tem=map[ei][ef];
                map[ei][ef]=0;  
                for(f=0;f<4;f++)
                {
                    dfs(si,sf,0,f);
                }
                map[ei][ef]=tem;
            }
            else
            {
                flag=0;
            }
            if(1==flag)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}
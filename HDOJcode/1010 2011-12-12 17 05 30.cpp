******************************
    Author : townboy
    Submit time : 2011-12-12 17:05:30
    Judge Status : Accepted
    HDOJ Runid : 5156209
    Problem id : 1010
    Exe.time : 62MS
    Exe.memory : 236K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int escape,dir[4][2]={0,1,0,-1,1,0,-1,0},ei,ef,t,m,n;
char map[20][20];
void dfs(int x,int y,int sum)
{
    int i;
    if(escape)
    {
        return;
    }
    if(x==ei&&y==ef&&t==sum)
    {
        escape=1;
        return;
    }
    if((abs(x-ei)+abs(y-ef))>(t-sum))
    {
        return;
    }
    if(x<=m&&x>=1&&y<=n&&y>=1)
    {
        for(i=0;i<4;i++)
        {
            if(map[x+dir[i][0]][y+dir[i][1]]!='X')
            {
                map[x+dir[i][0]][y+dir[i][1]]='X';
                dfs(x+dir[i][0],y+dir[i][1],sum+1);
                map[x+dir[i][0]][y+dir[i][1]]='.';
            }
        }
    }
}
int main(void)
{
    int i,f,si,sf,sum;
    while(scanf("%d%d%d",&m,&n,&t),!(0==m&&0==n&&0==t))
    {
        sum=0;
        escape=0;
        for(i=1;i<=m;i++)
        {
            for(f=1;f<=n;f++)
            {
                cin>>map[i][f];
                if(map[i][f]=='.')
                {
                    sum++;
                }
                else if(map[i][f]=='S')
                {
                    si=i;
                    sf=f;
                }
                else if(map[i][f]=='D')
                {
                    ei=i;
                    ef=f;
                }
            }
        }
        if(sum+1<t||(t-abs(ei-si)-abs(ef-sf))%2==1)
        {
            printf("NO\n");
        }
        else
        {
            map[si][sf]='X';
            dfs(si,sf,0);
            if(escape)
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
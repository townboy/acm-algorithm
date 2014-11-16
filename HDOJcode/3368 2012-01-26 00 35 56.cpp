******************************
    Author : townboy
    Submit time : 2012-01-26 00:35:56
    Judge Status : Accepted
    HDOJ Runid : 5294757
    Problem id : 3368
    Exe.time : 78MS
    Exe.memory : 180K
    https://github.com/townboy
******************************


#include<stdio.h>
int ans,dir[8][2]={0,1,0,-1,1,0,-1,0,1,1,-1,-1,1,-1,-1,1},res;
char map[100][100];
void dfs(int x,int y,int type,int flag,int sum)
{
    if(0==flag)
    {
        if('L'==map[x][y])
        {
            dfs(x+dir[type][0],y+dir[type][1],type,1,sum+1);
        }
        return ;
    }
    if(1==flag)
    {
        if('L'==map[x][y])
        {
            dfs(x+dir[type][0],y+dir[type][1],type,1,sum+1);
            return ;
        }
        if('*'==map[x][y])
        {
            return ;
        }
        if('D'==map[x][y])
        {
            res=sum;
            return ;
        }
    }
}
int main(void)
{
    int i,f,g,h,num,max;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        getchar();
        for(f=0;f<=9;f++)
        {
            for(g=0;g<=9;g++)
            {
                map[f][g]='*';    
            }
        }
        for(f=1;f<=8;f++)
        {
            for(g=1;g<=8;g++)
            {
                scanf("%c",&map[f][g]);    
            }
            getchar();
        }
        max=0;
        for(f=1;f<=8;f++)
        {
            for(g=1;g<=8;g++)
            {
                if('*'==map[f][g])
                {
                    ans=0;
                    for(h=0;h<8;h++)
                    {
                        res=0;
                        dfs(f+dir[h][0],g+dir[h][1],h,0,0);
                        ans=ans+res;
                    }
                    if(ans>max)
                    {
                        max=ans;
                    }
                }
            }
        }
        printf("Case %d: %d\n",i+1,max); 
    }
    return 0;
}
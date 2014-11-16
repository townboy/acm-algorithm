******************************
    Author : townboy
    Submit time : 2012-07-16 22:17:09
    Judge Status : Accepted
    HDOJ Runid : 6234047
    Problem id : 1426
    Exe.time : 156MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>

int flag,map[15][15],pr[15][15];

int check(int m,int n,int x)
{
    int i,f,heng,su;
    for(i=1;i<=9;i++)
    {
        if(x == map[i][n])
        {
            return -1;
        }    
    }
    for(f=1;f<=9;f++)
    {
        if(x == map[m][f])
        {
            return -1;
        }
    }
    heng=(m-1)/3+1;
    su=(n-1)/3+1;
    for(i=(heng-1)*3+1;i<=heng*3;i++)
    {
        for(f=(su-1)*3+1;f<=su*3;f++)
        {
            if(x == map[i][f])
            {
                return -1;
            }
        }
    }
    return 1;
}

void copy()
{
    int i,f;
    for(i=1;i<=9;i++)
    {
        for(f=1;f<=9;f++)
        {
            pr[i][f]=map[i][f];
        }
    }
}

void dfs(int m,int n)
{    
    int i;
    if(10 == m)
    {
        flag=1;
        copy();
        return ;
    }
    if(1 == flag)
    {
        return ;
    }
    if(-1 != map[m][n])
    {
        if(9 == n)
        {
            dfs(m+1,1);
        }
        else
        {
            dfs(m,n+1);
        }
        return ;
    }
    for(i=1;i<10;i++)
    {
        if(1 == check(m,n,i))
        {
            map[m][n]=i;
            if(9 == n)
            {
                dfs(m+1,1);
            }
            else
            {
                dfs(m,n+1);
            }            
        }
    }
    map[m][n]=-1;
}

int main()
{
    char x[10];
    int i,f,ji=0;
    while(scanf("%s",x)!=EOF)
    {
        if(0 != ji)
        {
            printf("\n");
        }
        ji++;
        flag=0;
        if('?' == x[0])
        {
            map[1][1]=-1;
        }
        else
        {
            map[1][1]=x[0]-'0';
        }
        for(i=1;i<=9;i++)
        {
            for(f=1;f<=9;f++)
            {
                if(1 == i&& 1 == f)
                {
                    continue;
                }
                scanf("%s",x);
                if('?' == x[0])
                {
                    map[i][f]=-1;
                }
                else
                {
                    map[i][f]=x[0]-'0';
                }    
            }
        }
        dfs(1,1);
        for(i=1;i<=9;i++)
        {
            for(f=1;f<=9;f++)
            {
                if(1 != f)
                {
                    printf(" ");
                }
                printf("%d",pr[i][f]);
            }
            printf("\n");
        }
    }
    return 0;
}
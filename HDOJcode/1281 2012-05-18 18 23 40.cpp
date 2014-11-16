******************************
    Author : townboy
    Submit time : 2012-05-18 18:23:40
    Judge Status : Accepted
    HDOJ Runid : 5961803
    Problem id : 1281
    Exe.time : 15MS
    Exe.memory : 1608K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int map[600][600],match[600],mk[600],l,r,sum,mkl[600];

int dfs(int x)
{
    int i,t;
    for(i=1;i<=r;i++)
    {
        if((1 == map[x][i])&&(0 == mk[i]))
        {
            mk[i]=1;
            t=match[i];
            match[i]=x;
            if((-1 == t)||(1 == dfs(t)))
            {
                return 1;
            }
            match[i]=t;
        }
    }
    return 0;
}

int xyl()
{
    int i,max=0;
    for(i=1;i<=l;i++)
    {
        memset(mk,0,sizeof(mk));
        if(1 == dfs(i))
        {
            max++;
        }
    }
    return max;
}

void chu()
{
    int i;
    sum=0;
    for(i=1;i<=r;i++)
    {
        match[i]=-1;
    }
    memset(map,0,sizeof(map));
}

void chuu()
{
    int i;
    for(i=1;i<=r;i++)
    {
        match[i]=-1;
    }
}

int main()
{
    int k,i,x,y,res,ji;
//    freopen("D:\\in.txt","r",stdin);
    ji=0;
    while(scanf("%d%d%d",&l,&r,&k)!=EOF)
    {
        ji++;
        chu();
        for(i=0;i<k;i++)
        {
            scanf("%d%d",&x,&y);
            map[x][y]=1;
        }
        res=xyl();
        
        for(i=1;i<=r;i++)
        {
            mkl[i]=match[i];
        }
        
        for(i=1;i<=r;i++)
        {
            if(-1 != mkl[i])
            {
                chuu();
                map[mkl[i]][i]=0;
                if(xyl() != res)
                {
                    sum++;
                }
                map[mkl[i]][i]=1;
            }
        }
        printf("Board %d have %d important blanks for %d chessmen.\n",ji,sum,res);        
    }

    return 0;
}
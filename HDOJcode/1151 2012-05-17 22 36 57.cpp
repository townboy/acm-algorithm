******************************
    Author : townboy
    Submit time : 2012-05-17 22:36:57
    Judge Status : Accepted
    HDOJ Runid : 5959502
    Problem id : 1151
    Exe.time : 0MS
    Exe.memory : 260K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int map[130][130],match[130],mk[130],n;

void chu()
{
    int i;
    memset(map,0,sizeof(map));
    for(i=0;i<=n;i++)
    {
        match[i]=-1;
    }
}

int dfs(int x)
{
    int i,t;
    for(i=1;i<=n;i++)
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
    int max=0,i;
    for(i=1;i<=n;i++)
    {
        memset(mk,0,sizeof(mk));
        if(1 == dfs(i))
        {
            max++;
        }
    }
    return max;
}

int main()
{
    int i,k,s,e,res,num,f;
//    freopen("D:\\in.txt","r",stdin);
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&n,&k);
        chu();
        for(f=0;f<k;f++)
        {
            scanf("%d%d",&s,&e);
            map[s][e]=1;
        }
        res=xyl();
        printf("%d\n",n-res);
    }
    return 0;
}

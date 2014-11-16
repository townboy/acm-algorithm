******************************
    Author : townboy
    Submit time : 2012-01-18 14:44:08
    Judge Status : Accepted
    HDOJ Runid : 5271888
    Problem id : 1572
    Exe.time : 0MS
    Exe.memory : 212K
    https://github.com/townboy
******************************


#include<stdio.h>
int ji,ren,num,hash[51],tai[10],map[40][40],val[1000000],a[10];
void dfs(int x,int sum)
{
    int i;
    if(ren+1==x)
    {
        val[ji]=sum;
        ji++;
        return ;
    }
    for(i=0;i<ren;i++)
    {
        if(0==hash[a[i]])
        {
            hash[a[i]]=1;
            tai[x]=a[i];
            dfs(x+1,sum+map[tai[x-1]][tai[x]]);
            hash[a[i]]=0;
        }
    }
}
int main(void)
{
    int min,i,f,num,flag[50],n,x;
    while(scanf("%d",&num),num)
    {
        ji=0;
        for(i=0;i<num;i++)
        {
            for(f=0;f<num;f++)
            {
                scanf("%d",&map[i][f]);
            }
        }
        scanf("%d",&n);
        for(i=0;i<num;i++)
        {
            flag[i]=0;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            flag[x]=1;
        }
        ren=0;
        for(i=0;i<num;i++)
        {
            hash[i]=0;
            if(1==flag[i])
            {
                a[ren]=i;
                ren++;
            }
        }
        for(i=0;i<=ren;i++)
        {
            tai[i]=0;
        }
        dfs(1,0);
        min=0;
        for(i=1;i<ji;i++)
        {
            if(val[min]>val[i])
            {
                min=i;
            }
        }
        printf("%d\n",val[min]);
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-07-03 16:52:49
    Judge Status : Accepted
    HDOJ Runid : 6122845
    Problem id : 1455
    Exe.time : 0MS
    Exe.memory : 192K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

int flag,n,zan[70],used[70],aim,stick;
int cmp(const void*a,const void*b)
{
    return *(int *)b-*(int *)a;
}

void dfs(int ans,int x,int pos)
{
    int i;
/*    printf("%d %d %d\n",ans,x,pos);
    for(i=0;i<n;i++)
    {
        printf("%d ",used[i]);
    }
    printf("\n");
*/    if(1 == flag)
    {
        return ;
    }
    if(ans == aim)
    {
        flag=1;
    }
    if(1 == used[pos])
    {
        return ;
    }
    if(stick-x == zan[pos])
    {
        used[pos]=1;
        if(ans+1 == aim)
        {
            flag=1;
            return ;
        }
        for(i=0;i<n;i++)
        {
            if(0 == used[i])
            {
                dfs(ans+1,0,i);        
                break;
            }
        }
        used[pos]=0;
        return ;
    }
    if(zan[pos] > stick-x)
    {
        return ;
    }
    for(i=pos+1;i<n;i++)
    {
        if(1 == used[i])
        {
            continue;
        }
        used[pos]=1;
        dfs(ans,x+zan[pos],i);
        used[pos]=0;
    }    
}

void chu()
{
    flag=0;
    memset(used,0,sizeof(used));
}

int main()
{
    int sum,i;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%d",&n),n)
    {
        chu();
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&zan[i]);
            sum+=zan[i];
        }
        qsort(zan,n,sizeof(zan[0]),cmp);
        for(i=zan[0];i<=sum;i++)
        {
            if(0 != sum%i)
            {
                continue;
            }
            aim=sum/i;
            stick=i;
            dfs(0,0,0);
            if(1 == flag)
            {
                printf("%d\n",i);
                break;        
            }
        }
    }    
    return 0;
}
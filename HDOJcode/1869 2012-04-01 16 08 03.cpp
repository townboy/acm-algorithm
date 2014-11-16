******************************
    Author : townboy
    Submit time : 2012-04-01 16:08:03
    Judge Status : Accepted
    HDOJ Runid : 5684582
    Problem id : 1869
    Exe.time : 31MS
    Exe.memory : 260K
    https://github.com/townboy
******************************


#include<stdio.h>
#define inf 100000000
int map[110][110];

void chu(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int f=0;f<n;f++)
        {
            map[i][f]=inf;
        }
        map[i][i]=0;
    }
}

int main()
{
    int i,f,k,s,e,m,n,flag;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        chu(n);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&s,&e);
            map[s][e]=map[e][s]=1;
        }
        for(k=0;k<n;k++)
        {
            for(i=0;i<n;i++)
            {
                for(f=0;f<n;f++)
                {
                    if(map[i][f]>map[i][k]+map[k][f])
                    {
                        map[i][f]=map[i][k]+map[k][f];
                    }
                }
            }
        }
        flag=0;
        for(i=0;i<n;i++)
        {
            for(f=0;f<n;f++)
            {
                if(7<map[i][f])
                {
                    flag=1;
                    break;
                }
            }
        }
        if(1==flag)
        { 
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-04-05 23:25:36
    Judge Status : Accepted
    HDOJ Runid : 5714605
    Problem id : 3342
    Exe.time : 0MS
    Exe.memory : 268K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int map[110][110],ru[110];

int main()
{
    int n,k,i,s,e,aim,ji;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%d",&n),n)
    {
        memset(ru,0,sizeof(ru));
        memset(map,0,sizeof(map));
        scanf("%d",&k);
        
        for(i=0;i<k;i++)
        {
            scanf("%d%d",&s,&e);
            if(1==map[s][e])
            {
                continue;    
            } 
            ru[e]++;
            map[s][e]=1;
        }
        
        for(ji=0;;ji++)
        {
            aim=-1;
            for(i=0;i<n;i++)
            {
                if(0==ru[i])
                {
                    aim=i;
                    break;    
                }
            }
            if(-1==aim)
            {
                break;
            }
            ru[aim]=-1;
            for(i=0;i<n;i++)
            {
                if(1==map[aim][i])
                {
                    ru[i]--;
                }
            }
        }
        if(n==ji)
        {
            printf("YES\n");
        }
        else
        { 
            printf("NO\n");
        }
    }
    return 0;
}
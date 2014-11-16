******************************
    Author : townboy
    Submit time : 2012-04-05 22:40:38
    Judge Status : Accepted
    HDOJ Runid : 5714204
    Problem id : 1285
    Exe.time : 31MS
    Exe.memory : 1628K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int ru[600],map[600][600];

int main()
{
    int n,k,aim,i,f,s,e;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(map,0,sizeof(map));
        memset(ru,0,sizeof(ru));
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
    
        for(i=0;i<n;i++)
        {
            aim=-1;
            for(f=1;f<=n;f++)
            {
                if(0==ru[f])
                {
                    aim=f;
                    break;
                }
            }
           
            ru[aim]=-1;
            for(f=1;f<=n;f++)
            {
                if(1==map[aim][f])
                {
                    ru[f]--;
                }
            }
            
            if(0==i)
            {
                printf("%d",aim);
            }
            else
            {
                printf(" %d",aim);
            }
        }
        printf("\n");
    }
    return 0;
}
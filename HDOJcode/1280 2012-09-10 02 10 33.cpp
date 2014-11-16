******************************
    Author : townboy
    Submit time : 2012-09-10 02:10:33
    Judge Status : Accepted
    HDOJ Runid : 6731575
    Problem id : 1280
    Exe.time : 0MS
    Exe.memory : 296K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int di[3100],hash[11000];

void chu()
{
    memset(hash,0,sizeof(hash));
}

int main()
{
    int flag,start,f,n,m,i;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        chu();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&di[i]);
            for(f=1;f<i;f++)
            {
                hash[di[i]+di[f]]++;
            }
        }
        start=10000;
        flag=0;
        while(0 != m)
        {
            if(0 == hash[start])
            {
                start--;                
            }
            else
            {
                m--;
                hash[start]--;
                if(1 == flag)
                {
                    printf(" ");
                }
                flag=1;
                printf("%d",start);
            }    
        }
        printf("\n");
    }
    return 0;
}
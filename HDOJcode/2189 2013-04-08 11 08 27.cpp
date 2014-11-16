******************************
    Author : townboy
    Submit time : 2013-04-08 11:08:27
    Judge Status : Accepted
    HDOJ Runid : 8028349
    Problem id : 2189
    Exe.time : 0MS
    Exe.memory : 232K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int su[200];
int ans[200];

void init()
{
    int i,f,g;
    ans[0]=1;
    for(i=2;i<=50;i++)
        if(0 == su[i])
            for(f=i+i;f<=150;f+=i)
                su[f]=1;
    for(i=2;i<=150;i++)
    {
        if(1 == su[i])    continue;    
        for(f=150;f>=2;f--)
        {
            for(g=1;;g++)
            {
                if(f-g*i < 0)    break;
                ans[f]+=ans[f-g*i];
            }
        }
    }
}

int main()
{
    int i,cas,n;
    scanf("%d",&cas);
    init();
    for(i=0;i<cas;i++)
    {
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2011-12-22 23:48:30
    Judge Status : Accepted
    HDOJ Runid : 5196235
    Problem id : 1536
    Exe.time : 140MS
    Exe.memory : 804K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int sg[20000],s[200],snum;
int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int dfs(int x)
{
    int i,zan[120],tmp;
    if(sg[x]!=-1)
    {
        return sg[x];
    }
    else
    {
        for(i=0;i<110;i++)
        {
            zan[i]=0;
        }
        for(i=0;i<snum;i++)
        {
            if((x-s[i])>=0)
            {
                tmp=dfs(x-s[i]);
                zan[tmp]=1;
            }
            else
            {
                break;
            }
        }
        for(i=0;;i++)
        {
            if(0==zan[i])
            {
                sg[x]=i;
                return i;
            }
        }
    }
}
int main(void)
{
    int i,zu,dui,ans,f,g,ge;
     while(scanf("%d",&snum),snum)
     {
         for(i=0;i<snum;i++)
         {
             scanf("%d",&s[i]);
         }
         qsort(s,snum,sizeof(s[0]),cmp);
         scanf("%d",&zu);
         for(g=0;g<20000;g++)
         {
             sg[g]=-1;
         }
         for(i=0;i<zu;i++)
         {
             scanf("%d",&dui);
             ans=0;
             for(f=0;f<dui;f++)
             {
                 scanf("%d",&ge);
                 ans=ans^dfs(ge);
             }
             if(0==ans)
             {
                 printf("L");
             }
             else
             {
                 printf("W");
             }     
         }
         printf("\n");
     }
return 0;
}
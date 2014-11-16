******************************
    Author : townboy
    Submit time : 2011-12-06 15:15:41
    Judge Status : Accepted
    HDOJ Runid : 5120909
    Problem id : 1325
    Exe.time : 15MS
    Exe.memory : 956K
    https://github.com/townboy
******************************


#include<stdio.h>
int g[100010],f[100010];
void merge(int x,int y)
{
    g[y]=x;
}
int main(void)
{
    int a,b,i,flag,sum,ji; 
    ji=1;
    while(scanf("%d%d",&a,&b),!((a<0)&&(b<0)))
    {
        if((0==a)&&(0==b))
        {
            printf("Case %d is a tree.\n",ji);
            ji++;
        }
        else
        {
        for(i=1;i<100000;i++)
        {
            g[i]=i;
            f[i]=0;
        }
        merge(a,b);
        f[a]=1;
        f[b]=1;
        flag=1;
        while(scanf("%d%d",&a,&b),!((0==a)&&(0==b)))
        {
            f[a]=1;
            f[b]=1;
           if(g[b]==b)
           {
               merge(a,b);
           }
           else
           {
               flag=0;
           }
          
        }
        if(1==flag)
        {
        
            sum=0;
             for(i=1;i<100000;i++)
            {
               if((g[i]==i)&&(1==f[i]))
               {
                   sum++;
               }
            }
            if(1==sum)
            {
                printf("Case %d is a tree.\n",ji);
            }
            else
            {
                printf("Case %d is not a tree.\n",ji);
            }
            
        }
        else
        {
            printf("Case %d is not a tree.\n",ji);
        }
        ji++;
        }
    }



return 0;
}
******************************
    Author : townboy
    Submit time : 2011-10-26 01:05:41
    Judge Status : Accepted
    HDOJ Runid : 4824266
    Problem id : 2034
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>

int main (void)
{   
    int i,f,n,m,a[105],b[105],c[105],d[105],num,tem;
    while(scanf("%d%d",&n,&m),!((n==0)&&(m==0)))
    {
        for(i=0;i<n;i++)
        { 
        scanf("%d",&a[i]);
        c[i]=1;
        }
        
        for(i=0;i<m;i++)
        { 
        scanf("%d",&b[i]);
        }
        
        for(i=0;i<n;i++)
        { 
            for(f=0;f<m;f++)
                if(a[i]==b[f])
                {    
                    c[i]=0;
                    break;
                }
        }
        num=0;
        for(i=0;i<n;i++)
        {
              if(c[i]==1)
              {
                  d[num]=a[i];
                  num++;
              }    
        }
        for(i=0;i<num;i++)
        {
            for(f=i+1;f<num;f++)
                if(d[f]<d[i])
                {
                tem=d[f];
                d[f]=d[i];
                d[i]=tem;
                }
        }
        
        
        
        
        for(i=0;i<num;i++)
        {
            printf("%d ",d[i]);
        }

        if(num==0)
            printf("NULL\n");
        else
             printf("\n"); 
    }

return 0;
}
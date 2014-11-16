******************************
    Author : townboy
    Submit time : 2011-10-27 23:22:30
    Judge Status : Accepted
    HDOJ Runid : 4838174
    Problem id : 2019
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int num,x,i,f,a[1000],flag;
    while(scanf("%d%d",&num,&x),!((num==0)&&(x==0)))
    {
        flag=0;
        for(i=0;i<num;i++)
        {
            scanf("%d",&a[i]);
        }
        if(num==0)
            printf("%d\n",x);
        else if(x<=a[0])
        {
            printf("%d",x);
            for(f=0;f<num;f++)
                 printf(" %d",a[f]);
            printf("\n");
        } 
        else if(x>=a[num-1])
        {   
            for(f=0;f<num;f++)
                 printf("%d ",a[f]);
            printf("%d",x);
            printf("\n");
        }
        else
        {   
            printf("%d",a[0]);
            for(f=1;f<num;f++)
            if((x<=a[f])&&(flag==0))
            {
                printf(" %d %d",x,a[f]);
                flag=1;
            }
            else
                printf(" %d",a[f]);
            printf("\n");        
        
        }
 
    
    
    
    }






  return 0;
}


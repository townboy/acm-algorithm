******************************
    Author : townboy
    Submit time : 2011-11-02 22:20:45
    Judge Status : Accepted
    HDOJ Runid : 4885434
    Problem id : 1019
    Exe.time : 625MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main (void)
{
    int num,i,f,g,n,flag,a[1000],max;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        for(f=0;f<n;f++)
        {
            scanf("%d",&a[f]);
        }
        
        max=a[0];
        for(f=0;f<n;f++)
        {
            if(a[f]>max)
                max=a[f];
        }

        for(f=1;;f++)
        {
            flag=1;
            for(g=0;g<n;g++)
            {
                if((f*max)%a[g]!=0)
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
            {
                printf("%d\n",f*max);
                break;
            }
        }
    
    
    
    }


return 0;
}
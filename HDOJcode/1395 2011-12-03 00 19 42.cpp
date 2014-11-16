******************************
    Author : townboy
    Submit time : 2011-12-03 00:19:42
    Judge Status : Accepted
    HDOJ Runid : 5101389
    Problem id : 1395
    Exe.time : 15MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int num,yu,ji,dy,i;
    while(scanf("%d",&num)!=EOF)
    {
        if((0==num%2)||(1==num))
        {
            printf("2^? mod %d = 1\n",num);
        }
        else 
        {
            yu=2;
            ji=1;
            for(i=0;;i++)
            {
                if(1==yu)
                {
                    printf("2^%d mod %d = 1\n",ji,num);
                    break;
                }
                yu=yu*2;
                ji=ji+1;
                if(yu>num)
                {
                    yu=yu%num;
                }
            }
        }

    
    
    }

return 0;
} 

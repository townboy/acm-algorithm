******************************
    Author : townboy
    Submit time : 2011-10-29 23:58:43
    Judge Status : Accepted
    HDOJ Runid : 4853872
    Problem id : 1021
    Exe.time : 31MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main (void)
{
    int n,i,x,y,z;

    while(scanf("%d",&n)!=EOF)
    {
            x=7;
            y=11;
            for(i=0;i<n-1;i++)
            {
                z=y+x;
                z=z%3;
                x=y;
                y=z;
            }
            
            if(z%3==0)
                printf("yes\n");
            else
                printf("no\n");
    }
    
return 0;



}




******************************
    Author : townboy
    Submit time : 2011-10-30 00:26:11
    Judge Status : Accepted
    HDOJ Runid : 4853961
    Problem id : 1406
    Exe.time : 343MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main (void)
{
    int num,i,x,y,f,sum,g,flag,temp;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        flag=0;
        scanf("%d%d",&x,&y);
        if(x>y)
        {
            temp=x;
            x=y;
            y=temp;        
        }
        for(f=x;f<=y;f++)
        {
            sum=0;
            for(g=1;g<f;g++)
            {
                if(f%g==0)
                    sum=sum+g;
            }   
            if(sum==f)
                flag++;
        }
        printf("%d\n",flag);
    }
            
                
        
    
return 0;



}




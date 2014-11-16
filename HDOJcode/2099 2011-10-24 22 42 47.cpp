******************************
    Author : townboy
    Submit time : 2011-10-24 22:42:47
    Judge Status : Accepted
    HDOJ Runid : 4817640
    Problem id : 2099
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main (void)
{
    int a,b,i,flag;
   while(scanf("%d%d",&a,&b),!(a==0&&b==0))
   {    flag=0;
        for(i=0;i<100;i++)
        {
           if((a*100+i)%b==0)
           {
                flag++;
                if(flag==1)
                {
                    if(i<=9)
                         printf("0%d",i);
                    else
                        printf("%d",i);
                }
                else
                {
                    if(i<=9)
                         printf(" 0%d",i);
                       else
                        printf(" %d",i);
                }
           
           }


        
        
        
        }
        printf("\n");
   
   
   
   
   }
   return 0;





}
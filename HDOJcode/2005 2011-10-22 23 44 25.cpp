******************************
    Author : townboy
    Submit time : 2011-10-22 23:44:25
    Judge Status : Accepted
    HDOJ Runid : 4805941
    Problem id : 2005
    Exe.time : 0MS
    Exe.memory : 184K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
    void main ()
    {   

        int a[14],month,yeah,day,i,ji;
        a[1]=31;
        a[2]=28;
        a[3]=31;
        a[4]=30;
        a[5]=31;
        a[6]=30;
        a[7]=31;
        a[8]=31;
        a[9]=30;
        a[10]=31;
        a[11]=30;
        a[12]=31;

        while(scanf("%d/%d/%d",&yeah,&month,&day)!=EOF)
        {
           
           
               ji=0;
               for(i=1;i<month;i++)
               {
               ji=ji+a[i];
               }
               ji=ji+day;        
              
               if(yeah%4==0&&(yeah%100!=0||yeah%400==0))
               {
               if(month<3)
                  printf("%d\n",ji);
               else
                  printf("%d\n",ji+1);
               }
                   
               else
                  printf("%d\n",ji);

        
        
        }



    }
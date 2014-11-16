******************************
    Author : townboy
    Submit time : 2011-11-16 00:34:43
    Judge Status : Accepted
    HDOJ Runid : 4987821
    Problem id : 1166
    Exe.time : 156MS
    Exe.memory : 440K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
     int num,n,f,i,a[60000],z1,z2,sum;
     char z[10];
     scanf("%d",&num);
     for(i=0;i<num;i++)
     {
         printf("Case %d:\n",i+1);
         scanf("%d",&n);
         for(f=1;f<=n;f++)
         {
             scanf("%d",&a[f]);
         }
         while(scanf("%s",z),z[0]!='E')
         {
             scanf("%d%d",&z1,&z2);
             if(z[0]=='A')
             {
                 a[z1]=a[z1]+z2;
             }
             else if(z[0]=='S')
             {
                 a[z1]=a[z1]-z2;
             }
             else
             {
                 sum=0;
                 for(f=z1;f<=z2;f++)
                 {
                     sum=sum+a[f];
                 }
                 printf("%d\n",sum);
             }
         
         }
     
     
     }




     



    return 0;
}

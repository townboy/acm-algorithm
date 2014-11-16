******************************
    Author : townboy
    Submit time : 2012-06-22 15:02:58
    Judge Status : Accepted
    HDOJ Runid : 6091111
    Problem id : 1757
    Exe.time : 0MS
    Exe.memory : 200K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int tmp[10][10];
void mul(int a[][10],int b[][10],int p)
{
     int i,j,k;
     memset(tmp,0,sizeof(tmp));
     for(i=0;i<10;i++)
     {
     for(k=0;k<10;k++)
     {
       if(a[i][k])
       {
        for(j=0;j<10;j++)
        {
         if(b[k][j])
           tmp[i][j]=(tmp[i][j]+a[i][k]*b[k][j])%p;
        }
       }
     }
     }
     for(i=0;i<10;i++)
     for(j=0;j<10;j++)
     a[i][j]=tmp[i][j];
}

int main()
{
    int k,m;
    while(scanf("%d%d",&k,&m)==2)
    {
         int i,j;
         int init[10][10];
         int ret[10];
         int ans[10][10];
         for(i=0;i<10;i++)
         ret[i]=i;
         for(i=0;i<10;i++)
         scanf("%d",&init[0][i]);
         for(i=1;i<10;i++)
         {
         for(j=0;j<10;j++)
         {
           if(i-j==1)
           init[i][j]=1;
           else
           init[i][j]=0;
         }
         }
         for(i=0;i<10;i++)
         for(j=0;j<10;j++)
         ans[i][j]=(i==j);
         if(k<10)
         printf("%d\n",k%m);
         else
         {
           int x=k-9;
           for(;x;x>>=1)
           {
             if(x&1)
             mul(ans,init,m);
             mul(init,init,m);
           }
           int sum=0;
           for(i=0;i<10;i++)
           {
            sum=(sum+ans[0][i]*ret[9-i])%m;
           }
           printf("%d\n",sum);
         }
    }
    return 0;
}
         
         
        

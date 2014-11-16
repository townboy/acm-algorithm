******************************
    Author : townboy
    Submit time : 2011-11-26 21:53:42
    Judge Status : Accepted
    HDOJ Runid : 5063086
    Problem id : 2566
    Exe.time : 0MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
int sumf,n,m;
void s1(int num,int sum);
void s2(int num,int sum);
void s5(int num,int sum);
void pan(int num,int sum);
void s1(int num,int sum)
{
    int i;
    if((num==n)&&(sum==m))
    {
        sumf++;        
    }
    else
    {
        for(i=num;i<=n;i++)
        {
            s2(i,i);
        }
    }
    
}
void s2(int num,int sum)
{
    int i;
    if((num==n)&&(sum==m))
    {
        sumf++;
    }
    else
    {
        for(i=num;i<=n;i++)
        {
            s5(i,sum+(i-num)*2);
        }
    }

}
void s5(int num,int sum)
{
    int i;
    if((num==n)&&(sum==m))
    {
        sumf++;
    }
    else
    {
        for(i=num;i<=n;i++)
        {
            pan(i,sum+(i-num)*5);
        }
    }
}
void pan(int num,int sum)
{
    if((n==num)&&(m==sum))
    {
        sumf++;
    }
}
int main(void)
{
    int i,num;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&n,&m);
        sumf=0;
        s1(0,0);        
        printf("%d\n",sumf);
    }

return 0;
} 

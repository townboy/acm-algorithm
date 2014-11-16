******************************
    Author : townboy
    Submit time : 2011-11-30 16:50:28
    Judge Status : Accepted
    HDOJ Runid : 5085598
    Problem id : 1058
    Exe.time : 62MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>
int c[4]={2,3,5,7},a[4];
__int64 b[6000];
void me(int num)
{
    int min,i;
    min=0;
    for(i=1;i<4;i++)
    {
        if(b[a[i]]*c[i]<b[a[min]]*c[min])
        {
            min=i;
        }
    }
    b[num]=b[a[min]]*c[min];
    for(i=0;i<4;i++)
    {
        if(b[a[i]]*c[i]==b[num])
        {
            a[i]++;
        }
    }
}
int main(void)
{
    int num,i,f;
    for(i=0;i<4;i++)
    {
        a[i]=0;
    }
    b[0]=1;
    for(f=1;f<=5842;f++)
    {
        me(f);
    }
    while(scanf("%d",&num),num)
    {
        
        if((1==num%10)&&(11!=num%100))
        {
            printf("The %dst humble number is %I64d.\n",num,b[num-1]);
        }
        else if((2==num%10)&&(12!=num%100))
        {
            printf("The %dnd humble number is %I64d.\n",num,b[num-1]);
        }
        else if((3==num%10)&&(13!=num%100))
        {
            printf("The %drd humble number is %I64d.\n",num,b[num-1]);
        }
        else
        {
            printf("The %dth humble number is %I64d.\n",num,b[num-1]);
        }
    
        
    }
}
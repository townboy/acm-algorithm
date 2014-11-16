******************************
    Author : townboy
    Submit time : 2011-12-07 14:59:19
    Judge Status : Accepted
    HDOJ Runid : 5127434
    Problem id : 2503
    Exe.time : 671MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
int qm(int a,int b)
{
    int i;
    if(a<b)
    {
        i=b;
        b=a;
        a=i;
    }
    for(i=1;;i++)
    {
        if((i*a)%b==0)
        {
            return i*a;
        }
    }
}
int qd(int a,int b)
{
    int i;
    if(a<b)
    {
        i=b;
        b=a;
        a=i;
    }
    for(i=b;;i--)
    {
        if((0==b%i)&&(0==a%i))
        {
            return i;
        }
    }
    
}
int main(void)
{
    int num,i,s1,s2,s,x1,x2,max,min;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d%d%d",&s1,&x1,&s2,&x2);
        min=qm(x1,x2);
        s=s1*(min/x1)+(min/x2)*s2;
        max=qd(s,min);
        printf("%d %d\n",s/max,min/max);
    }
return 0;
}

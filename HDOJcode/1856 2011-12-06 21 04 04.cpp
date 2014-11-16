******************************
    Author : townboy
    Submit time : 2011-12-06 21:04:04
    Judge Status : Accepted
    HDOJ Runid : 5123302
    Problem id : 1856
    Exe.time : 250MS
    Exe.memory : 78528K
    https://github.com/townboy
******************************


#include<stdio.h>
int a[10000010],b[10000010],max;
int find(int g)
{
    int x,last;
    x=g;
    while(a[x]!=x)
    {
        x=a[x];
    }
    while(a[g]!=g)
    {
        last=g;
        g=a[g];
        a[last]=x;
    }
    return x;
}
void merge(int x,int y)
{
    a[x]=y;
    b[y]=b[y]+b[x];
    b[x]=0;
    if(b[y]>max)
    {
        max=b[y];
    }
}
int main(void)
{
    int i,num,x,y;
    while(scanf("%d",&num)!=EOF)
    {
        max=1;
        for(i=1;i<=10000000;i++)
        {
                a[i]=i;
            b[i]=1;
        }
        for(i=0;i<num;i++)
        {
            scanf("%d%d",&x,&y);
            if(find(x)!=find(y))
            {
                merge(find(x),find(y));
            }
        }
        printf("%d\n",max);
    }
return 0;

}
******************************
    Author : townboy
    Submit time : 2012-02-27 21:49:22
    Judge Status : Accepted
    HDOJ Runid : 5426032
    Problem id : 1022
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int top,j,stack[10000],num,tai[20000],t;
char o1[10000],o2[10000]; 
void xiao(int x,int y)
{
    if(x==y)
    {
        tai[t]=-1;
        t++;
        j++;
        top--;
        if(-1==top)
        {
            return;
        }
        xiao(stack[top],o2[j]-'0');
    }
}
int check()
{
    int i;
    top=-1;
    j=0;
    t=0;
    for(i=0;i<num;i++)
    {
        if(8==top)
        {
            return 0;
        }
        tai[t]=1;
        t++;
        top++;
        stack[top]=o1[i]-'0';
        xiao(stack[top],o2[j]-'0');
    }
    if(-1==top)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int i;
    while(scanf("%d",&num)!=EOF)
    {
        scanf("%s%s",o1,o2);
        if(1==check())
        {
            printf("Yes.\n");
            for(i=0;i<2*num;i++)
            {
                if(1==tai[i])
                {
                    printf("in\n");
                }
                else
                {
                    printf("out\n");
                }            
            } 
            printf("FINISH\n");
        }
        else
        {
            printf("No.\n");
            printf("FINISH\n");
        }
    }
    return 0;
}
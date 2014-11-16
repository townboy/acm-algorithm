******************************
    Author : townboy
    Submit time : 2011-12-20 16:59:20
    Judge Status : Accepted
    HDOJ Runid : 5187245
    Problem id : 1849
    Exe.time : 15MS
    Exe.memory : 180K
    https://github.com/townboy
******************************


#include<stdio.h>
char ch[2000][15];
void trans(int i,int x)
{
    int ji;
    ji=0;
    while(x!=0)
    {
        ch[i][ji]=x%2;
        x=x/2;
        ji++;
    }
}
int main(void)
{
    int num,i,f,x,sum,zong;
    while(scanf("%d",&num),num)
    {
        for(i=0;i<num;i++)
        {
            for(f=0;f<=12;f++)
            {
                ch[i][f]=0;
            }
            scanf("%d",&x);
            trans(i,x);
        }
        zong=0;
        for(i=0;i<=12;i++)
        {
            sum=0;
            for(f=0;f<num;f++)
            {
                sum=sum+ch[f][i];
            }
            zong=zong+sum%2;
        }
        if(0==zong)
        {
            printf("Grass Win!\n");
        }
        else
        {
            printf("Rabbit Win!\n");
        }
        
       
    }
    return 0;
}

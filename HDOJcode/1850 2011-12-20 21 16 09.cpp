******************************
    Author : townboy
    Submit time : 2011-12-20 21:16:09
    Judge Status : Accepted
    HDOJ Runid : 5188446
    Problem id : 1850
    Exe.time : 0MS
    Exe.memory : 160K
    https://github.com/townboy
******************************


#include<stdio.h>
char ch[110][21];
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
    int num,i,f,x,sum,zong,ji,flag;
    while(scanf("%d",&num),num)
    {
        for(i=0;i<num;i++)
        {
            for(f=0;f<=20;f++)
            {
                ch[i][f]=0;
            }
            scanf("%d",&x);
            trans(i,x);
        }
        zong=0;
        flag=-1;
        for(f=0;f<=20;f++)
        {
            sum=0;
            for(i=0;i<num;i++)
            {
                sum=sum+ch[i][f];
            }
            zong=zong+sum%2;
            if(1==sum%2)
            {
                flag=f;            
            }
        }
        if(0==zong)
        {
            printf("0\n");
        }
        else
        {
            ji=0;
            for(i=0;i<num;i++)
            {       
                if(1==ch[i][flag])
                {
                     ji++;
                }
            }
            printf("%d\n",ji);
        }
    }
    return 0;
}
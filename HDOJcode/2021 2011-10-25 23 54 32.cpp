******************************
    Author : townboy
    Submit time : 2011-10-25 23:54:32
    Judge Status : Accepted
    HDOJ Runid : 4824030
    Problem id : 2021
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int num,shu,i,x;
    while(scanf("%d",&num),num)
    {
        shu=0;
        for(i=0;i<num;i++)
        {
        scanf("%d",&x);
        shu=x/100+shu;
        shu=(x%100)/50+shu;  
        shu=(x%50)/10+shu; 
        shu=(x%10)/5+shu;  
        shu=(x%5)/2+shu; 
        shu=((x%5)%2)+shu; 
        }
        printf("%d\n",shu);


    }

return 0;
}


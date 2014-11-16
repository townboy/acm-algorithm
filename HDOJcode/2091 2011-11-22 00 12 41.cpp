******************************
    Author : townboy
    Submit time : 2011-11-22 00:12:41
    Judge Status : Accepted
    HDOJ Runid : 5031091
    Problem id : 2091
    Exe.time : 0MS
    Exe.memory : 184K
    https://github.com/townboy
******************************


#include<stdio.h>
void pr(char x,int y)
{
    int i;
    for(i=0;i<y;i++)
    {
        printf("%c",x);    
    }
}


int main(void)
{
    int num,i,ji=0;
    char c;
    while(scanf("%c",&c),c!='@')
    {
        if(ji!=0)
            printf("\n");
        scanf("%d",&num);
        getchar();
        if(num!=1)
        {
            pr(' ',num-1);
        pr(c,1); 
        printf("\n");
        for(i=2;i<num;i++)
        {
            pr(' ',num-i);
            pr(c,1);
            pr(' ',1+2*(i-2));
            pr(c,1);
            printf("\n");
        }
        pr(c,2*num-1);
        printf("\n");
        }
        else
        {
            printf("%c\n",c);
        }
        ji++;
        
    }
    
return 0;
}
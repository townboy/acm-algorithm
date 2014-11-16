******************************
    Author : townboy
    Submit time : 2011-11-17 16:02:30
    Judge Status : Accepted
    HDOJ Runid : 5004143
    Problem id : 2082
    Exe.time : 421MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int a[30],ji;
void js(int x,int num,int ge)
{
    int i;
    if(x+ge*num<=50)
    {
        if(ge!=0)
        {
            ji++;
        }
        
        if(num-1>=1)
        { 
            for(i=0;i<=a[num-1];i++)
            {
                js(x+ge*num,num-1,i);
            }
        }
    }
}


int main(void)
{
    int num,i,f;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        ji=0;
        for(f=1;f<=26;f++)
        {
            scanf("%d",&a[f]);
        }
        
        for(f=0;f<=a[26];f++)
        {
                js(0,26,f);
        }
        printf("%d\n",ji);
    }

    return 0;

}

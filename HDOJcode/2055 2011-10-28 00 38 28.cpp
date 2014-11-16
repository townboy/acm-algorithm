******************************
    Author : townboy
    Submit time : 2011-10-28 00:38:28
    Judge Status : Accepted
    HDOJ Runid : 4838481
    Problem id : 2055
    Exe.time : 0MS
    Exe.memory : 204K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int main(void)
{
    int num,b,i;
    char a;

    scanf("%d",&num);

    for(i=0;i<num;i++)
    {
        getchar();
        scanf("%c%d",&a,&b);
        if((a>=65)&&(a<=90))
            printf("%d\n",b+a-64);
        else
            printf("%d\n",b-(a-96));
  
  
    }
  return 0;
}


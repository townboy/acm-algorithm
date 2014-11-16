******************************
    Author : townboy
    Submit time : 2011-10-24 00:17:21
    Judge Status : Accepted
    HDOJ Runid : 4812421
    Problem id : 2081
    Exe.time : 0MS
    Exe.memory : 204K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int main(void)
{
    int a,num,i;
    char ch[15];
    scanf("%d",&num);
    getchar();
    for(i=0;i<num;i++)
    {
    gets(ch);
    printf("6");
          for(a=6;a<11;a++)
        { 
            printf("%c",ch[a]);
        }
        printf("\n");
    }

return 0;
}
******************************
    Author : townboy
    Submit time : 2012-06-30 16:09:59
    Judge Status : Accepted
    HDOJ Runid : 6110722
    Problem id : 3079
    Exe.time : 0MS
    Exe.memory : 200K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
char ch[110000];

int map[5]={'A','E','I','O','U'};

void fun(int x)
{
    int i;
    if(x >= 'a')
    {
        x-=('a'-'A');    
    }
    for(i=0;i<5;i++)
    {
        if(x == map[i])
        {
            printf("%c",x);    
            return ;
        }
    }    
    printf("%c",x+'a'-'A');
    return ;
}

int main()
{
    int num,i,f,len;
    scanf("%d",&num);
    getchar();
    for(i=0;i<num;i++)
    {
        gets(ch);
        len=strlen(ch);
        for(f=0;f<len;f++)
        {
            fun(ch[f]);                
        }
        printf("\n");
    }
    return 0;
}
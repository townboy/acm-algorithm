******************************
    Author : townboy
    Submit time : 2013-02-05 20:18:15
    Judge Status : Accepted
    HDOJ Runid : 7596910
    Problem id : 1720
    Exe.time : 15MS
    Exe.memory : 248K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>

char ch1[110],ch2[110];
int a,b;

int check(int tem)
{
    if(tem <= '9' && tem >= '0')
        return tem-'0';
    if(tem <= 'F' && tem >= 'A')
        return tem-'A'+10;
    else
        return tem-'a'+10;
}

void turn()
{
    int i,len=strlen(ch1);
    a=b=0;
    for(i=0;i<len;i++)
    {
        a*=16;
        a+=check(ch1[i]);
    }
    len=strlen(ch2);
    for(i=0;i<len;i++)
    {
        b*=16;
        b+=check(ch2[i]);
    }    
}

int main()
{
    int i;
    while(scanf("%s%s",ch1,ch2)!=EOF)
    {
        turn();
        printf("%d\n",a+b);
    }
    return 0;
}
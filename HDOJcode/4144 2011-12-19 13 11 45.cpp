******************************
    Author : townboy
    Submit time : 2011-12-19 13:11:45
    Judge Status : Accepted
    HDOJ Runid : 5183275
    Problem id : 4144
    Exe.time : 0MS
    Exe.memory : 224K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
int main(void)
{
    int num,i,f,sum;
    char ch[20000],ch2[20000];
    while(scanf("%d",&num)!=EOF)
    {
        getchar();
        gets(ch);
        for(i=0;i<num;i++)
        {
            if(ch[i]>='A'&&ch[i]<='Z')
            {
                ch2[i]='0';
            }
            else
            {
                ch2[i]='1';
            }
        }
        ch2[i]='\0';
        for(i=0;i<num/5;i++)
        {
            sum=0;
            for(f=5*i;f<5*(i+1);f++)
            {
                sum=sum+(ch2[f]-'0')*pow(2,(5*i+4)-f);
            }
            printf("%c",sum+'A');
        }
        printf("\n");
    }
return 0;
}
******************************
    Author : townboy
    Submit time : 2012-06-17 16:15:47
    Judge Status : Accepted
    HDOJ Runid : 6074718
    Problem id : 1328
    Exe.time : 15MS
    Exe.memory : 200K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
char ch[10010];
int main()
{
    int i,num,p[30],len,f;
//    freopen("D:\\in.txt","r",stdin);
    for(i=0;i<25;i++)
    {
        p[i]='A'+i+1;
    }
    p[25]='A';
    scanf("%d",&num);
    getchar();
    for(i=0;i<num;i++)
    {
        gets(ch);
        len=strlen(ch);
        printf("String #%d\n",i+1);
        for(f=0;f<len;f++)
        {
            printf("%c",p[ch[f]-'A']);
        }
        printf("\n\n");
    }
    return 0;
}
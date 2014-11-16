******************************
    Author : townboy
    Submit time : 2012-12-23 18:51:27
    Judge Status : Accepted
    HDOJ Runid : 7434631
    Problem id : 4492
    Exe.time : 0MS
    Exe.memory : 280K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>

int k,cas;
char ch[100];

int main()
{
    int i,len,t;
    int n,f,pos;

    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d",&k);
        printf("%d ",k);
        getchar();

        gets(ch);
        scanf("%d",&n);
        
        len=strlen(ch);
        pos=0;
        
        for(f=0;f<n;f++)
        {
            scanf("%d",&t);
            pos=(pos+t+len)%len;
            printf("%c",ch[pos]);
        }
        printf("\n");
    }    
    return 0;
}
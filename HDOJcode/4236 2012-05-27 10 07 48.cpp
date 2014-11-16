******************************
    Author : townboy
    Submit time : 2012-05-27 10:07:48
    Judge Status : Accepted
    HDOJ Runid : 6005827
    Problem id : 4236
    Exe.time : 0MS
    Exe.memory : 280K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int main()
{
    char ch[100000];
    int i,num,j,r,f,g,len;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&j,&r);
        printf("%d ",j);
        scanf("%s",ch);
        len=strlen(ch);
        for(f=0;f<len;f++)
        {
            for(g=0;g<r;g++)
            {
                printf("%c",ch[f]);
            }    
        }
        printf("\n");
    }
    return 0;
}
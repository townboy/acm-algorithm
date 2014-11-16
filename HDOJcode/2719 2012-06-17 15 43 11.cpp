******************************
    Author : townboy
    Submit time : 2012-06-17 15:43:11
    Judge Status : Accepted
    HDOJ Runid : 6074601
    Problem id : 2719
    Exe.time : 0MS
    Exe.memory : 196K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
char ch[100010];
int t[7]={' ','!','$','%','(',')','*'};
char h[7][4];

int main()
{
    int len,i,f;
    strcpy(h[0],"%20");
    strcpy(h[1],"%21");
    strcpy(h[2],"%24");
    strcpy(h[3],"%25");
    strcpy(h[4],"%28");
    strcpy(h[5],"%29");
    strcpy(h[6],"%2a");
//    freopen("D:\\in.txt","r",stdin);
    while(gets(ch)!=NULL)
    {    
        len=strlen(ch);
        if('#' == ch[0])
        {
            break;
        }
        for(i=0;i<len;i++)
        {
            for(f=0;f<7;f++)
            {
                if(t[f] == ch[i])
                {
                    printf("%s",h[f]);
                    break;
                }
            }
            if(7 == f)
            {
                printf("%c",ch[i]);
            }
        }    
        printf("\n");
    }
    return 0;
}
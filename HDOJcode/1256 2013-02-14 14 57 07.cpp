******************************
    Author : townboy
    Submit time : 2013-02-14 14:57:07
    Judge Status : Accepted
    HDOJ Runid : 7614556
    Problem id : 1256
    Exe.time : 0MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>

char ch[10];
int sukuan,sq,xq;

void print(char a,int tem)
{
    int i;
    for(i=0;i<tem;i++)
        printf("%c",a);
}

int main()
{
    int cas,i,f,hei;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%s %d",ch,&hei);
        if(0 != i)
            printf("\n");
        sukuan=1+hei/6;
        sq=(hei-3)/2;
        xq=hei-3-sq;                        
        print(' ',sukuan);
        print(ch[0],xq);
        printf("\n");
        
        for(f=0;f<sq;f++)
        {
            print(ch[0],sukuan);
            print(' ',xq);
            print(ch[0],sukuan);
            printf("\n");
        }
        
        print(' ',sukuan);
        print(ch[0],xq);
        printf("\n");
        
        for(f=0;f<xq;f++)
        {
            print(ch[0],sukuan);
            print(' ',xq);
            print(ch[0],sukuan);
            printf("\n");
        }
        print(' ',sukuan);
        print(ch[0],xq);
        printf("\n");                
    }
    return 0;
}
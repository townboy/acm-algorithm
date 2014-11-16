******************************
    Author : townboy
    Submit time : 2011-11-24 21:25:29
    Judge Status : Accepted
    HDOJ Runid : 5048782
    Problem id : 2072
    Exe.time : 0MS
    Exe.memory : 668K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int main(void)
{
    int sum,start,i,len,a[1000],ji,f,flag;
    char ch[10000],g[1000][500];
    while(gets(ch),ch[0]!='#')
    {
        len=strlen(ch);
        ch[len]=' ';
        ch[len+1]='\0';
        len=len+1;
        start=0;
        ji=0;
        
        for(i=0;i<len;i++)
        {
            if(ch[i]==' ')
            {
                if(start==i)
                {
                    start=i+1;
                }
                else
                {
                    for(f=start;f<i;f++)
                    {
                        g[ji][f-start]=ch[f];
                    }
                    g[ji][f-start]='\0';
                    start=i+1;
                    ji++;
                }
                
            
            }
        }

        for(i=0;i<ji;i++)
        {
            flag=0;
            for(f=0;f<i;f++)
            {
                if(0==strcmp(g[i],g[f]))
                {
                    flag=1;
                    break;
                }
            }
            if(0==flag)
            {
                a[i]=1;
            }
            else
            {
                a[i]=0;
            }
        }
        sum=0;
        for(i=0;i<ji;i++)
        {
            if(1==a[i])
            {
                sum++;
            }
        }
        printf("%d\n",sum);


    }

return 0;
}
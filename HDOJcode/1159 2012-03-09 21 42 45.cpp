******************************
    Author : townboy
    Submit time : 2012-03-09 21:42:45
    Judge Status : Accepted
    HDOJ Runid : 5508661
    Problem id : 1159
    Exe.time : 78MS
    Exe.memory : 4124K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int val[1000][1000];
char ch1[1000],ch2[1000];

int maxx(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    int len1,len2,i,f;
    ch1[0]='V';
    ch2[0]='V';
    while(scanf("%s",&ch1[1])!=EOF)
    {
         scanf("%s",&ch2[1]);
         len1=strlen(ch1);
         len2=strlen(ch2);
         memset(val,0,sizeof(val));
         for(i=1;i<=len1-1;i++)
         {
             for(f=1;f<=len2-1;f++)
             {
                 if(ch1[i]==ch2[f])
                 {
                     val[i][f]=val[i-1][f-1]+1;     
                 }
                 else
                 {
                     val[i][f]=maxx(val[i-1][f],val[i][f-1]);
                 }
             }
         }
         printf("%d\n",val[len1-1][len2-1]);
    }
    return 0;
}
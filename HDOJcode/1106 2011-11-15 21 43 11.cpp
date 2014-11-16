******************************
    Author : townboy
    Submit time : 2011-11-15 21:43:11
    Judge Status : Accepted
    HDOJ Runid : 4986523
    Problem id : 1106
    Exe.time : 0MS
    Exe.memory : 244K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int main(void)
{
    int a[1100],ji,i,len,f,sum,start;
    char ch[1100];
    while(gets(ch)!=NULL)
    {
        len=strlen(ch);

        for(i=len-1;i>=0;i--)
        {
            ch[i+1]=ch[i];
        }
        ch[0]='5';
        ch[len+1]='5';

        start=0;
        ji=0;
        for(i=start+1;;i++)
        {
            sum=0;
            if((ch[i]=='5')&&(ch[i-1]=='5'))
            {
                start++;         
            }
            else if((ch[i]=='5')&&(ch[i-1]!='5'))
            {
                for(f=i-1;f>=start+1;f--)
                {
                    sum=sum+(ch[f]-'0')*pow(10,i-f-1);
                }
                start=i;
                a[ji]=sum;
                ji++;
            }
            if(i==len+1)
            {
                break;
            }
        }
        qsort(a,ji,sizeof(a[0]),cmp);
        for(i=0;i<ji;i++)
        {
            printf("%d",a[i]);
            if(i!=ji-1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
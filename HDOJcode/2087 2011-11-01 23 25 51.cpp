******************************
    Author : townboy
    Submit time : 2011-11-01 23:25:51
    Judge Status : Accepted
    HDOJ Runid : 4877009
    Problem id : 2087
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int main (void)
{
    int num,where,lena,lenb,i;
    char a[1000],b[1000];
    while(scanf("%s",a),a[0]!='#')
    {
        scanf("%s",b);
        lena=strlen(a);
        lenb=strlen(b);
        where=num=0;
        for(i=0;i<lena;i++)
        {
            if(a[i]==b[where])
            {
                if(where==lenb-1)
                {    
                    num++;
                    where=0;
                }
                else
                {
                    where++;
                }
            }
            else
            {
                where=0;
            }
        }
        
        printf("%d\n",num);
    
    
    }
    return 0;



}
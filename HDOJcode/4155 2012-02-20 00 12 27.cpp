******************************
    Author : townboy
    Submit time : 2012-02-20 00:12:27
    Judge Status : Accepted
    HDOJ Runid : 5380414
    Problem id : 4155
    Exe.time : 78MS
    Exe.memory : 184K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int tai[10];
int dfs(int sum)
{
    int i;
    if(sum>31)
    {
        return 1;
    }
    for(i=1;i<=6;i++)
    {
        if(4!=tai[i])
        {
            tai[i]++;
            if(0==dfs(sum+i))
            {
                tai[i]--;
                return 1;
            }
            tai[i]--;
        }
    }
    return 0;
}
int main()
{
    int i,res,len,sum;
    char ch[50];
    while(gets(ch)!=NULL)
    {
        for(i=0;i<7;i++)
        {
            tai[i]=0;
        } 
        len=strlen(ch);
        if(0==len)
        {
            continue;
        }    
        sum=0;
        for(i=0;i<len;i++)
        {
            sum=sum+ch[i]-'0';
            tai[ch[i]-'0']++;
        }
        res=dfs(sum);
        printf("%s",ch);
        if(0==(res+len%2)%2)
        {
            printf(" B\n");
        }
        else
        {
            printf(" A\n");
        }
    }
    return 0;
}
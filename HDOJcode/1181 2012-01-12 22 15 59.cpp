******************************
    Author : townboy
    Submit time : 2012-01-12 22:15:59
    Judge Status : Accepted
    HDOJ Runid : 5250290
    Problem id : 1181
    Exe.time : 0MS
    Exe.memory : 156K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int escape,flag[30],map[30][30];
void seh(int x)
{
    int i;
    if(x=='m'-'a')
    {
        escape=1;
        return ;
    }
    if(1==flag[x])
    {
        return ;
    }
    if(1==escape)
    {
        return ;
    }
    flag[x]=1;
    for(i=0;i<26;i++)
    {
        if(map[x][i])
        {
            seh(i);    
        }
       
    }
}
int main(void)
{
    int i,f,len;
    char ch[1000];
    while(gets(ch)!=NULL)
    {
        for(i=0;i<26;i++)
        {
            for(f=0;f<26;f++)
            {
                map[i][f]=0;
            }
        }
        for(i=0;i<26;i++)
        {
            flag[i]=0;
        }
        escape=0;
        len=strlen(ch);
        map[ch[0]-'a'][ch[len-1]-'a']=1;
        while(gets(ch),ch[0]!='0')
        {
            len=strlen(ch);
            map[ch[0]-'a'][ch[len-1]-'a']=1;
        }
        seh(1);
        if(1==escape)
        {
            printf("Yes.\n");
        }
        else
        {
            printf("No.\n");
        }
    }
    
    return 0;
}
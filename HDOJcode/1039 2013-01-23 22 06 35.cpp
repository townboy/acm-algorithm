******************************
    Author : townboy
    Submit time : 2013-01-23 22:06:35
    Judge Status : Accepted
    HDOJ Runid : 7537413
    Problem id : 1039
    Exe.time : 15MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>

int yy[5]={'a','e','i','o','u'};
int len;
char ch[50];

int check(int tem)
{
    int i;
    for(i=0;i<5;i++)
        if(tem == yy[i])
            return 1;
    return 0;
}

int yuan()
{
    int i;
    for(i=0;i<len;i++)
    {
        if(1 == check(ch[i]))
            return 1;
    }
    return 0;
}

int three()
{
    int i,last=0;
    for(i=0;i<len;i++)
    {    
        if(1 == check(ch[i]))
        {
            if(last > 0)
                last++;
            else
                last=1;
        }
        else
        {
            if(last < 0)
                last--;
            else
                last=-1;
        }
        if(last == 3 || last == -3)
            return 1;
    }
    return 0;
    return 0;
}

int same()
{
    int i;
    for(i=0;i<len-1;i++)
        if(ch[i] == ch[i+1] && ch[i] != 'e' && ch[i] != 'o')
            return 1;
    return 0;
}

int main()
{
    while(scanf("%s",ch)!=EOF)
    {
        if(0 == strcmp(ch,"end"))
            return 0;
        len=strlen(ch);
        if(0 == yuan())
        {
            printf("<%s> is not acceptable.\n",ch);
            continue;        
        }
        if(1 == three())
        {
            printf("<%s> is not acceptable.\n",ch);
            continue;        
        }
        if(1 == same())
        {
            printf("<%s> is not acceptable.\n",ch);
            continue;
        }        
        printf("<%s> is acceptable.\n",ch);
    }
    return 0;
}
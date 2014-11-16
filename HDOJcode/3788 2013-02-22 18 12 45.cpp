******************************
    Author : townboy
    Submit time : 2013-02-22 18:12:45
    Judge Status : Accepted
    HDOJ Runid : 7641865
    Problem id : 3788
    Exe.time : 0MS
    Exe.memory : 232K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>

int s1,s2,s3;
int a,b,z,j;
char ch[1100];

int fun()
{
    int zpos,jpos,t;
    int i,len=strlen(ch);
    z=0;
    j=0;
    for(i=0;i<len;i++)
    {
        if('z' == ch[i])
        {
            z++;
            zpos=i;
        }
        else if('j' == ch[i])
        {
            j++;    
            jpos=i;
        }
        else if('o' != ch[i])
            return 0;
    }
    if(1 != z || 1 != j || jpos < zpos)
        return 0;

    s1=0;
    for(i=0;;i++)
        if('o' == ch[i])        
            s1++;
        else
            break;
    s2=0;
    for(i++;;i++)
        if('o' == ch[i])        
            s2++;
        else
            break;
    s3=0;
    for(i++;i<len;i++)
        s3++;        
    
    if(s2 == 0)
        return 0;    
    t=s2-1;
    if(s3-t*s1 == s1)
        return 1;
    return 0;
}

int main()
{
    while(scanf("%s",ch)!=EOF)
    {
        if(1 == fun())
            printf("Accepted\n");
        else
            printf("Wrong Answer\n");
    }
    return 0;
}
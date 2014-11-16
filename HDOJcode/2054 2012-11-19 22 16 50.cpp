******************************
    Author : townboy
    Submit time : 2012-11-19 22:16:50
    Judge Status : Accepted
    HDOJ Runid : 7202841
    Problem id : 2054
    Exe.time : 0MS
    Exe.memory : 3528K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<memory.h>

char a[210000],b[210000];
int num1[410000],num2[410000];
int lena,lenb,loca,locb;

void put()
{
    int i;
    for(i=0;i<loca;i++)
    {    
        num1[200001-(loca-i)]=a[i]-'0';
    }
    for(i=loca+1;i<lena;i++)
    {
        num1[200000+i-loca]=a[i]-'0';
    }
    for(i=0;i<locb;i++)
    {    
        num2[200001-(locb-i)]=b[i]-'0';
    }
    for(i=locb+1;i<lenb;i++)
    {
        num2[200000+i-locb]=b[i]-'0';
    }
}

int equal()
{
    int i;
    for(i=1;i<=400000;i++)
    {
        if(num1[i] != num2[i])
        {
            return 0;
        }
    }
    return 1;
}

void chu()
{
    memset(num1,0,sizeof(num1));
    memset(num2,0,sizeof(num2));
}

int main()
{
    int i,flag;
    while(scanf("%s%s",a,b)!=EOF)
    {
        lena=strlen(a);
        lenb=strlen(b);
        chu();
        flag=0;    
        for(i=0;i<lena;i++)
        {
            if('.' == a[i])
            {
                flag=1;
                loca=i;
            }
        }    
        if(0 == flag)
        {
            loca=lena;
        }        
        
        flag=0;    
        for(i=0;i<lenb;i++)
        {
            if('.' == b[i])
            {
                flag=1;
                locb=i;
            }
        }    
        if(0 == flag)
        {
            locb=lenb;
        }        
        
        put();
        if(1 == equal())
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
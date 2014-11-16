******************************
    Author : townboy
    Submit time : 2013-03-01 21:08:51
    Judge Status : Accepted
    HDOJ Runid : 7672614
    Problem id : 1230
    Exe.time : 0MS
    Exe.memory : 252K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<memory.h>

int su[110],hash[110];
char ch1[1000],ch2[1000];
int wei1[30],wei2[30];
int l1,l2;

int ex()
{
    if(1 == strlen(ch1) && 1 == strlen(ch2) && '0' == ch1[0] && '0' == ch2[0])
        return 1;
    return 0;
}

void yu()
{
    int i,ji=0,f;
    for(i=2;i<=105;i++)
        if(0 == su[i])
            for(f=i*i;f<=105;f+=i)
                su[f]=1;        
    for(i=2;i<=105;i++)
    {
        if(0 == su[i])    
        {
            ji++;
            hash[ji]=i;
        }
    }
}

void fun()
{
    int tem,sum=0,i,len1=strlen(ch1),len2=strlen(ch2);
    l1=l2=0;
    for(i=0;i<len1;i++)
    {
        if(',' == ch1[i])
        {
            l1++;
            wei1[l1]=sum;
            sum=0;
            continue;
        }
        sum*=10;
        sum+=ch1[i]-'0';
    }
    l1++;
    wei1[l1]=sum;
    sum=0;
    
    for(i=0;i<len2;i++)
    {
        if(',' == ch2[i])
        {
            l2++;
            wei2[l2]=sum;
            sum=0;
            continue;
        }
        sum*=10;
        sum+=ch2[i]-'0';
    }
    l2++;
    wei2[l2]=sum;
    
    for(i=1;i<=l1/2;i++)
    {    
        tem=wei1[i];
        wei1[i]=wei1[l1+1-i];
        wei1[l1+1-i]=tem;
    }
    
    for(i=1;i<=l2/2;i++)
    {    
        tem=wei2[i];
        wei2[i]=wei2[l2+1-i];
        wei2[l2+1-i]=tem;
    }
}

void cal()
{
    int i,jin=0;
    for(i=1;i<=27;i++)
    {
        wei1[i]+=wei2[i]+jin;
        jin=wei1[i]/hash[i];
        wei1[i]%=hash[i];
    }
}

void print()
{
    int i,ji=0;
    for(i=27;i>0;i--)
    {
        if(1 == ji)
            printf(",%d",wei1[i]);        
        else if(0 != wei1[i])
        {
            ji=1;
            printf("%d",wei1[i]);
        }    
    }
    printf("\n");    
}

void debug()
{
    int i;
    for(i=1;i<=5;i++)
    {
        printf(" %d",wei1[i]);
    }
    printf("\n");
}

void chu()
{
    memset(wei1,0,sizeof(wei1));
    memset(wei2,0,sizeof(wei2));
}

int main()
{
    yu();
    while(scanf("%s%s",ch1,ch2)!=EOF)
    {
        if(1 == ex())
            break;
        chu();
        fun();
        cal();
        print();
    }    
    return 0;
}
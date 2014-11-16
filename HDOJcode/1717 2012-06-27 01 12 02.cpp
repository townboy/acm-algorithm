******************************
    Author : townboy
    Submit time : 2012-06-27 01:12:02
    Judge Status : Accepted
    HDOJ Runid : 6102563
    Problem id : 1717
    Exe.time : 15MS
    Exe.memory : 232K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>

int len;
char ch[100000];

int gcd(int da,int xiao)
{
    int yu;
    while(0 != xiao)
    {
        yu=da%xiao;
        da=xiao;
        xiao=yu;
    }
    return da;
}

__int64 gcdd(__int64 da,__int64 xiao)
{
    __int64 yu;
    while(0 != xiao)
    {
        yu=da%xiao;
        da=xiao;
        xiao=yu;
    }
    return da;
}

void f1()
{
    __int64 a1,a2,m1,m2;
    int i,duan;
    for(i=2;i<len;i++)
    {
        if('(' == ch[i])
        {
            duan=i;
            break;
        }
    }
    a1=a2=0;
    m1=m2=1;
    for(i=2;i<len-1;i++)
    {
        if(i == duan)
        {
            continue;
        }
        a2*=10;
        a2+=ch[i]-'0';
        m2*=10;
    }
    m1=m2;
    a1=a2;
    for(i=duan+1;i<len-1;i++)
    {
        a1*=10;
        a1+=ch[i]-'0';
        m1*=10;
    }
    printf("%I64d/%I64d\n",(a1-a2)/gcdd((m1-m2),(a1-a2)),(m1-m2)/gcdd((m1-m2),(a1-a2)));
}

void f2()
{
    int i,shang=0,xia=1;
    for(i=2;i<len;i++)
    {
        xia*=10;
        shang*=10;
        shang+=ch[i]-'0';
    }
    printf("%d/%d\n",shang/gcd(xia,shang),xia/gcd(xia,shang));
}

void fun()
{
    len=strlen(ch);
    if(')' == ch[len-1])
    {
        f1();
    }
    else
    {    
        f2();
    }
}

int main()
{
    int num,i;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%s",ch);
        fun();
    }
}

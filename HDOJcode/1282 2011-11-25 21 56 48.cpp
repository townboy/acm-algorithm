******************************
    Author : townboy
    Submit time : 2011-11-25 21:56:48
    Judge Status : Accepted
    HDOJ Runid : 5055595
    Problem id : 1282
    Exe.time : 0MS
    Exe.memory : 212K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
#include<string.h>
int pan(char a[])
{
    int i,len,flag;
    flag=1;
    len=strlen(a);
    for(i=0;i<(len/2);i++)
    {
        if(a[i]!=a[len-1-i])
        {
            flag=0;
            break;
        }
    }
    if(0==flag)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}
void fan(char a[])
{
    int len,i;
    char tem;
    len=strlen(a);
    for(i=0;i<len/2;i++)
    {
        tem=a[i];
        a[i]=a[len-1-i];
        a[len-1-i]=tem;
    }
}
int tod(char a[])
{
    int sum,len,i;
    len=strlen(a);
    sum=0;
    for(i=0;i<len;i++)
    {
        sum=sum+(a[i]-'0')*pow(10,len-i-1);
    }
    return sum;
}
void tos(int sum,char a[])
{
    int i;
    a[0]='0';
    a[1]='\0';
    for(i=0;sum!=0;i++)
    {
        a[i]=sum%10+'0';
        sum=sum/10;
    }
    a[i]='\0';
} 
int main(void)
{
    int f,res,b[300],ji;
    char a[300][20],c[20];
    while(scanf("%s",&a[0])!=EOF)
    {
        strcpy(c,a[0]);
        res=pan(a[0]);
        ji=1;
        for(ji=1;0==res;ji++)
        {
            b[ji]=tod(a[ji-1]);
            fan(a[ji-1]);
            b[ji]=b[ji]+tod(a[ji-1]);
            tos(b[ji],a[ji]);
            res=pan(a[ji]);
        }
        printf("%d\n",ji-1);
        printf("%s",c);
        for(f=1;f<ji;f++)
        {
            printf("--->");
            printf("%s",a[f]);
        }
        printf("\n");
    }
return 0;
}
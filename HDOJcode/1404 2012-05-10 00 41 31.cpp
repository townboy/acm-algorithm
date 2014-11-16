******************************
    Author : townboy
    Submit time : 2012-05-10 00:41:31
    Judge Status : Accepted
    HDOJ Runid : 5921185
    Problem id : 1404
    Exe.time : 171MS
    Exe.memory : 4112K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>

int np[1100000];
int d[10]={1,10,100,1000,10000,100000,1000000};
char ch[10];

void quan(int x,int j)
{
    int i;
    x=x*10;
    for(i=0;i<j;i++)
    {
        np[x+i]=1;
    }
}

int wei(int x)
{
    int j;
    j=0;
    while(x != 0)
    {
        j++;
        x=x/10;
    }
    return j;
}

void turn(int x)
{
    int i,len=wei(x),j,f,q;
    for(i=0;i<len;i++)
    {
        q=(x%d[i+1])/d[i];
        for(f=1;f+q<=9;f++)
        {
            np[x+f*d[i]]=1;
        }
    }
    
    if(6 == len)
    {
        return ;
    }
    
    x=x*10;
    np[x]=1;
    len++;
    j=10;
    while(len < 6) 
    {
        quan(x,j);
        j=j*10;
        len++;
        x=x*10;
    }
}

int shu()
{
    int i,len=strlen(ch),j=1,sum=0;
    for(i=len-1;i>=0;i--)
    {
        sum+=j*(ch[i]-'0');
        j*=10;
    }
    return sum;
}

int main()
{
    int i;

    np[0]=1;
    np[1]=0;
    for(i=1;i<1000000;i++)
    {
        if(0 == np[i])
        {
            turn(i);
        }
    }

    while(gets(ch)!=NULL)
    {
        if('0' == ch[0])
        {
            printf("Yes\n");
        }
        else
        {
            if(1 == np[shu()])
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
    return 0;
}
******************************
    Author : townboy
    Submit time : 2013-01-24 14:18:45
    Judge Status : Accepted
    HDOJ Runid : 7539530
    Problem id : 1073
    Exe.time : 15MS
    Exe.memory : 560K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>

using namespace std;

char ch[5100],c1[5100],c2[5100];
string oj[5100],own[5100];
int ji1,ji2,sum1,sum2;
int fea[3]={' ','\t','\n'};

void print()
{
    int i;
    for(i=0;i<ji1;i++)
    {
        cout<<oj[i]<<endl;
    }
    for(i=0;i<ji2;i++)
    {
        cout<<own[i]<<endl;
    }
}

int check(int tem)
{
    int i;
    for(i=0;i<3;i++)
        if(fea[i] == tem)
            return 1; 
    return 0;
}    

void fun()
{
    int f,i,len;
    sum1=0;
    for(i=0;i<ji1;i++)
    {
        len=oj[i].length();
        for(f=0;f<len;f++)
        {
            if(1 == check(oj[i][f]))
                continue;
            c1[sum1]=oj[i][f];            
            sum1++;
        }    
    }

    sum2=0;
    for(i=0;i<ji2;i++)
    {
        len=own[i].length();
        for(f=0;f<len;f++)
        {
            if(1 == check(own[i][f]))
                continue;
            c2[sum2]=own[i][f];            
            sum2++;
        }    
    }
}

int nei()
{
    int i;
    fun();
    if(sum1 != sum2)
        return 0;
    for(i=0;i<sum1;i++)
        if(c1[i] != c2[i])
            return 0;
    return 1;
}

int cmp()
{
    int i;
    if(ji1 != ji2)
        return 0;
    for(i=0;i<ji1;i++)
        if(oj[i] != own[i])
            return 0;
    return 1;
}

int main()
{
    int i,cas;

    scanf("%d",&cas);
    getchar();
    for(i=0;i<cas;i++)
    {
        gets(ch);
        ji1=0;
        while(gets(ch)!=NULL)
        {
            if(0 == strcmp(ch,"END"))
                break;
            oj[ji1]=ch;
            ji1++;
        }
        
        gets(ch);
        ji2=0;
        while(gets(ch)!=NULL)
        {
            if(0 == strcmp(ch,"END"))
                break;
            own[ji2]=ch;
            ji2++;
        }
    
        if(1 == cmp())
        {
            printf("Accepted\n");
            continue;
        }
        if(1 == nei())
        {
            printf("Presentation Error\n");
            continue;
        }
        printf("Wrong Answer\n");
    }
    return 0;
}
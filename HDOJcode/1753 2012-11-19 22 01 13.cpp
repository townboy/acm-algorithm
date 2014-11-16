******************************
    Author : townboy
    Submit time : 2012-11-19 22:01:13
    Judge Status : Accepted
    HDOJ Runid : 7202637
    Problem id : 1753
    Exe.time : 0MS
    Exe.memory : 300K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h> 
#include<string.h>

int lena,lenb; 
int num1[1100],num2[1100],sum[1100]; 
char a[410],b[410]; 
int loca,locb,aim; 

void chu()
{
    memset(num1,0,sizeof(num1));
    memset(num2,0,sizeof(num2)); 
    memset(sum,0,sizeof(sum)); 
} 

void put()
{
    int i;
    for(i=0;i<loca;i++)
    {    
        num1[501-(loca-i)]=a[i]-'0'; 
    }
    for(i=loca+1;i<lena;i++)
    {
        num1[500+i-loca]=a[i]-'0'; 
    } 
    for(i=0;i<locb;i++)
    {    
        num2[501-(locb-i)]=b[i]-'0'; 
    }
    for(i=locb+1;i<lenb;i++)
    {
        num2[500+i-locb]=b[i]-'0'; 
    } 
}     

void add()
{
    int i,jin=0; 
    for(i=1000;i>0;i--)
    {
        sum[i]=(jin+num1[i]+num2[i])%10;
        jin=(jin+num1[i]+num2[i])/10;
    }
}
 
void check()
{
    int i,flag=0;
    for(i=1000;i>=501;i--)
    {
        if(0 == flag && 0 != sum[i])
        {
            aim=i;
            flag=1;
        } 
    } 
    if(0 == flag)
    {
        aim=-1;
    }
} 
 
void print()
{
    int i,flag=0;
    for(i=1;i<=500;i++)
    {
        if(1 == flag)
        {
            printf("%d",sum[i]); 
        }
        else if(0 != sum[i]) 
        {
            printf("%d",sum[i]); 
            flag=1; 
        }
    }
    check(); 
    if(-1 == aim)
    {
        printf("\n");
        return ;
    }
    printf(".");    
    for(i=501;i<=aim;i++)
    {
        printf("%d",sum[i]);
    }
    printf("\n");
}

void debug()
{
    int i;
    printf("%d %d\n",loca,lena); 
    for(i=490;i<=510;i++)
    {
        printf("%d",sum[i]); 
    } 
    printf("\n"); 
} 
 
int main()
{
    int i,flag; 
    while(scanf("%s%s",a,b)!=EOF)
    {
        chu(); 
        lena=strlen(a);
        lenb=strlen(b);
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
            a[lena]='.';
            loca=lena;
            lena++; 
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
            b[lenb]='.';
            locb=lenb; 
            lenb++; 
        } 
        put();    
        add(); 
        print();
    } 
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-08-28 22:41:11
    Judge Status : Accepted
    HDOJ Runid : 6673589
    Problem id : 1228
    Exe.time : 0MS
    Exe.memory : 248K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>

char dig[4][15]; 
int a,b; 

int turn(int x)
{
    if(0 == strcmp(dig[x],"zero")) 
    {
        return 0; 
    }    
    if(0 == strcmp(dig[x],"one")) 
    {
        return 1; 
    }
    if(0 == strcmp(dig[x],"two")) 
    {
        return 2; 
    }
    if(0 == strcmp(dig[x],"three")) 
    {
        return 3; 
    }
    if(0 == strcmp(dig[x],"four")) 
    {
        return 4; 
    }
    if(0 == strcmp(dig[x],"five")) 
    {
        return 5; 
    }
    if(0 == strcmp(dig[x],"six"))
    {
        return 6; 
    }
    if(0 == strcmp(dig[x],"seven")) 
    {
        return 7; 
    }
    if(0 == strcmp(dig[x],"eight")) 
    {
        return 8; 
    }
    if(0 == strcmp(dig[x],"nine")) 
    {
        return 9; 
    } 
} 

int main()
{
    int x;
    while(1)
    {
        scanf("%s",dig[0]);  
        a=turn(0); 
        scanf("%s",dig[1]);
        if('+' != dig[1][0])
        {
            scanf("%s",dig[2]); 
            a*=10;
            a+=turn(1);     
        } 
        scanf("%s",dig[2]);      
        b=turn(2); 
        scanf("%s",dig[3]);
        if('=' != dig[3][0])
        {
            scanf("%s",dig[0]);        
            b*=10;
            b+=turn(3);    
        } 
        if(0 == a+b)
        {
            break; 
        } 
        printf("%d\n",a+b); 
    } 
    return 0; 
} 
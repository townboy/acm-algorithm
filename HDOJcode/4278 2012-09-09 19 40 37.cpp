******************************
    Author : townboy
    Submit time : 2012-09-09 19:40:37
    Judge Status : Accepted
    HDOJ Runid : 6728283
    Problem id : 4278
    Exe.time : 0MS
    Exe.memory : 252K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string>
#include<math.h> 
 
char ch[1100]; 

int turn(int x)
{
    if(x > 8)
    {
        return x-2; 
    } 
    if(x > 3)
    {
        return x-1; 
    } 
    return x; 
} 

int main()
{
    int len,i,sum; 
    while(gets(ch)!=NULL)
    {
        if('0' == ch[0])
        {
            break; 
        }
        len=strlen(ch);
        sum=0; 
        for(i=len-1;i>=0;i--)
        {
            sum+=(int)(pow(8,len-1-i)+0.5)*turn(ch[i]-'0'); 
        }    
        printf("%s: %d\n",ch,sum); 
    } 
    return 0; 
} 
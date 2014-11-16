******************************
    Author : townboy
    Submit time : 2013-03-02 15:17:13
    Judge Status : Accepted
    HDOJ Runid : 7675902
    Problem id : 4461
    Exe.time : 0MS
    Exe.memory : 248K
    https://github.com/townboy
******************************


#include<stdio.h>

int sro[7]={16,7,8,1,1,2,3}; 
char ch[7]; 
int red,black; 
int ma,pao; 

int main()
{
    int f,n,cas,i;
    scanf("%d",&cas); 
    for(i=0;i<cas;i++)
    {
        red=black=0; 
        ma=pao=0; 
        scanf("%d",&n);
        for(f=0;f<n;f++)
        {
            scanf("%s",ch); 
            red+=sro[ch[0]-'A']; 
            if(ch[0] == 'B')
                ma=1;
            if(ch[0] == 'C')
                pao=1;     
        } 
        if((0 == ma || 0 == pao) && red>1)
            red--; 
        
        scanf("%d",&n);
        ma=pao=0; 
        for(f=0;f<n;f++)
        {
            scanf("%s",ch); 
            black+=sro[ch[0]-'A']; 
            if(ch[0] == 'B')
                ma=1;
            if(ch[0] == 'C')
                pao=1;     
        }
        if((0 == ma || 0 == pao) && black>1)
            black--; 
        
        if(red == black)
            printf("tie\n"); 
        else if(red > black)
            printf("red\n"); 
        else
            printf("black\n"); 
    } 
    return 0; 
} 
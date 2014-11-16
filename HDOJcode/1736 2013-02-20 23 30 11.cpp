******************************
    Author : townboy
    Submit time : 2013-02-20 23:30:11
    Judge Status : Accepted
    HDOJ Runid : 7636077
    Problem id : 1736
    Exe.time : 0MS
    Exe.memory : 244K
    https://github.com/townboy
******************************


    #include<stdio.h>
    #include<string>
    #include<iostream> 
    using namespace std; 
    
    char last,ch;
    int yuan[4]={',','.','!','?'};
    string ti[4]={"£¬","¡£","£¡","£¿"};
    string tem;
    
    int main()
    {
     int hash=0,i,ji=0;
     last=0;
    
    while(scanf("%c",&ch)!=EOF)
     {
        tem=""; 
         tem=tem+last+ch; 
         
        if(last == '<')
         {
             if('<' == ch)
             {    
                 printf("¡¶");
                 ch=0;
                 hash=1;
             }
             else
                 printf("<"); 
         }
         else if(last == '>')
         {
             if('>' == ch)
             {    
                 printf("¡·");
                 ch=0;
                 hash=1; 
             }
             else
                 printf(">"); 
         }

        if(tem == "¡°" || tem == "¡±")
            ji^=1;
        
        if(0 == hash)
        {
            if(',' == ch)
                printf("£¬");
            else if('.' == ch)
                printf("¡£");
            else if('!' == ch)
                printf("£¡");
            else if('?' == ch)
                printf("£¿");
            else if(ch == '"')
             {
                 if(0 == ji)
                     printf("¡°");
                 else
                     printf("¡±");
                 ji^=1;
            }
            else if('<' == ch || '>' == ch)
            {}
            else
                printf("%c",ch);
        }         
          last=ch;
          hash=0;
    }
    if('<' == last || '>' == last)
        printf("%c",last);
    return 0;
}
******************************
    Author : townboy
    Submit time : 2012-06-17 16:56:00
    Judge Status : Accepted
    HDOJ Runid : 6074875
    Problem id : 2629
    Exe.time : 0MS
    Exe.memory : 196K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
char ch[100];

int main()
{
    int i,num;    
    scanf("%d",&num);
    getchar();
    for(i=0;i<num;i++)
    {
        gets(ch);
        printf("He/She is from ");
        if('3' == ch[0])
        {
            if('3' == ch[1])
            {
                printf("Zhejiang");
            }
            else
            {
                printf("Shanghai");
            }
        }
        else if('1' == ch[0])
        {
            printf("Beijing");
        }
        else if('7' == ch[0])
        {
            printf("Taiwan");
        }
        else if('5' == ch[0])
        {
            printf("Tibet");
        }
        else if('2' == ch[0])
        {
            printf("Liaoning");
        }
        else if('8' == ch[0])
        {
            if('1' == ch[1])
            {
                printf("Hong Kong");        
            }
            else
            {
                printf("Macao");
            }
        }
        printf(",and his/her birthday is on %c%c,%c%c,%c%c%c%c based on the table.\n",ch[10],ch[11],ch[12],ch[13],ch[6],ch[7],ch[8],ch[9]);
    }
    return 0;
}
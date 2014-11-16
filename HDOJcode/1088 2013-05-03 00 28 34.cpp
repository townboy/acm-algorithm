******************************
    Author : townboy
    Submit time : 2013-05-03 00:28:34
    Judge Status : Accepted
    HDOJ Runid : 8221694
    Problem id : 1088
    Exe.time : 0MS
    Exe.memory : 308K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

int main()
{
    int sum;
    int flag=0;
    string ch;
    sum=0;
    while(cin >>  ch)
    {
        if("<br>" == ch)
        {
            puts("");
            sum=0;
        }
        else if("<hr>" == ch)
        {
            if(0 != sum)
                puts("");
            for(int i=0;i<80;i++)
                printf("-");
            puts("");
            sum=0;
        }
        else 
        {
            if(sum+1+ch.length() > 80)
            {
                sum=0;
                puts("");
            }
            
            if(0 != sum){
                printf(" ");
                sum ++;
            }
            cout<<ch;
            sum+=ch.length();
        }
    }
    puts("");
    return 0;
}
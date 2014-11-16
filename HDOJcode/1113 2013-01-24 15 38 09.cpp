******************************
    Author : townboy
    Submit time : 2013-01-24 15:38:09
    Judge Status : Accepted
    HDOJ Runid : 7540076
    Problem id : 1113
    Exe.time : 15MS
    Exe.memory : 300K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<map>
#include<string>
#include<iostream>

using namespace std;

int ji;
string tem,dic[1100];

int cmp(const void *a,const void *b)
{
    if(*(string *)a > *(string *)b)
         return 1;
    return -1;
}

int equ(string a,string b)
{
    int i,hash[26];
    if(a.length() != b.length())
        return 0;
    memset(hash,0,sizeof(hash));
    for(i=0;i<a.length();i++)
        hash[a[i]-'a']++;
    for(i=0;i<b.length();i++)
        hash[b[i]-'a']--;
    for(i=0;i<26;i++)
        if(0 != hash[i])
            return 0;
    return 1;
} 

int main()
{
    int flag,i;
    ji=0;
    while(cin>>tem)
    {
        if(tem == "XXXXXX")
            break;
        dic[ji]=tem;
        ji++;
    }
    qsort(dic,ji,sizeof(dic[0]),cmp);        

    while(cin>>tem)
    {
        if("XXXXXX" == tem)
            break;
        flag=0;
        for(i=0;i<ji;i++)
        {
            if(1 == equ(dic[i],tem))
            {
                flag=1;
                cout<<dic[i]<<endl;
            }
        }
        if(0 == flag)
            printf("NOT A VALID WORD\n");
        printf("******\n");
    }
    return 0;
}
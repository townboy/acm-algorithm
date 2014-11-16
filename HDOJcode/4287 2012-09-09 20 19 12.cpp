******************************
    Author : townboy
    Submit time : 2012-09-09 20:19:12
    Judge Status : Accepted
    HDOJ Runid : 6728831
    Problem id : 4287
    Exe.time : 62MS
    Exe.memory : 448K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<map>
using namespace std;

map<int,int>mp; 
int order[5100];
int pan[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
char ch[10];

void chu()
{
    mp.clear(); 
} 

int main()
{
    int sum,i,f,g,len,num,n,m,k;
    scanf("%d",&num);
    for(i=0;i<num;i++) 
    {
        scanf("%d%d",&n,&m); 
        chu(); 
        for(f=0;f<n;f++)
        {
            scanf("%d",&k); 
            mp[k]=0; 
            order[f]=k; 
        } 
        for(f=0;f<m;f++)
        {
            scanf("%s",ch);
            len=strlen(ch);
            sum=0;
            for(g=0;g<len;g++)
            {
                sum*=10;
                sum+=pan[ch[g]-'a'];
            }    
            mp[sum]++;
        } 
        for(f=0;f<n;f++)
        {
            printf("%d\n",mp[order[f]]);
        } 
    } 
    return 0; 
} 
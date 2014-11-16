******************************
    Author : townboy
    Submit time : 2013-04-03 18:20:16
    Judge Status : Accepted
    HDOJ Runid : 7976807
    Problem id : 2115
    Exe.time : 0MS
    Exe.memory : 272K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

struct node 
{
    int min,sec;
    string name;
    friend bool operator < (node a,node b)
    {
        if(a.min == b.min && a.sec == b.sec)
            return a.name < b.name;
        if(a.min > b.min || (a.min == b.min && a.sec > b.sec))
            return false;
        return true;
    }
};
struct node que[15];

int n,rank[15];

void ans()
{
    int i;
    cout << que[0].name<<" 1\n";
    rank[0]=1;
    for(i=1;i<n;i++)
    {
        cout << que[i].name;
        if(que[i].min == que[i-1].min && que[i].sec == que[i-1].sec)
            rank[i]=rank[i-1];
        else
            rank[i]=i+1;
        printf(" %d\n",rank[i]);
    }
}

int main()
{
    int i,cas=0; 
    while(scanf("%d",&n),n)
    {
        cas++;
        for(i=0;i<n;i++)
        {
            cin >> que[i].name;
            scanf("%d:%d",&que[i].min,&que[i].sec);
        }
        sort(que,que+n);
        if(1 != cas)
            printf("\n");
        printf("Case #%d\n",cas);
        ans();
    }
    return 0;
}
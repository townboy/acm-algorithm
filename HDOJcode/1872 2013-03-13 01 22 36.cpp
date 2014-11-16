******************************
    Author : townboy
    Submit time : 2013-03-13 01:22:36
    Judge Status : Accepted
    HDOJ Runid : 7750341
    Problem id : 1872
    Exe.time : 31MS
    Exe.memory : 356K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string>
#include<iostream>
#define INF 0x7fffffff

using namespace std;

int n;

struct node
{
    string name;
    int sro;
};
struct node tem,old[310],ex[310];

void mysort()
{
    int i,f;
    for(i=n-2;i>=0;i--)
    {
        for(f=0;f<=i;f++)
        {
            if(old[f].sro < old[f+1].sro)
            {
                tem=old[f];
                old[f]=old[f+1];
                old[f+1]=tem;
            }
        }
    }
}

int check()
{
    int i,last=INF;
    for(i=0;i<n;i++)
    {
        if(ex[i].sro > last)
            return 2;
        last=ex[i].sro;
    }
    for(i=0;i<n;i++)
        if(ex[i].name != old[i].name)
            return 1;
    return 0;
}

int main()
{
    string name;
    int sro,i,ans;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            cin>>name;
            scanf("%d",&sro);
            old[i].name=name;
            old[i].sro=sro;
        }
        for(i=0;i<n;i++)
        {
            cin>>name;
            scanf("%d",&sro);
            ex[i].name=name;
            ex[i].sro=sro;
        }
        mysort();
        ans=check();
        if(0 == ans)
        {
            printf("Right\n");
            continue;
        }
        else if(1 == ans)
            printf("Not Stable\n");
        else
            printf("Error\n");
        for(i=0;i<n;i++)
        {
            cout<<old[i].name;
            printf(" %d\n",old[i].sro);
        }
    }
    return 0;
}

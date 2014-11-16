******************************
    Author : townboy
    Submit time : 2013-07-01 15:26:24
    Judge Status : Accepted
    HDOJ Runid : 8513091
    Problem id : 1560
    Exe.time : 2750MS
    Exe.memory : 304K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<string.h>

using namespace std;

char dna[10][10];
int deep,exist[10],len[10];
int n;
char c[5]="AGCT";

int h(){
    int ans = 0;
    for(int i=0;i<n;i++)
        ans = max(ans , len[i]-exist[i]);
    return ans;
}

int ID(int d){
    int state = h();
    if(0 == state)
        return 1;
    if(d + h() > deep)
        return 0;
    
    int flag[10],ok;
    for(int i=0;i<4;i++){
        ok = 0;
        for(int f=0;f<n;f++)
            if(exist[f]!=len[f] && dna[f][exist[f]]==c[i]){
                exist[f]++;
                flag[f] = 1;
                ok = 1;
            }
            else
                flag[f]=0;
        if(1==ok && 1==ID(d+1))
            return 1;
        for(int f=0;f<n;f++)
            exist[f] -= flag[f];
    }
    return 0;
}

int main()
{
    int cas,i,f;
    scanf("%d",&cas);
    for(i = 0; i <cas;i ++){
        scanf("%d",&n);
        memset(exist,0,sizeof(exist));
        for(f=0;f<n;f++){
            scanf("%s",dna[f]);
            len[f] = strlen(dna[f]);
        }
        
        for(deep=0;;deep++){
            if(1 == ID(0))
                break;
        }
        cout << deep << endl;
    }
    return 0;
}
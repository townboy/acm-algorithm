******************************
    Author : townboy
    Submit time : 2013-06-29 19:34:38
    Judge Status : Accepted
    HDOJ Runid : 8508660
    Problem id : 4561
    Exe.time : 93MS
    Exe.memory : 292K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int data[11000];

int handle(int head,int tail){
    int i,ans = 0,result = 1;
    for(i=head;i<=tail;i++){
        if(data[i] < 0)
            result *= -1;
    }
    if(result > 0)
        return tail-head+1;
    for(i=head;;i++){
        if(data[i] == -2){
            ans = tail-i;
            break;
        }
    }
    for(i=tail;;i--){
        if(data[i] == -2){
            ans = max(ans,i-head);
            break;
        }
    }
    return ans;
}

int main()
{
    int last,ans,used;
    int i,cas,len,f;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d",&len);
        ans = 0;
        used = 0;
        for(f=0;f<len;f++)
            scanf("%d",data+f);
        data[len]=0;
        len++;
        last=0;
        for(f=0;f<len;f++)
            if(0 == data[f]){
                if(1 == used){
                    used = 0;
                    ans = max(ans,handle(last,f-1));
                }
                last = f+1;
            }
            else
                used=1;
        printf("Case #%d: %d\n",i+1,ans);
    }
    return 0;
}
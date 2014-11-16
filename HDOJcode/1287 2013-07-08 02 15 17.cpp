******************************
    Author : townboy
    Submit time : 2013-07-08 02:15:17
    Judge Status : Accepted
    HDOJ Runid : 8542183
    Problem id : 1287
    Exe.time : 31MS
    Exe.memory : 320K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;

int n;
int que[10000];
int main(){
    int i,f;
    while(cin >> n){
        for(i = 0 ; i < n;i++)
            cin >> que[i];
        for( i =  'Z'; i >= 'A' ;i--){
            for(f = 0 ; f < n ;f++){
                int  res = que[f]^i;
                if(res > 'Z' || res < 'A')
                    break;
            }    
            if(f == n)
                break;
        }
        for(int g = 0 ;g < n;g++){
            int tem = que[g] ^ i;
            printf("%c",tem);
        }
        cout << endl;
    }
    return 0;
}

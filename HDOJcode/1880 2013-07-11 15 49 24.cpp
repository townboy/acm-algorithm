******************************
    Author : townboy
    Submit time : 2013-07-11 15:49:24
    Judge Status : Accepted
    HDOJ Runid : 8566783
    Problem id : 1880
    Exe.time : 578MS
    Exe.memory : 21852K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>
#include<memory.h>
#include<string>
#include<string.h>
#include<algorithm>

using namespace std;

struct node{
    char a[25];
    char b[85];
};
node one[100010],two[100010];
int ji;
char ch[200];

bool cmp1(node a,node b){
    if(strcmp(a.a ,b.a) < 0)
        return true;
    return false;
}

bool cmp2(node a,node b){
    if(strcmp(a.b ,b.b) < 0)
        return true;
    return false;
}

void fun(){
    int pos ,i;
    for(int i = 0; ch[i] ;i++){
        if(ch[i] != ']')
            continue;
        pos = i;
        break;
    }
    for(i = 1 ;i < pos;i++){
        one[ji].a[i-1] = ch[i];
        two[ji].a[i-1] = ch[i];
    }
    one[ji].a[i-1] = two[ji].a[i-1] = 0;

    for(i = pos+2; ch[i] ;i++){
        one[ji].b[i-pos-2] = ch[i];
        two[ji].b[i-pos-2] = ch[i];
    }
    one[ji].b[i-pos-2] = two[ji].b[i-pos-2] = 0;
    ji ++ ;
}

void debug(){
    for(int i = 0 ;i < ji;i++){
        cout << two[i].a << "  " << two[i].b << endl;
    }
    cout << endl;
}

char ask[200];
void search(){
    int flag = 2;
    int len = strlen(ch),i;
    if('[' == ch[0]) {
        for(i = 1; i < len-1 ;i++)
            ask[i-1] = ch[i];
        ask[i-1] = 0;
        flag = 1;
    }
    else
        memcpy(ask,ch,sizeof(ch));

    if(1 == flag) {
        int l = 0,r = ji-1,mid ;
        while(l <= r){
            int mid = (l+r)/2;
            int state = strcmp(ask,one[mid].a);
            if(0 == state){
                cout << one[mid].b << endl;
                return ;
            }
            if(state < 0)
                r = mid-1;
            else 
                l = mid+1;
        }
        cout << "what?" << endl;
    }
    else {
        int l = 0,r = ji-1,mid ;
        while(l <= r){
            int mid = (l+r)/2;
            int state = strcmp(ch,two[mid].b);
            if(0 == state){
                cout << two[mid].a << endl;
                return ;
            }
            if(state < 0)
                r = mid-1;
            else 
                l = mid+1;
        }
        cout << "what?" << endl;
    }
}

int main(){
    while(gets(ch)!=NULL){
        ji = 0;
        fun();
        while(gets(ch),0 != strcmp(ch,"@END@"))
            fun();

        sort(one,one+ji,cmp1);
        sort(two,two+ji,cmp2);

        int n ;
        cin >> n;
        getchar();
        for(int i = 0 ;i < n;i ++){
            gets(ch);
            search();
        }
    }
    return 0;
}


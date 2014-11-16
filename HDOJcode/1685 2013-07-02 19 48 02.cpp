******************************
    Author : townboy
    Submit time : 2013-07-02 19:48:02
    Judge Status : Accepted
    HDOJ Runid : 8517469
    Problem id : 1685
    Exe.time : 140MS
    Exe.memory : 304K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int deep;
int book[15];
int yu[20],n;

int h(){
    int ans = n;
    for(int i = 0;i < n-1;i++)
        if(book[i+1] == book[i]+1)
            ans --;
    return yu[ans+1];
}

void handle(int sx,int sy,int ey){
    int tem[15];
    int lenx = sy-sx , leny = ey-sy+1;
    for(int i = 0; i < lenx;i++)
        tem[i] = book[i+sx];
    for(int i = 0 ;i < leny; i++)
        book[sx+i] = book[sy+i];
    for(int i = 0; i < lenx ;i++)
        book[sx+leny+i] = tem[i];
}

bool ID(int d){
    int state = h();
    if(0 == state)
        return true;
    if(state + d > deep)
        return false;
    int left[15];
    
    memcpy(left,book,sizeof(book));
    for(int i = 0 ;i < n;i++)
        for(int f = i+1 ;f < n;f++)
            for(int g = f; g < n;g++)
            {
                handle(i,f,g);
                if(true == ID(d+1))
                    return true;
                memcpy(book,left,sizeof(book));
            }
    return false;
}

int main(){
    int cas,i;
    
    for(i = 0;i < 19;i++)
        yu[i] = i/3;
    
    scanf("%d",&cas);
    for(i = 0;i < cas; i++){
        scanf("%d",&n);
        for(int f = 0;f < n;f ++)
            scanf("%d",book + f);
        for(deep = 0;deep < 5; deep++){
            if(true == ID(0))
                break;
        }
        if(5 == deep)
            cout << "5 or more";
        else
            cout << deep;
        cout << endl;
    }
    return 0;
}
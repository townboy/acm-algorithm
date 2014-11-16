******************************
    Author : townboy
    Submit time : 2013-11-17 19:25:15
    Judge Status : Accepted
    HDOJ Runid : 9608422
    Problem id : 4788
    Exe.time : 15MS
    Exe.memory : 400K
    https://github.com/townboy
******************************


#include <stdio.h>  
#include <iostream>  
#include <algorithm>  
#include <memory.h>  
#include <vector>  
#include <string>  

using namespace std;  

string yu[9];  

void init() {  
    yu[0] = "B]";  
    yu[1] = "KB]";  
    yu[2] = "MB]";  
    yu[3] = "GB]";  
    yu[4] = "TB]";  
    yu[5] = "PB]";  
    yu[6] = "EB]";  
    yu[7] = "ZB]";  
    yu[8] = "YB]";  
}  

int main() {  
    int a ,cas;  
    cin >> cas;  
    char ch[100];  
    init();  
    for(int i = 0 ;i < cas;i ++) {  
        scanf("%d[%s",&a,ch);  
        double l = 1;  
        for(int i = 0 ;i < 9;i++) {  
            if(yu[i] == ch)  
                break;  
            l *= (1000.0 / 1024);  
        }  
        printf("Case #%d: %.2lf%%\n",i + 1 , 100 - 100*l);  
    }  
    return 0;  
}  


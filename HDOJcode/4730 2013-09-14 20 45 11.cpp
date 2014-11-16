******************************
    Author : townboy
    Submit time : 2013-09-14 20:45:11
    Judge Status : Accepted
    HDOJ Runid : 9170410
    Problem id : 4730
    Exe.time : 15MS
    Exe.memory : 292K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>

using namespace std;

char ch[110];

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        scanf("%s",ch);
        printf("Case #%d: ",i+1);
        int len = strlen(ch);
        if(len > 3 && ch[len-1] == 'u' && ch[len-2] == 's' && ch[len-3] == 'e' && ch[len-4] == 'd') {
            for(int i = 0 ;i < len-4;i++)
                printf("%c",ch[i]);
        }
        else
            printf("%s",ch);
        cout << "nanodesu" << endl;
    }
    return 0;
}

******************************
    Author : townboy
    Submit time : 2013-07-06 01:13:35
    Judge Status : Accepted
    HDOJ Runid : 8531937
    Problem id : 2809
    Exe.time : 1296MS
    Exe.memory : 8740K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int Exp[1100000];
int state[1100000];

int ati,def,hp,Iati,Idef,Ihp;
int n , alllive;

int enemy[25][4];
char name[25];


void fight(int S,int aim,int toS){
    int exp = Exp[S];
    int add = exp/100;
    exp %= 100;
    int nati = ati + add*Iati;
    int ndef = def + add*Idef;
    int Elose = max( 1 , nati - enemy[aim][1] );
    int time = (enemy[aim][2] + Elose -1) / Elose;
    time --;
    int Olose = max(1 , enemy[aim][0]-ndef);
    int Ownleft = state[S] - time*Olose;
    if(Ownleft <= 0)
        return ;
    exp += enemy[aim][3];

    if(exp >= 100)
        Ownleft += Ihp;
    state[toS] = max(state[toS] , Ownleft);
}

int fun(int S){
    if(0 != state[S])
        return state[S];
    int tem = 1; 
    state[S] = -1;
    for(int i = 0 ; i < n;i++){
        if(0 != (tem & S)){
            tem <<= 1;
            continue;
        }
        int nS = S|tem ;
        int nSxue = fun(nS);
        tem <<= 1 ;
        if(-1 == nSxue)
            continue;
        fight(nS,i,S);
    }
    int exp = 0;
    tem = 1;
    for(int i = 0 ; i < n ;i ++){
        if(0 == (tem&S))
            exp += enemy[i][3];
        tem <<= 1;
    }
    Exp[S] = exp;
    return state[S];
}

int main(){
    while(scanf("%d",&ati) != EOF){
        scanf("%d %d %d %d %d",&def,&hp,&Iati,&Idef,&Ihp);
        scanf("%d",&n);
        alllive = (1<<n)-1;
        memset(state,0,sizeof(state));
        state[alllive] = hp;
        Exp[alllive] = 0;
        
        for(int i = 0 ; i < n;i ++ ){
            cin >> name;
            for(int f = 0 ; f < 4 ;f++)
                cin >> enemy[i][f];
        }
        
        int result = fun(0);
        if(-1 == result)
            cout << "Poor LvBu,his period was gone." << endl;
        else 
            cout << result << endl;
     }
    return 0;
}
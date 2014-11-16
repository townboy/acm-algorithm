******************************
    Author : townboy
    Submit time : 2013-07-08 18:35:01
    Judge Status : Accepted
    HDOJ Runid : 8547344
    Problem id : 3729
    Exe.time : 156MS
    Exe.memory : 748K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;

struct node {
    int st;
    int ed;
    int id;
    friend bool operator < (node a, node b){
        if(a.ed == b.ed)
            return a.st < b.st;
        return a.ed < b.ed;
    }
};
node stu[70];

int n;
int exist[70];

void init(){
    memset(exist,0,sizeof(exist));
    sort(stu,stu+n);
}

int ocp[110000];
int fun(){
    int i,f;
    int ans = 0 ;
    memset(ocp,0,sizeof(ocp));
    for(i = 0 ; i < n ;i ++){
        if(1 == exist[i])
            continue;
        for(f = stu[i].st ; f <= stu[i].ed;f ++)
            if(0 == ocp[f]){
                ocp[f] = 1;
                ans ++ ;
                break;
            }
    }
    return ans ;
}

void debug(){
    for(int i = 0 ; i < n;i++)
        cout << stu[i].st << " " << stu[i].ed << endl;
}

int num ;
int ans[70];


void Ans(){
    num = 0;
    for(int i = 0; i < n; i ++)
        if(0 == exist[i]){
            ans[num] = stu[i].id+1;
            num++;
        }
    sort(ans,ans+num);
    cout << ans[0];
    for(int i = 1 ;i < num;i++)
        cout << " " << ans[i];
    cout << endl;
}

int xuan(int aim){
    for(int i = 0 ;i < n; i++)
        if(stu[i].id == aim)
            return i;
}

int main(){
    int cas;
    scanf("%d",&cas);
    for(int i = 0 ; i < cas; i++){
        scanf("%d",&n);

        for(int f = 0; f < n ;f++){
            cin >> stu[f].st >> stu[f].ed;
            stu[f].id = f;
        }
        init();
        int ans = fun();
        int sum = 0;
        for(int f = 0 ; f < n; f++){
            int pos = xuan(f);
            exist[pos] = 1;
            int tem = fun();
            if(tem != ans)
                exist[pos] = 0;
            else
                sum ++;
            if(sum == n-ans)
                break;
        }
        cout << ans << endl;
        Ans();
    }
    return 0;
}
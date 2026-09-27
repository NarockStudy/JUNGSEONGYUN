// N=0, S=1
// 시계=1, 반시계=-1
// 12시 방향부터 0~7
// 각 의자의 인접부: 1=2 // 2=2&6 // 3=2&6 // 4=6 

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int chair[4][8];
int head[4];        //각 의자의 12시 방향을 헤드로 관리
bool vis[4];

void sim(int n, int d){
    if(vis[n]) return;
    vis[n]=true;

    //현재 의자의 인접부 계산
    int cur_l=(head[n]-2+8)%8;
    int cur_r=(head[n]+2+8)%8;

    //인접 의자 계산
    if(n==0){
        int r_l=(head[n+1]-2+8)%8;
        if(chair[n][cur_r]!=chair[n+1][r_l]){
            sim(n+1, d*-1);
        }
    }
    else if(n==3){
        int l_r=(head[n-1]+2+8)%8;
        if(chair[n][cur_l]!=chair[n-1][l_r]){
            sim(n-1,d*-1);
        }
    }
    else{
        int r_l=(head[n+1]-2+8)%8;
        int l_r=(head[n-1]+2+8)%8;
        if(chair[n][cur_r]!=chair[n+1][r_l]){
            sim(n+1, d*-1);
        }
        if(chair[n][cur_l]!=chair[n-1][l_r]){
            sim(n-1,d*-1);
        }
    }

    //현재 의자 회전
    head[n]=(head[n]+d*-1+8)%8;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k=0;

    //입력
    for(int i=0;i<4;i++){
        string s;
        cin >> s;
        for(int j=0;j<8;j++){
            chair[i][j]=s[j]-'0';
        }
    }

    cin >> k;

    for(int i=0;i<k;i++){
        int n,d;
        cin >> n >> d;
        fill(vis,vis+4,false);
        sim(n-1,d);   //시뮬레이션
    }

    //출력계산
    int ans=0;
    for(int i=0;i<4;i++){
        ans+=(1<<i)*chair[i][head[i]];
    }

    //츨력
    cout << ans;

    return 0;
}
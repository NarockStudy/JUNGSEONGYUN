#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int r,c,k;
int A[102][102];
int R=3, C=3;

void trans(){
    int T[102][102];
    memset(T,0,sizeof(T));
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            T[j][i]=A[i][j];
        }
    }
    memset(A,0,sizeof(A));
    for(int i=1;i<=C;i++){
        for(int j=1;j<=R;j++){
            A[i][j]=T[i][j];
        }
    }
    swap(R,C);
}

void func_R(){
    int nc=0;
    for(int i=1;i<=R;i++){
        int cnt[102]{0,};
        for(int j=1;j<=C;j++){
            if(A[i][j]==0) continue;
            cnt[A[i][j]]++;
        }
        vector<pair<int,int>> v;
        for(int num=1;num<=100;num++){
            if(cnt[num]) v.push_back({cnt[num],num});  //{횟수,숫자}
        }
        sort(v.begin(),v.end());

        for(int j=1;j<=100;j++) A[i][j]=0;

        int idx=1;
        for(auto &p:v){
            if(idx>100) break;
            A[i][idx++]=p.second;      //숫자먼저
            if(idx>100) break;
            A[i][idx++]=p.first;
        }
        nc=max(nc,idx-1);
    }
    C=min(100,nc);
}

void func_C(){ //뒤집고-R연산-뒤집고
    trans();
    func_R();
    trans();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> k;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            cin >> A[i][j];
    
    for(int t=0;t<=100;t++){
        if(A[r][c]==k){
            cout << t << '\n';
            return 0;
        }
        if(R>=C) func_R();
        else func_C();
    }
    cout << -1 << '\n';

    return 0;
}
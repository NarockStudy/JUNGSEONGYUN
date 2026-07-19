#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int H, K, R;
vector<vector<int>> tasks;
const int mxN=1<<11;
queue<int> q[2][mxN];   ///업무 큐, 0:왼 1:오
int nxt[mxN];   //다음 업무
int ans;

//하루 시뮬레이션
void func(int d){
    int tot=(1<<(H+1))-1;
    for(int i=1;i<=tot;i++){
        if(1<<H<=i){   //노드가 말단일 때
            if(nxt[i]<K){
                int tsk=tasks[i-(1<<H)][nxt[i]++];
                q[i&1][i/2].push(tsk);
            }
        }
        else{
            int dd=!(d&1);
            if(q[dd][i].empty()) continue;  //업무 empty면 패스
            int tsk=q[dd][i].front();
            q[dd][i].pop();
            if(i==1) ans+=tsk;  //완료
            else{
                q[i&1][i/2].push(tsk);
            }
        }
    }
}

int main() {
    cin >> H >> K >> R;

    tasks.resize(1 << H, vector<int>(K));
    for (int i = 0; i < (1 << H); i++) {
        for (int j = 0; j < K; j++) {
            cin >> tasks[i][j];
        }
    }

    //R일까지 시뮬레이션
    for(int i=1;i<=R;i++){
        func(i);
    }
    
    cout << ans;

    return 0;
}

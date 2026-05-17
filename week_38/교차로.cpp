#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<long long> t;
vector<char> w;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    t.resize(N);
    w.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> t[i] >> w[i];
    }

    queue<int> q[4];    //0~3:A~D
    int idx=0;
    long long tm=0;
    while(1){
        //종료 조건
        bool nul=true;
        for(int i=0;i<4;i++){
            if(!q[i].empty()) nul=false;
        }
        if(nul && idx>=N) break;

        //시간 건너뛰기
        if(nul){
            tm=t[idx];
        }
        
        //현시각 차량 진입
        while(idx<N && tm==t[idx]){
            q[w[idx]-'A'].push(idx);
            idx++;
        }

        //교차로 처리
        int chk=0;
        for(int i=0;i<4;i++){
            int r=(i-1+4)%4;
            if(q[r].empty() && !q[i].empty())
                chk|=(1<<i);
        }
        if(!chk){
            for(int i=0;i<4;i++){
                while(!q[i].empty()){
                    t[q[i].front()]=-1;
                    q[i].pop();
                }
            }
            for(int i=idx;i<N;i++){
                t[i]=-1;
            }
            break;
        }
        for(int i=0;i<4;i++){
            if(chk&(1<<i)){
                t[q[i].front()]=tm;
                q[i].pop();
            }
        }

        tm++;
    }

    //출력
    for(int i=0;i<N;i++){
        cout << t[i] << '\n';
    }

    return 0;
}

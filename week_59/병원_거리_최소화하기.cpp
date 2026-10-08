#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int board[52][52];
vector<int> people;     //사람 위치
vector<int> hos;        //병원 위치
vector<int> sel_idx;    //고른 병원
int ans=1e9;

//백트래킹으로 최솟값 찾기
void sim(int start){
    int sz=(int)sel_idx.size();
    //병원 m개 고르면 거리 계산 후 갱신
    if(sz==m){
        int sum_all=0;
        for(auto p:people){
            int p_r=p/100;
            int p_c=p%100;
            int sum_per=1e9;
            for(auto s :sel_idx){
                int h_r=hos[s]/100;
                int h_c=hos[s]%100;
                int dist=abs(p_r-h_r)+abs(p_c-h_c);
                sum_per=min(sum_per,dist);
            }
            sum_all+=sum_per;
            //합한 값이 기존 ans보다 크면 종료
            if(sum_all>=ans) return;
        }
        ans=min(ans,sum_all);
        return;
    }

    //백트래킹
    int sz_h=(int)hos.size();
    for(int i=start;i<sz_h;i++){
        sel_idx.push_back(i);
        sim(i+1);
        sel_idx.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //입력
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tmp;
            cin >> tmp;
            board[i][j] = tmp;
            if(tmp==1)  people.push_back(i*100+j);
            else if(tmp==2) hos.push_back(i*100+j);
        }
    }

    //시뮬레이션
    sim(0);

    cout << ans;

    return 0;
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int board[52][52];
int ans=40000;
vector<pair<int,int>> h, c_in, c_sel;

//거리계산 
int cal_dist(int r1, int c1, int r2, int c2){
    int dist=abs(r1-r2)+abs(c1-c2);
    return dist;
}

//최솟값 찾기
int cal(){
    int sum=0, anss=0;
    for(int i=0;i<h.size();i++){
        int minn=3000;
        for(int j=0;j<M;j++){
            auto [r1, c1]=h[i];
            auto [r2, c2]=c_sel[j];
            minn=min(minn, cal_dist(r1,c1,r2,c2));
        }
        sum+=minn;
    }
    return sum;
}

//백트래킹
void func(int k, int start){
    if(k==M){
        ans=min(ans, cal());
        return;
    }

    for(int i=start;i<c_in.size();i++){
        auto [r,c]=c_in[i];
        c_sel.push_back({r,c});
        func(k+1, i+1);
        c_sel.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> board[i][j];
            if(board[i][j]==1) h.push_back({i,j});
            if(board[i][j]==2) c_in.push_back({i,j});
        }
    }
    func(0,0);
    cout << ans << '\n';

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, ans=0;
vector<vector<int>> board;
vector<pair<int,int>> z, v; // z: 빈칸 좌표, v: 바이러스 좌표
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

// 바이러스 확산 시뮬레이션 후 안전 영역 개수 반환
int bfs(){
    queue<pair<int, int>> q;
    auto tmp=board;
    for(auto [x, y]: v) q.push({x,y});
    
    // 바이러스 확산
    while(!q.empty()){
        auto [x,y] =q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx =x+dx[dir];
            int ny =y+dy[dir];
            if(nx<0||ny<0||nx>=N||ny>=M) continue;
            if(tmp[nx][ny]) continue;
            tmp[nx][ny]=2;
            q.push({nx,ny});
        }
    }
    
    // 안전 영역(0) 개수 세기
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(tmp[i][j]==0) cnt++;
        }
    }
    return cnt;
}

// 조합으로 벽 3개 세우기
void func(int d, int start){
    if(d==3){
        ans =max(ans, bfs());
        return;
    }
    for(int i=start;i<z.size();i++){
        auto [x, y]=z[i];  
        board[x][y] =1; // 벽 세우기
        func(d+1, i+1);
        board[x][y] =0; // 벽 제거 (백트래킹)
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    board.assign(N,vector<int>(M,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> board[i][j];
            if(board[i][j]==2) v.push_back({i,j});
            if(board[i][j]==0) z.push_back({i,j});
        }
    }
    func(0,0);
    cout << ans;
    
    return 0;
}
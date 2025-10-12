#include <iostream>
#include <vector>
using namespace std;

int N, M, ans=0;
vector<vector<int>> board;
int dx[4]={-1,0,1,0};   // 북, 동, 남, 서
int dy[4]={0,1,0,-1};

void func(int r, int c, int d){
    // 현재 칸 청소
    if(board[r][c]==0){
        board[r][c] =2;
        ans++;
    }
    
    // 4방향 탐색
    for(int i=0;i<4;i++){
        d=(d+3)%4;  // 반시계 회전
        int nx=r+dx[d];
        int ny=c+dy[d];
        
        if(nx<0||ny<0||nx>=N||ny>=M) continue;
        if(board[nx][ny]!=0) continue;
        
        // 청소할 곳 발견 -> 전진
        func(nx,ny,d);
        return;
    }

    // 네 방향 모두 청소됨 -> 후진
    int d2=(d+2)%4;
    int nx=r+dx[d2];
    int ny=c+dy[d2];
    
    if(nx<0||ny<0||nx>=N||ny>=M) return;
    if(board[nx][ny]!=1)
        func(nx,ny,d);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    int r, c, d;
    cin >> r >> c >> d;
    
    board.assign(N, vector<int>(M,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> board[i][j];
        }
    }
    
    func(r,c,d);
    cout << ans << '\n';

    return 0;
}
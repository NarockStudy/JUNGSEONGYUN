#include <iostream>
#include <vector>
#include <deque>
using namespace  std;

int N, K, L;
vector<vector<int>> board;
vector<pair<int,char>> dir;
deque<pair<int,int>> dq;
int dx[4]={0,1,0,-1}; // 동, 남, 서, 북
int dy[4]={1,0,-1,0};
int ans;

void func(){
    int cdir =0, turn =0;
    int r =0, c =0;
    dq.push_back({r,c});
    board[r][c] =2;
    
    while(1){
        ans++; // 1초 경과
        int nx=r+dx[cdir], ny=c+dy[cdir];

        // 벽 또는 몸과 충돌 시 종료
        if(nx<0||ny<0||nx>=N||ny>=N||board[nx][ny]==2) return;
        
        // 사과가 있으면 꼬리 유지
        if(board[nx][ny]==1){
            board[nx][ny]=2;
            dq.push_back({nx,ny});
        }
        // 사과가 없으면 꼬리 제거
        else{
            board[nx][ny]=2;
            dq.push_back({nx,ny});
            auto [x,y] =dq.front(); dq.pop_front();
            board[x][y] =0;
        }
        r=nx, c=ny;
        
        // 방향 전환 명령 수행
        if(turn<L && dir[turn].first==ans){
            char c=dir[turn].second;
            if(c=='L') cdir=(cdir+3)%4; // 왼쪽 회전
            else cdir=(cdir+1)%4;       // 오른쪽 회전
            turn++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    board.assign(N, vector<int>(N,0));
    for(int i=0;i<K;i++){
        int r, c;
        cin >> r >> c;
        board[r-1][c-1] =1;
    }
    cin >> L;
    dir.assign(L,{});
    for(int i=0;i<L;i++){
        int X;
        char C;
        cin >> X >> C;
        dir[i] ={X,C};
    }
    func();
    cout << ans << '\n';

    return 0;
}
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N, M, K;
int board[1000][1000];
int dist[1000][1000][11][2]; // [N][M][K+1][day/night]
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

struct State {
    int x, y, break_cnt, is_day;
};

void bfs() {
    queue<State> q;
    q.push({0, 0, 0, 1});
    dist[0][0][0][1] = 1;
    while (!q.empty()) {
        auto [cx, cy, cbreak, cday] = q.front(); q.pop();
        for (int d=0; d<4; d++) {
            int nx = cx + dx[d], ny = cy + dy[d];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            // 빈 칸 이동
            if (board[nx][ny] == 0 && dist[nx][ny][cbreak][1-cday] == 0) {
                dist[nx][ny][cbreak][1-cday] = dist[cx][cy][cbreak][cday] + 1;
                q.push({nx, ny, cbreak, 1-cday});
            }
            // 벽 & 낮 & 부술 수 있음
            else if (board[nx][ny] == 1 && cbreak < K && cday == 1 && dist[nx][ny][cbreak+1][1-cday] == 0) {
                dist[nx][ny][cbreak+1][1-cday] = dist[cx][cy][cbreak][cday] + 1;
                q.push({nx, ny, cbreak+1, 1-cday});
            }
        }
        // 밤에 벽 앞에서 멈춰서 기다리기
        if (cday == 0 && dist[cx][cy][cbreak][1-cday] == 0) {
            dist[cx][cy][cbreak][1-cday] = dist[cx][cy][cbreak][cday] + 1;
            q.push({cx, cy, cbreak, 1-cday});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            board[i][j] = s[j] - '0';
        }
    }
    dist[0][0][0][1] = 1;
    bfs();
    int ans = -1;
    for (int k = 0; k <= K; k++) {
        for (int day = 0; day <= 1; day++) {
            int val = dist[N-1][M-1][k][day];
            if (val != 0 && (ans == -1 || val < ans))
                ans = val;
        }
    }
    cout << ans << '\n';
    return 0;
}

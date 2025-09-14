#include <iostream>
#include <vector>
using namespace std;

int N;
int board[10][10];
bool diag1[20]; // 왼쪽 아래 -> 오른쪽 위 대각선 방문 체크
bool diag2[20]; // 왼쪽 위 -> 오른쪽 아래 대각선 방문 체크

vector<pair<int,int>> black, white; // 흑칠, 백칠 칸 좌표 분리
int maxBlack = 0, maxWhite = 0;

void dfs(const vector<pair<int,int>>& positions, int idx, int count, int& maxCount) {
    if (idx == positions.size()) {
        if (count > maxCount) maxCount = count;
        return;
    }

    auto [x, y] = positions[idx];
    int d1 = x + y;
    int d2 = x - y + N - 1;

    // 비숍을 이 위치에 놓을 수 있으면
    if (!diag1[d1] && !diag2[d2]) {
        diag1[d1] = true;
        diag2[d2] = true;
        dfs(positions, idx + 1, count + 1, maxCount);
        diag1[d1] = false;
        diag2[d2] = false;
    }

    // 이 위치에 놓지 않는 경우도 탐색
    dfs(positions, idx + 1, count, maxCount);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
            if(board[i][j] == 1){
                if((i+j) % 2 == 0) black.emplace_back(i,j);
                else white.emplace_back(i,j);
            }
        }
    }

    dfs(black, 0, 0, maxBlack);
    dfs(white, 0, 0, maxWhite);

    cout << maxBlack + maxWhite << '\n';
    return 0;
}

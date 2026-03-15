#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int board[502][502];
bool vis[502][502];
int ans = 0;
int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};

void dfs(int k, int r, int c, int sum)
{
    if (k == 4)
    {
        ans = max(ans, sum);
        return;
    }

    for (int dir = 0; dir < 4; dir++)
    {
        int nr = r + dx[dir];
        int nc = c + dy[dir];
        if (nr < 0 || nr >= N || nc < 0 || nc >= M || vis[nr][nc])
            continue;
        vis[nr][nc] = true;
        dfs(k + 1, nr, nc, sum + board[nr][nc]);
        vis[nr][nc] = false;
    }
}

// t모양은 dfs로 안되서 따로
void tt(int r, int c)
{
    vector<int> v;
    for (int dir = 0; dir < 4; dir++)
    {
        int nr = r + dx[dir];
        int nc = c + dy[dir];
        if (nr < 0 || nr >= N || nc < 0 || nc >= M)
            continue;
        v.push_back(board[nr][nc]);
    }
    if (v.size() < 3)
        return;
    sort(v.rbegin(), v.rend());
    int sum = board[r][c];
    for (int i = 0; i < 3; i++)
        sum += v[i];
    ans = max(ans, sum);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            vis[i][j] = true;
            dfs(1, i, j, board[i][j]);
            vis[i][j] = false;
            tt(i, j);
        }
    }
    cout << ans << '\n';

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int board[52][52];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int R, C, T;
vector<pair<int, int>> ap;

void dust()
{
    int tmp[52][52] = {0};
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (board[i][j] >= 5)
            {
                int a = board[i][j] / 5;
                int cnt = 0;
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                        continue;
                    if (ap[0] == pair{nx, ny} || ap[1] == pair{nx, ny})
                        continue;
                    tmp[nx][ny] += a;
                    cnt++;
                }
                board[i][j] -= a * cnt;
            }
        }
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            board[i][j] += tmp[i][j];
        }
    }
    return;
}

void cln()
{
    auto [a1, b1] = ap[0];
    auto [a2, b2] = ap[1];

    pair<int, int> cur = {a1 - 1, b1};
    int dir = 3;
    while (1)
    {
        if (cur == ap[0])
            break;
        if (cur == pair{a1, C - 1})
            dir = 2;
        if (cur == pair{0, C - 1})
            dir = 1;
        if (cur == pair(0, 0))
            dir = 0;
        auto [a, b] = cur;
        int na = a + dx[dir];
        int nb = b + dy[dir];
        board[a][b] = board[na][nb];
        cur = {na, nb};
    }

    cur = {a2 + 1, b2};
    dir = 1;
    while (1)
    {
        if (cur == ap[1])
            break;
        if (cur == pair{a2, C - 1})
            dir = 2;
        if (cur == pair{R - 1, C - 1})
            dir = 3;
        if (cur == pair(R - 1, 0))
            dir = 0;
        auto [a, b] = cur;
        int na = a + dx[dir];
        int nb = b + dy[dir];
        board[a][b] = board[na][nb];
        cur = {na, nb};
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C >> T;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == -1)
            {
                ap.push_back({i, j});
                board[i][j] = 0;
            }
        }
    }
    while (T--)
    {
        dust();
        cln();
    }
    int ans = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            ans += board[i][j];
        }
    }
    cout << ans << '\n';

    return 0;
}

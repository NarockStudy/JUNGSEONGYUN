#include <iostream>
#include <vector>
using namespace std;

int R, C, M;
int board[102][102];
int dr[5]{0, -1, 1, 0, 0}; // 1~4 위,아래,오,왼
int dc[5]{0, 0, 0, 1, -1};

struct Shark
{
    int r, c, s, d, z, idx;
    bool dead = false;
};

vector<Shark> vSharks;

void mov(Shark &sh)
{
    if (board[sh.r][sh.c] == sh.idx)
        board[sh.r][sh.c] = 0;

    int ns = sh.s;
    // 속도 최적화
    if (sh.d == 1 || sh.d == 2)
    {
        ns = R > 1 ? sh.s % (2 * (R - 1)) : 0;
    }
    else
    {
        ns = C > 1 ? sh.s % (2 * (C - 1)) : 0;
    }

    for (int i = 0; i < ns; i++)
    {
        if (sh.d == 1 && sh.r == 1)
            sh.d = 2;
        if (sh.d == 2 && sh.r == R)
            sh.d = 1;
        if (sh.d == 3 && sh.c == C)
            sh.d = 4;
        if (sh.d == 4 && sh.c == 1)
            sh.d = 3;
        sh.r += dr[sh.d];
        sh.c += dc[sh.d];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vSharks.push_back({0, 0, 0, 0, 0, 0, true}); // idx 0 채우기
    cin >> R >> C >> M;
    for (int idx = 1; idx <= M; idx++)
    {
        Shark sh;
        cin >> sh.r >> sh.c >> sh.s >> sh.d >> sh.z;
        sh.idx = idx;
        vSharks.push_back(sh);
        board[sh.r][sh.c] = idx;
    }

    int ans = 0;

    for (int j = 1; j <= C; j++)
    {
        // 낚시왕 이동 및 상어 잡기
        for (int i = 1; i <= R; i++)
        {
            if (board[i][j] != 0)
            {
                Shark sh = vSharks[board[i][j]];
                ans += vSharks[sh.idx].z;
                vSharks[sh.idx].dead = true;
                board[i][j] = 0;
                break;
            }
        }

        // 상어 이동
        for (auto &sh : vSharks)
        {
            if (!sh.dead)
                mov(sh);
        }

        // 상어 중복 제거
        for (auto &sh : vSharks)
        {
            if (!sh.dead)
            {
                int cur = board[sh.r][sh.c];
                if (cur != 0)
                {
                    if (vSharks[cur].z > sh.z)
                    {
                        sh.dead = true;
                        continue;
                    }
                    else
                    {
                        vSharks[cur].dead = true;
                    }
                }
                board[sh.r][sh.c] = sh.idx;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N;
vector<int> vi;
vector<char> vc;
int ans = INT_MIN;

int alu(char c, int a, int b)
{
    if (c == '+')
        return a + b;
    if (c == '-')
        return a - b;
    if (c == '*')
        return a * b;
    return 0;
}

void dfs(int idx, int num)
{
    if (idx == (vi.size() - 1))
    {
        ans = max(ans, num);
        return;
    }

    // 괄호x
    dfs(idx + 1, alu(vc[idx], num, vi[idx + 1]));

    // 괄호ㅇ
    if (idx + 2 <= (vi.size() - 1))
    {
        int cal = alu(vc[idx + 1], vi[idx + 1], vi[idx + 2]);
        dfs(idx + 2, alu(vc[idx], num, cal));
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    vi.assign(N / 2 + 1, 0);
    vc.assign(N / 2, ' ');
    for (int i = 0; i < N / 2; i++)
    {
        cin >> vi[i] >> vc[i];
    }
    cin >> vi[N / 2];

    dfs(0, vi[0]);

    cout << ans << '\n';

    return 0;
}
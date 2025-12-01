#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w, L;
    cin >> n >> w >> L;
    queue<int> q1, q2;  //q1은 대기, q2가 다리 
    int ans = 0, q2w = 0, q2L=0;    //w가 다리길이, L이 하중
    //q1대기열 채우기
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        q1.push(a);
    }
    //q2 다리 0으로 채우기
    for (int i = 0; i < w; i++) {
        q2.push(0);
    }
    //q1, q2 둘 다 트럭이 없을때까지
    while (!q1.empty() || q2w) {
        //q2쪽 다리 먼저 처리
        ans++;
        q2L -= q2.front();
        if (q2.front()) q2w--;
        q2.pop();
        //상황에 따라 q1쪽 대기열 처리
        if (!q1.empty()) {
            if (q2L + q1.front() > L) {
                q2.push(0);
                continue;
            }
            q2.push(q1.front());
            q2w++;
            q2L += q1.front();
            q1.pop();
        }
    }
    cout << ans << '\n';

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int a, b;
        cin >> a >> b;
        vector<int> A(a), B(b);
        for (int i = 0; i < a; i++)
            cin >> A[i];
        for (int i = 0; i < b; i++)
            cin >> B[i];
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int cnt = 0, b_idx = 0;
        for (int i = 0; i < a; i++) {
            if (b_idx == b) {
                cnt += b_idx * (a - i);
                break;
            }
            for (int j = b_idx; j < b; j++) {
                if (A[i] <= B[j]) {
                    b_idx = j;
                    cnt += b_idx;
                    break;
                }
                if (j == (b - 1)) {
                    b_idx = b;
                    cnt += b_idx;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
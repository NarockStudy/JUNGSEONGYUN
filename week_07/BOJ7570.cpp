#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//dp...?
//전체 길이 - 가장 긴 증가구간
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int dp[1000001]{0,};
    int maxx =0;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        dp[a] =dp[a-1]+1;
        maxx =max(maxx,dp[a]);
    }
    cout << N-maxx << '\n';    

    return 0;
}
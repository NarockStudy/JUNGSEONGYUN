#include <iostream>
using namespace std;

int t[16];
int p[16];
int dp[25];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> t[i] >> p[i];
    }

    for(int i=n-1;i>=0;i--){
        if(i+t[i]<=n){
            dp[i]=max(dp[i+t[i]]+p[i], dp[i+1]);
        }
        else{
            dp[i]=dp[i+1];
        }
    }
    cout << dp[0];

    return 0;
}
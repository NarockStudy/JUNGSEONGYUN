#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> vin(N), dp(N,1);
    vector<int> prevv(N, -1); // 직전 인덱스 저장용 
    for(int i=0;i<N;i++)
        cin >> vin[i];

    int lastt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            if(vin[j]<vin[i] && dp[j]+1 > dp[i]){
                dp[i] = dp[j]+1;
                prevv[i] =j;
            }
        }
        if(dp[i]>dp[lastt]) lastt =i;
    }

    cout << dp[lastt] << '\n';

    vector<int> ans;
    for(int i=lastt; i!=-1; i =prevv[i])
        ans.push_back(vin[i]);
    for(int i=ans.size()-1;i>=0;i--)
        cout << ans[i] << ' ';
    
    return 0;
}
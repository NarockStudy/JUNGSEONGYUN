#include <iostream>
#include <vector>
using namespace std;

int n;
int ans=1e9;

int board[22][22];
vector<int> va;
bool chk[22];

void dfs(int k, int idx){
    if(k==n/2){
        vector<int> vp;
        for(int i=0;i<n;i++){
            if(chk[i]) continue;
            vp.push_back(i);
        }

        int am=0, pm=0;
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                am+=board[va[i]][va[j]];
                pm+=board[vp[i]][vp[j]];
            }
        }
        ans=min(ans,abs(am-pm));
        return;
    }

    for(int i=idx;i<n;i++){
        if(chk[i]) continue;
        chk[i]=true;
        va.push_back(i);
        dfs(k+1, i+1);
        va.pop_back();
        chk[i]=false;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> board[i][j];

    dfs(0,0);

    cout << ans;

    return 0;
}
#include <iostream>
using namespace std;

const int MAX=20;

int N;
int board[MAX][MAX];
int dp[3][MAX][MAX];

int ans;

//mod={0,1,2} == {ㅡ,|,\}
void dfs(int mod, int r, int c){
    if(r==N && c==N){
        ans++;
        return;
    }

    if(mod==0){
        if(c+1<=N && !board[r][c+1]){
            dfs(0,r,c+1);
            if(r+1<=N && !board[r+1][c+1] && !board[r+1][c]){
                dfs(2,r+1,c+1);
            }
        }
    }
    else if(mod==1){
        if(r+1<=N && !board[r+1][c]){
            dfs(1,r+1,c);
            if(c+1<=N && !board[r+1][c+1] && !board[r][c+1]){
                dfs(2,r+1,c+1);
            }
        }
    }
    else{
        if(c+1<=N && !board[r][c+1]){
            dfs(0,r,c+1);
        }
        if(r+1<=N && !board[r+1][c]){
            dfs(1,r+1,c);
            if(c+1<=N && !board[r+1][c+1] && !board[r][c+1]){
                dfs(2,r+1,c+1);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> board[i][j];
        }
    }

    // dfs(0,1,2);
    // cout << ans;

    //dp
    dp[0][1][2]=1;
    for(int i=1;i<=N;i++){
        for(int j=3;j<=N;j++){
            if(board[i][j]) continue;
            dp[0][i][j]=dp[0][i][j-1]+dp[2][i][j-1];
            dp[1][i][j]=dp[1][i-1][j]+dp[2][i-1][j];
            if(board[i-1][j] || board[i][j-1]) continue;
            dp[2][i][j]=dp[0][i-1][j-1]+dp[1][i-1][j-1]+dp[2][i-1][j-1];
        }
    }
    cout << dp[0][N][N]+dp[1][N][N]+dp[2][N][N];

    return 0;
}
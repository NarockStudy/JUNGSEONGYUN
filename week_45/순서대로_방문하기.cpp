#include <iostream>
using namespace std;

int board[6][6];
bool vis[6][6];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int m1[20];
int m2[20];
int n,m;
int ans=0;

void dfs(int k, int x, int y){
    if(k==m){
        ans++;
        return;
    }

    for(int d=0;d<4;d++){
        int nx=x+dx[d];
        int ny=y+dy[d];
        if(nx<1 || nx>n || ny<1 || ny>n) continue;
        if(board[nx][ny]==1 || vis[nx][ny]) continue;

        vis[nx][ny]=true;
        //다음 방문지점이 m이라면 k+1
        if(nx==m1[k] && ny==m2[k]){
            dfs(k+1,nx,ny);
        }
        else{
            dfs(k,nx,ny);
        }
        //백트래킹
        vis[nx][ny]=false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> board[i][j];
        }
    }
    for(int i=0;i<m;i++){
        cin >> m1[i] >> m2[i];
    }

    //첫 시작점부터 방문 시작
    vis[m1[0]][m2[0]]=true;
    dfs(1, m1[0], m2[0]);

    cout << ans;

    return 0;
}
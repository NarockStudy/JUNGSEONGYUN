#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N,M;
int board[52][52];
int dx[4]{0,1,0,-1};
int dy[4]{1,0,-1,0};
int ans=2500;
vector<pair<int ,int>> v, vsel;

int bfs(){
    int tmp[52][52];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            tmp[i][j]=board[i][j];
            if(board[i][j]==1) tmp[i][j]=-1;    //tmp에선 벽만 -1값으로
            else               tmp[i][j]=-2;    //빈칸, 바이러스는 -2값으로
        }
    }

    queue<pair<int,int>> q;
    for(auto p:vsel){
        q.push(p);
        tmp[p.first][p.second]=0;   //바이러스 시작점만 0으로
    }
    while(!q.empty()){
        auto [x, y]=q.front();
        q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            if(nx<0||nx>=N||ny<0||ny>=N) continue;
            if(tmp[nx][ny]==-2){
                tmp[nx][ny]=tmp[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    int cnt=-1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(tmp[i][j]==-2 && board[i][j]!=1){    //안퍼졌는데(tmp) 빈칸(board)인 곳 
                return 2500;
            }
            cnt=max(cnt,tmp[i][j]);
        }
    }

    return cnt;
}

void dfs(int k, int idx){
    if(k==M){
        ans=min(ans, bfs());
        return;
    }
    for(int i=idx;i<v.size();i++){
        vsel.push_back(v[i]);
        dfs(k+1,i+1);
        vsel.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> board[i][j];
            if(board[i][j]==2) v.push_back({i,j});
        }
    }

    dfs(0,0);
    if(ans==2500) ans=-1;
    
    cout << ans << '\n';

    return 0;
}
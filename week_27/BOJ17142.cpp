#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
int board[52][52];
vector<pair<int,int>> v,vsel;
int ans=3000;
int dx[4]{0,1,0,-1};
int dy[4]{1,0,-1,0};

int bfs(){
    int tmp[52][52]={0,};
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int a=board[i][j];
            if(a==0) a=-3;
            else if(a==1) a=-1;
            else if(a==2) a=-2;
            tmp[i][j]=a;
        }
    }

    queue<pair<int,int>> q;
    for(auto p:vsel){
        q.push(p);
        tmp[p.first][p.second]=0;
    }

    while(!q.empty()){
        auto[x,y]=q.front();
        q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            if(nx<0||nx>=N||ny<0||ny>=N) continue;
            if(tmp[nx][ny]>=-1) continue;
            else tmp[nx][ny]=tmp[x][y]+1;
            // if(tmp[nx][ny]==-2 || tmp[nx][ny]==-3) tmp[nx][ny]=tmp[x][y]+1;
            q.push({nx,ny});
        }
    }
    int cnt=0;
    bool flag=0;
    for(int i=0;i<N;i++){
        if(flag) break;
        for(int j=0;j<N;j++){
            if(tmp[i][j]==-3){
                cnt=-10;
                flag=1;
                break;
            }
            if(board[i][j]==0)
                cnt=max(cnt,tmp[i][j]);
        }
    }
    if(cnt==-10) cnt=4000;

    return cnt;
}

void dfs(int k, int idx){
    if(k==M){
        ans=min(ans,bfs());
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
    if(ans==3000) ans=-1;
    cout << ans << '\n';

    return 0;
}
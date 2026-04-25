#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int INF=0x3f3f3f3f;

char board[22][22]; //x,y
int dist[11][11]; //nodes i -> j 거리 
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int dp[1<<11][11]; //vis, cur

vector<pair<int,int>> nodes;

int w,h;

void bfs(int idx){
    int sz=nodes.size();
    int d[22][22];
    bool vis[22][22];
    fill(&d[0][0], &d[0][0]+22*22, INF);
    fill(&vis[0][0], &vis[0][0]+22*22, false);

    auto cur=nodes[idx];
    d[cur.first][cur.second]=0;
    vis[cur.first][cur.second]=true;

    queue<pair<int,int>> q;
    q.push(nodes[idx]);
    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            if(nx<0||nx>=h||ny<0||ny>=w) continue;
            if(vis[nx][ny] || board[nx][ny]=='x') continue;
            vis[nx][ny]=true;
            d[nx][ny]=d[x][y]+1;
            q.push({nx,ny});
        }
    }
    for(int j=0;j<sz;j++){
        auto[x,y]=nodes[j];
        dist[idx][j]=d[x][y];
    }
}

int tsp(int v, int c){
    int sz=nodes.size();
    if(v==(1<<sz)-1){
        return 0;
    }
    if(dp[v][c]!=-1) return dp[v][c];

    int mn=INF;
    for(int nxt=0;nxt<sz;nxt++){
        if((v>>nxt)&1) continue;
        mn=min(mn, tsp(v|(1<<nxt), nxt)+dist[c][nxt]);
    }
    dp[v][c]=mn;
    return dp[v][c];    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(1){
        cin >> w >> h;
        if(w==0 && h==0) break;

        //초기화
        fill(&board[0][0], &board[0][0]+ 22*22, '.');
        fill(&dist[0][0], &dist[0][0]+ 11*11, INF);
        fill(&dp[0][0], &dp[0][0]+(1<<11)*11, -1);
        nodes.clear();

        //입력
        int st_i, st_j;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> board[i][j];
                if(board[i][j]=='o'){
                    st_i=i, st_j=j;
                }
                if(board[i][j]=='*'){
                    nodes.push_back({i,j});
                }
            }
        }

        //dist작성
        nodes.emplace(nodes.begin(), st_i,st_j);
        int sz=nodes.size();
        for(int i=0;i<sz;i++){
            bfs(i);
        }

        //도달 체크
        bool imp=false;
        for(int i=0;i<sz && !imp;i++){
            for(int j=0;j<sz && !imp;j++){
                if(i==j) continue;
                if(dist[i][j]==INF){
                    cout << -1 << '\n';
                    imp=true;
                }
            }
        }
        if(imp) continue;

        //tsp
        int st=0;
        cout << tsp(1<<st, st) << '\n';
    }

    return 0;
}

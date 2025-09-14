#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, G, R, ans=0;
vector<vector<int>> board;
vector<pair<int,int>> area;
vector<int> sel;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int bfs(){
    vector<vector<int>> color(N, vector<int>(M,0));
    vector<vector<int>> time(N, vector<int>(M,-1));
    queue<tuple<int, int, int ,int>> q; //x,y,color,time

    for(int i=0;i<area.size();i++){
        auto [x,y] =area[i];
        if(sel[i]==1){
            color[x][y] =1;
            time[x][y] =0;
            q.push({x,y,1,0});
        }
        if(sel[i]==2){
            color[x][y] =2;
            time[x][y] =0;
            q.push({x,y,2,0});
        }
    }
    int cnt =0;
    while(!q.empty()){
        auto [x,y,c,t] =q.front(); q.pop();
        if(color[x][y]==3) continue;
        for(int dir=0;dir<4;dir++){
            int nx =x+dx[dir];
            int ny =y+dy[dir];
            if(nx<0||ny<0||nx>=N||ny>=M) continue;
            if(board[nx][ny]==0 || color[nx][ny]==3) continue;
            if(color[nx][ny]==0){
                color[nx][ny] =c;
                time[nx][ny] =t+1;
                q.push({nx,ny,c,t+1});
            }
            else if(color[nx][ny]==1 && c==2 && time[nx][ny]==t+1){
                color[nx][ny] =3;
                cnt++;
            }
            else if(color[nx][ny]==2 && c==1 && time[nx][ny]==t+1){
                color[nx][ny] =3;
                cnt++;
            }
        }
    }
    return cnt;
}

void func(int d, int g, int r){
    if(g>G || r>R) return;
    if(d==area.size()){
        if(g==G && r==R){
            ans =max(ans, bfs());
        }
        return;
    }
    sel[d] =0;
    func(d+1, g, r);
    sel[d] =1;
    func(d+1, g+1, r);
    sel[d] =2;
    func(d+1, g, r+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> G >> R;
    board.assign(N,vector<int>(M,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> board[i][j];
            if(board[i][j]==2) area.push_back({i,j});
        }
    }
    sel.assign(area.size(),0);
    func(0,0,0);
    cout << ans;
    
    return 0;
}
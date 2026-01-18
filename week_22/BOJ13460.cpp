#include <iostream>
#include <queue>
using namespace std;

int N,M;
char board[12][12];
bool vis[12][12][12][12]; //***
int dx[4]{0,1,0,-1};
int dy[4]{1,0,-1,0};

struct State{
    int rx, ry, //빨간 구슬 좌표
        bx, by, //파란 구슬 좌표
        cnt;    //횟수
};

void sim(int& x, int& y, int& dist, int dir){
    while(board[x+dx[dir]][y+dy[dir]] != '#' && board[x][y] != 'O'){
        x+=dx[dir];
        y+=dy[dir];
        dist++;
    }
}

int bfs(State s){
    queue<State> q;
    q.push(s);
    vis[s.rx][s.ry][s.bx][s.by]=true;

    while(!q.empty()){
        State cur=q.front();
        q.pop();

        if(cur.cnt>=10) return -1;

        for(int i=0;i<4;i++){
            int nrx=cur.rx, nry=cur.ry,
                nbx=cur.bx, nby=cur.by,
                rdist=0, bdist=0; //두 구슬 겹칠 때 대비용
            sim(nrx,nry,rdist,i);
            sim(nbx,nby,bdist,i);
            if(board[nbx][nby]=='O') continue;
            if(board[nrx][nry]=='O') return cur.cnt+1;
            if(nrx==nbx && nry==nby){
                if(rdist>bdist){
                    nrx-=dx[i];
                    nry-=dy[i];
                }
                else{
                    nbx-=dx[i];
                    nby-=dy[i];
                }
            }
            if(!vis[nrx][nry][nbx][nby]){
                vis[nrx][nry][nbx][nby]=true;
                q.push({nrx,nry,nbx,nby,cur.cnt+1});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    State s;
    s.cnt=0;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> board[i][j];
            if(board[i][j]=='R'){
                s.rx=i;
                s.ry=j;
            }
            if(board[i][j]=='B'){
                s.bx=i;
                s.by=j;
            }
        }
    }
    cout << bfs(s) << '\n';

    return 0;
}

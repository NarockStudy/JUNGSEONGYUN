#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX=22;
const int INIT=2;
int N;
int board[MAX][MAX];
int dist[MAX][MAX];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};


vector<tuple<int,int,int>> bfs(int x, int y, int sh){
    //bfs 돌릴 때마다 vis 및 시작점 초기화
    for(int i=0;i<N;i++){
        memset(dist[i],-1,sizeof(dist[i]));
    }
    dist[x][y]=0;

    vector<tuple<int,int,int>> rtrn; //dist,r,c
    queue<pair<int,int>> q;
    
    q.push({x,y});
    while(!q.empty()){
        auto [x,y]=q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            if(nx<0||nx>=N||ny<0||ny>=N) continue;
            if(sh<board[nx][ny] || dist[nx][ny]!=-1) continue;
            dist[nx][ny]=dist[x][y]+1;
            q.push({nx,ny});

            //bfs로 전체 돌다가 먹을 수 있는 물고기 수집
            if(sh>board[nx][ny] && board[nx][ny]>0){
                rtrn.push_back({dist[nx][ny],nx,ny});
            }
        }
    }

    return rtrn;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    int shsz=INIT, shr=-1, shc=-1, shet=0, sht=0;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> board[i][j];
            if(board[i][j]==9) {
                shr=i, shc=j;
                board[i][j]=0;
            }
        }
    }

    while(1){
        vector<tuple<int,int,int>> v=bfs(shr,shc, shsz); //먹을 수 있는 물고기 집합
        if(v.empty()) break; //찾은 물고기가 없을 때 종료
        sort(v.begin(), v.end()); //dist,r,c순으로 정렬
        auto[d, r, c]=v[0];
        sht+=d;
        shr=r;
        shc=c;
        shet++;
        if(shsz==shet){
            shsz++;
            shet=0;
        }
        board[r][c]=0;  //먹은 자리 초기화
    }
    cout << sht;

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, L, R;
int board[52][52];
bool chk[52][52];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void chkMov(int r, int c, int& sum, vector<int> &vp){
    queue<pair<int,int>> q;
    chk[r][c]=true;
    vp.push_back(100*r+c);
    sum+=board[r][c];
    q.push({r,c});

    //bfs로 연결된 좌표 찾기
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int dir=0;dir<4;dir++){
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(chk[nx][ny]) continue;
            int diff=abs(board[x][y]-board[nx][ny]);
            if(L<=diff && diff<=R){
                chk[nx][ny]=true;
                vp.push_back(100*nx+ny);
                sum+=board[nx][ny];
                q.push({nx,ny});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> L >> R;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }

    int ans=0;

    while(1){
        bool no_mov=true;
        fill(&chk[0][0], &chk[0][0]+52*52, false);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(chk[i][j]) continue;
                vector<int> vp; //연결된 좌표 담는 배열
                int sum=0;      //연결된 좌표값들의 합
                chkMov(i,j,sum,vp); 
                if(vp.size()>=2){   //연결된 좌표가 있을 때
                    no_mov=false;
                    int avg=sum/vp.size();
                    for(int& i:vp){
                        int r=i/100;
                        int c=i%100;
                        board[r][c]=avg;
                    }
                }
            }
        }

        //종료조건: 더 이상 연결된 좌표 없음
        if(no_mov) break;

        ans++;
    }
    
    cout << ans;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int n,m,t;
int board[52][52];
int dx[4]={-1,0,1,0};   //북,동,남,서
int dy[4]={0,1,0,-1};
vector<pair<int,int>> wind; //[0]이 윗칸, [1]이 아랫칸

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> t;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j]==-1){
                wind.push_back({i,j});  //돌풍 위치 저장
            }
        }
    }

    //t초 동안 시뮬레이션
    while(t--){
        //1.먼지 확산
        int tmp[52][52]={0};    //tmp에 증감량 계산
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]<5) continue; //확산할 거 없으면 skip
                int dust=board[i][j]/5;
                for(int dir=0;dir<4;dir++){
                    int nx=i+dx[dir];
                    int ny=j+dy[dir];
                    if(nx<0||nx>=n||ny<0||ny>=m) continue;
                    if(board[nx][ny]==-1) continue;
                    tmp[i][j]-=dust;
                    tmp[nx][ny]+=dust;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j]+=tmp[i][j];
            }
        }

        //2.돌풍 청소
        //윗칸
        int dir=0;
        int x=wind[0].first-1;
        int y=wind[0].second;
        if(x<0){
            dir=1;
            x+=1;
            y+=1;
        }
        while(1){
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            if(nx<0||nx>wind[0].first||ny<0||ny>=m){   //범위 벗어나면 방향 바꾸기
                dir=(dir+1)%4;
                nx=x+dx[dir];
                ny=y+dy[dir];
            }
            if(board[nx][ny]==-1){  //윗칸 종료조건
                board[x][y]=0;
                break;
            }
            board[x][y]=board[nx][ny];
            x=nx;
            y=ny;
        }
        //아랫칸
        dir=2;
        x=wind[1].first+1;
        y=wind[1].second;
        if(x>=n){
            dir=1;
            x-=1;
            y+=1;
        }
        while(1){
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            if(nx<wind[1].first||nx>=n||ny<0||ny>=m){   //범위 벗어나면 방향 바꾸기
                dir=(dir-1+4)%4;
                nx=x+dx[dir];
                ny=y+dy[dir];
            }
            if(board[nx][ny]==-1){  //아랫칸 종료조건
                board[x][y]=0;
                break;
            }
            board[x][y]=board[nx][ny];
            x=nx;
            y=ny;
        }
    }

    //먼지 총합 계산
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sum+=board[i][j];
        }
    }
    sum+=2; //돌풍값 빼기

    cout << sum;

    return 0;
}
#include <iostream>
using namespace std;

int n, m;
int x, y, d;
int ans=0;
int dx[4]={-1,0,1,0};   //북,동,남,서
int dy[4]={0,1,0,-1};
int board[52][52];
bool vis[52][52];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin >> x >> y >> d;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }

    int cntd=0; //회전 횟수
    vis[x][y]=true; //시작칸 방문
    ans++;  //시작칸 카운팅
    while(1){
        d=(d+3)%4;  //좌회전
        int lx=x+dx[d], ly=y+dy[d]; //왼쪽칸 좌표
        //미방문==전진
        if(!vis[lx][ly] && !board[lx][ly]){
            //d=(d+3)%4;
            x+=dx[d];
            y+=dy[d];
            vis[x][y]=true;
            ans++;
            cntd=0;
        }
        //인도||방문==회전
        else{
            //d=(d+3)%4;
            cntd++;
        }
        //회전 4번==후진
        if(cntd==4){
            int bx=x-dx[d], by=y-dy[d];
            if(board[bx][by]) break; //후진 불가 시 종료 
            x=bx;
            y=by;
            cntd=0;
        }
    }

    cout << ans;

    return 0;
}
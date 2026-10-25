#include <iostream>
#include <vector>
using namespace std;

int n,m,k,c;
int tot;
vector<vector<int>> board;
int dx[4]={-1,0,1,0};   //북동남서
int dy[4]={0,1,0,-1};
int dr[4]={-1,-1,1,1};  //대각선 시계방향
int dc[4]={-1,1,1,-1};
bool done=false;    //더 이상 나무가 없을 때

void ctrl(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]<-19*c) board[i][j]++;
            if(board[i][j]==-19*c) board[i][j]=0;
        }
    }
}

void clean(){
    //위치 선정
    int x=-1,y=-1;    //제초제 뿌릴 위치
    int mx=0;   //제초 최댓값
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]<=0) continue; //나무 없는곳 제외
            bool chk[4]={false,};
            int sum=board[i][j];
            for(int mul=1;mul<=k;mul++){
                for(int d=0;d<4;d++){
                    if(chk[d]) continue;
                    int nx=i+dr[d]*mul;
                    int ny=j+dc[d]*mul;
                    if(nx<0||nx>=n||ny<0||ny>=n) continue;
                    if(board[nx][ny]<=0){
                        chk[d]=true;    //해당 방향 중단
                        continue;
                    }
                    if(board[nx][ny]>0){
                        sum+=board[nx][ny];
                    }
                }
            }
            if(sum>mx){ //등호 없어야 첫번째 값으로
                mx=sum;
                x=i;
                y=j;
            }
        }
    }
    //만약 더 이상 나무가 없으면 끝내기
    if(x==-1){
        done=true;
        return;
    }

    //제초
    board[x][y]=-20*c;
    bool chk[4]={false,};
    for(int mul=1;mul<=k;mul++){
        for(int d=0;d<4;d++){
            if(chk[d]) continue;
            int nx=x+dr[d]*mul;
            int ny=y+dc[d]*mul;
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(board[nx][ny]==-1){
                chk[d]=true;    //해당 방향 중단
                continue;
            }
            bool c2=false;
            if(board[nx][ny]<=0) c2=true;
            board[nx][ny]=-20*c;
            if(c2) chk[d]=true;
        }
    }
    tot+=mx;
}

void gg(){
    vector<vector<int>> gcnt(n,vector<int>(n,0));   //번식용보드 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]>0){
                //성장
                int cnt=0, cntz=0;
                for(int d=0;d<4;d++){
                    int nx=i+dx[d];
                    int ny=j+dy[d];
                    if(nx<0||nx>=n||ny<0||ny>=n) continue;
                    if(board[nx][ny]>0) cnt++;
                    if(board[nx][ny]==0) cntz++;
                }
                board[i][j]+=cnt;
                //번식
                for(int d=0;d<4;d++){
                    int nx=i+dx[d];
                    int ny=j+dy[d];
                    if(nx<0||nx>=n||ny<0||ny>=n) continue;
                    if(board[nx][ny]==0){
                        gcnt[nx][ny]+=(board[i][j])/cntz;
                    }
                }
            }
        }
    }

    //번식적용
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]+=gcnt[i][j];
        }
    }
}

void show(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k >> c;
    board.resize(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }

    while(m-- && !done){
        //1.성장 & 2.번식
        gg();

        //제초제 유지기간 관리
        ctrl();

        //3.제초
        clean();
    }

    cout << tot << '\n';

    return 0;
}
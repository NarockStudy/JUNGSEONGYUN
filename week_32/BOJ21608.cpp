#include <iostream>
using namespace std;

int N;
int board[22][22];
int likee[402][4]; // 좋아하는 학생 4명
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

// num이 st의 좋아하는 목록에 있는지
bool chk(int st, int num){
    for(int i=0;i<4;i++){
        if(likee[st][i]==num) return true;
    }
    return false;
}

// 자리 배정
void func(int st){
    int bx=0, by=0;
    int mlike=-1, mempty=-1;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]!=0) continue;

            int lcnt=0, ecnt=0;
            for(int dir=0;dir<4;dir++){
                int nx=i+dx[dir];
                int ny=j+dy[dir];

                if(nx<0||ny<0||nx>=N||ny>=N) continue;
                if(board[nx][ny]==0) ecnt++;
                else if(chk(st, board[nx][ny])) lcnt++;
            }

            // 1순위 좋아하는 학생 > 2순위 빈칸 > 3순위 행,열 작은순
            if(lcnt>mlike){
                mlike=lcnt;
                mempty=ecnt;
                bx=i; by=j;
            }
            else if(lcnt==mlike){
                if(ecnt>mempty){
                    mempty=ecnt;
                    bx=i; by=j;
                }
                else if(ecnt==mempty){
                    if(i<bx||(i==bx&&j<by)){
                        bx=i; by=j;
                    }
                }
            }
        }
    }
    board[bx][by]=st;
}

// 만족도 계산
int cal(){
    int score[5]={0,1,10,100,1000};
    int sum=0;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int st=board[i][j];
            int cnt=0;
            for(int dir=0;dir<4;dir++){
                int nx=i+dx[dir];
                int ny=j+dy[dir];
                if(nx<0||ny<0||nx>=N||ny>=N) continue;
                if(chk(st, board[nx][ny])) cnt++;
            }
            sum+=score[cnt];
        }
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i=0;i<N*N;i++){
        int st;
        cin >> st;
        for(int i=0;i<4;i++){
            cin >> likee[st][i];
        }
        func(st);
    }
    cout << cal() << '\n';

    return 0;
}

#include <iostream>
using namespace std;

int n;
int board[22][22];
int lv[402][4]; //선호 학생 기록표
int ords[402];  //입력 순서
int dr[4]={-1,0,0,1}; //북,서,동,남
int dc[4]={0,-1,1,0};
int scr[5]={0,1,10,100,1000};   //점수표

//현재칸 점수계산
int cal_score(int r, int c){
    int cur=board[r][c];
    int cnt_lv=0;
    for(int dir=0;dir<4;dir++){
        int nr=r+dr[dir];
        int nc=c+dc[dir];
        if(nr<0||nr>=n||nc<0||nc>=n) continue;
        int trg=board[nr][nc];
        for(int j=0;j<4;j++){
            if(lv[cur][j]==trg){
                cnt_lv++;
                break;
            }
        }
    }
    return scr[cnt_lv];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n*n;i++){
        int stud;
        cin >> stud;
        ords[i]=stud;
        for(int j=0;j<4;j++){
            cin >> lv[stud][j];
        }
    }
    
    //시뮬레이션 시작
    for(int i=0;i<n*n;i++){
        int cur=ords[i];
        int bst_r=-1, bst_c=-1;
        int bst_lv=-1, bst_emp=-1;
        //최적칸 찾기
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(board[r][c]!=0) continue;
                int cnt_lv=0;
                int cnt_emp=0;
                //4방향 탐색하며 현재칸 선호도 구하기
                for(int dir=0;dir<4;dir++){
                    int nr=r+dr[dir];
                    int nc=c+dc[dir];
                    if(nr<0||nr>=n||nc<0||nc>=n) continue;
                    int trg=board[nr][nc];
                    if(trg==0){
                        cnt_emp++;
                    }
                    else{
                        for(int j=0;j<4;j++){
                            if(lv[cur][j]==trg){
                                cnt_lv++;
                                break;
                            }
                        }
                    }
                }
                if(cnt_lv>bst_lv){
                    bst_r=r;
                    bst_c=c;
                    bst_lv=cnt_lv;
                    bst_emp=cnt_emp;
                }
                else if(cnt_lv==bst_lv){
                    if(cnt_emp>bst_emp){
                        bst_r=r;
                        bst_c=c;
                        bst_lv=cnt_lv;
                        bst_emp=cnt_emp;
                    }
                }
            }
        }
        //찾은 최적칸 board에 배치
        board[bst_r][bst_c]=cur;
    }
    
    //점수계산
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans+=cal_score(i,j);
        }
    }
    cout << ans;

    return 0;
}
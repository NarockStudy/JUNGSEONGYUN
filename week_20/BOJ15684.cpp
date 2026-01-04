#include <iostream>
using namespace std;

bool board[32][12];
int N,M,H;
int ans=4;

bool chk(){//시뮬레이션
    for(int j=1;j<=N;j++){
        int pos=j;//현재 위치
        for(int i=1;i<=H;i++){
            if(board[i][pos]) pos++;
            else if(pos>=2 && board[i][pos-1]) pos--;
        }
        if(pos!=j) return false;
    }
    return true;
}

void dfs(int k, int r, int c){//k==추가 가로선수
    if(k>=ans) return; //이미 더 좋은 답이 있으면 패스
    if(chk()){
        ans=k;
        return;
    }
    if(k==3) return; //최대3개까지
    //추가할 가로선 선택
    for(int i=r;i<=H;i++){
        int nc=(i==r? c:1); //첫줄만 c부터, 다음줄부턴 1
        for(int j=nc;j<=N-1;j++){
            if(board[i][j]) continue;
            if(j>=2 && board[i][j-1]) continue;
            if(j<=N-2 && board[i][j+1]) continue;
            board[i][j]=true;
            dfs(k+1,i,j+2); //현재 j에 가로선을 놓으면 j+2부터 가능
            board[i][j]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> H;
    while(M--){
        int a,b;
        cin >> a >> b;
        board[a][b]=true; //b~b+1 가로선 연결 
    }
    dfs(0,1,1);
    if(ans>=4) ans=-1;
    cout << ans << '\n';

    return 0;
}
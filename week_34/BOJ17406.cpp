#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

struct infoT{
    int r;
    int c;
    int s;
};

int N,M,K;
int ans=INF;
int board[52][52];
bool vis[8];
vector<infoT> vt;  //연산 정보 저장

void doT(int r, int c, int s){
    for(int d=1;d<=s;d++){
        int tmp=board[r-d][c-d];
        for(int i=r-d;i<r+d;i++){
            board[i][c-d]=board[i+1][c-d];
        }
        for(int j=c-d;j<c+d;j++){
            board[r+d][j]=board[r+d][j+1];
        }
        for(int i=r+d;i>r-d;i--){
            board[i][c+d]=board[i-1][c+d];
        }
        for(int j=c+d;j>c-d;j--){
            board[r-d][j]=board[r-d][j-1];
        }
        board[r-d][c-d+1]=tmp;
    }
}

void unT(int r, int c, int s){
    for(int d=1;d<=s;d++){
        int tmp=board[r-d][c-d];
        for(int j=c-d;j<c+d;j++){
            board[r-d][j]=board[r-d][j+1];
        }
        for(int i=r-d;i<r+d;i++){
            board[i][c+d]=board[i+1][c+d];
        }
        for(int j=c+d;j>c-d;j--){
            board[r+d][j]=board[r+d][j-1];
        }
        for(int i=r+d;i>r-d;i--){
            board[i][c-d]=board[i-1][c-d];
        }
        board[r-d+1][c-d]=tmp;
    }
}

int chkMn(){
    int mn=INF;
    for(int i=1;i<=N;i++){
        int sum=0;
        for(int j=1;j<=M;j++){
            sum+=board[i][j];
        }
        mn=min(mn,sum);
    }
    return mn;
}

void dfs(int k){
    if(k==K){
        ans=min(ans,chkMn());
        return;
    }
    for(int i=0;i<K;i++){
        if(vis[i]) continue;
        vis[i]=true;
        infoT t=vt[i];
        int r=t.r, c=t.c, s=t.s;
        doT(r,c,s);
        dfs(k+1);
        vis[i]=false;
        unT(r,c,s);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> board[i][j];
        }
    }
    for(int i=0;i<K;i++){
        int r,c,s;
        cin >> r >> c >> s;
        vt.push_back({r,c,s});
    }
    dfs(0);

    cout << ans;

    return 0;
}
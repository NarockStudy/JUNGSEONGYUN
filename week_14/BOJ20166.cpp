//dfs로 최대5자까지 만들 수 있는 문자열을 u_map에 넣어서 개수 세기
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N,M,K;
vector<string> board;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
unordered_map<string,int> um;

void dfs(int x, int y, string s){
    um[s]++;
    if(s.size()==5) return;
    for(int d=0;d<8;d++){
        int nx=(x+dx[d]+N)%N;
        int ny=(y+dy[d]+M)%M;
        //dfs(nx,ny,s+board[nx][ny]);
        s.push_back(board[nx][ny]);
        dfs(nx,ny,s);
        s.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    board.resize(N);
    for(int i=0;i<N;i++) cin >> board[i];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            string s;
            s.push_back(board[i][j]);
            dfs(i,j,s);
        }
    }
    while(K--){
        string s;
        cin >> s;
        cout << um[s] << '\n';
    }

    return 0;
}
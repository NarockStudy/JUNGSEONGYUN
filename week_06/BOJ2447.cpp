#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> board;

void rec(int n, int r, int c){
    if(n==1){
        board[r][c]='*';
        return;
    }
    int half=n/3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==1 && j==1) continue;
            rec(half, r+half*i, c+half*j);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    board.assign(N,string(N, ' '));
    rec(N,0,0);
    for(auto s:board)
        cout << s << '\n';

    return 0;
}
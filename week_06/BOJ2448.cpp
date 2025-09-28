#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> board; //N * 2N-1

void rec(int n, int r, int c){
    if(n==3){
        board[r][c+2] ='*';
        board[r+1][c+1] ='*';
        board[r+1][c+3] ='*';
        for(int i=0;i<5;i++) board[r+2][c+i] ='*';
        return;
    }
    int half=n/2;
    rec(half, r, c+half);
    rec(half, r+half, c);
    rec(half, r+half, c+2*half);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    board.assign(N,string(2*N-1, ' '));
    rec(N,0,0);
    for(auto s:board)
        cout << s << '\n';

    return 0;
}
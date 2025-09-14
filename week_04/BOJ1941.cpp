#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char board[5][5];
bool choos[5][5];
int ans = 0;
int dx[4]{1,0,-1,0};
int dy[4]{0,1,0,-1};
vector<int> vec(7);

bool bfs_connect(){
    queue<pair<int, int>> qu;
    bool isused[5][5] = {false,};
    int cnt=0;
    int x=vec[0]/5;
    int y=vec[0]%5;
    isused[x][y] = true;
    qu.push({x,y});
    cnt++;

    while(!qu.empty()){
        auto cur = qu.front();
        qu.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int my = cur.second + dy[i];

            if(nx<0||nx>=5||my<0||my>=5) continue;
            if(!choos[nx][my]|| isused[nx][my]) continue;

            qu.push({nx, my});
            isused[nx][my] = true;
            cnt++;
        }
    }
    return cnt==7;
}

void func(int brd, int depth, int som){
    if(som+7-depth<4) return;
    if(depth==7){
        if(som>=4 && bfs_connect()) ans++;
        return;
    }
    if(brd>25) return;
    int x = brd/5;
    int y = brd%5;
    
    choos[x][y] = true;
    vec[depth] = brd;
    func(brd+1, depth+1, som+(board[x][y]=='S'));

    choos[x][y] = false;
    func(brd+1, depth, som);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            cin >> board[i][j];
    
    func(0, 0, 0);

    cout << ans;

    return 0;
}
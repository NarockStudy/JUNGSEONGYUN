#include <iostream>
#include <vector>
using namespace std;

bool board[102][102];
//방향은 순대로 0,1,2,3
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

int cnt(){
    int ans=0;
    for(int y=0;y<100;y++){
        for(int x=0;x<100;x++){
            if(board[y][x] && board[y][x+1] && board[y+1][x] && board[y+1][x+1]) ans++;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    while(N--){
        int x,y,d,g;
        cin >> x >> y >> d >> g;
        board[y][x]=true;
       //방향 정하기
        vector<int> dir;
        dir.push_back(d);
        for(int i=0;i<g;i++){//각 세대별로 현재 있는 방향에 +1된 방향을 뒤로 넣기
            int siz=dir.size();
            for(int j=siz-1;j>=0;j--){
                dir.push_back((dir[j]+1)%4);
            }
        }
        //선그리기
        int nx=x, ny=y;
        for(auto dd:dir){
            nx+=dx[dd];
            ny+=dy[dd];
            if(0<=nx && nx<=100 && 0<=ny && ny<=100)    board[ny][nx]=true;
        }
    }
    cout << cnt() << '\n';

    return 0;
}
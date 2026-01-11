#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int board[22][22]{-1,};
int dx[5]{0,0,0,-1,1};
int dy[5]{0,1,-1,0,0};
int d[7]{0,}; //1~6이 TOP, 북, 동, 서, 남, BOTTOM(전개도랑 같음)

void chg(int dir){
    if(dir==1){
        swap(d[1],d[4]);
        swap(d[4],d[6]);
        swap(d[6],d[3]);
    }
    else if(dir==2){
        swap(d[1],d[3]);
        swap(d[3],d[6]);
        swap(d[6],d[4]);
    }
    else if(dir==3){
        swap(d[1],d[5]);
        swap(d[5],d[6]);
        swap(d[6],d[2]);
    }
    else if(dir==4){
        swap(d[1],d[2]);
        swap(d[2],d[6]);
        swap(d[6],d[5]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x,y, K;
    
    //input
    cin >> N >> M >> x >> y >> K;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin >> board[i][j];
    
    //simulation
    for(int i=0;i<K;i++){
        int dir;
        cin >> dir;
        int nx=x+dx[dir];
        int ny=y+dy[dir];
        if(nx<0 || nx>=N || ny<0 || ny>=M) continue;

        x=nx, y=ny;
        chg(dir);
        if(board[x][y]==0)  board[x][y]=d[6];
        else{
            d[6]=board[x][y];
            board[x][y]=0;
        }
        cout << d[1] << '\n';
    }

    return 0;
}
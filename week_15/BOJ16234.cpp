#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,L,R;
int board[52][52];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool vis[52][52];
 
int bfs(){
    int ans=0;
    while(1){
        fill(&vis[0][0],&vis[0][0]+sizeof(vis),false);
        bool chk=false; //변화 없음 감지용

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(!vis[i][j]){
                    queue<pair<int,int>> q;
                    vector<pair<int, int>> v;
                    q.push({i,j});
                    vis[i][j]=true;
                    v.push_back({i,j});
                    int sum=board[i][j];
                    
                    while(!q.empty()){
                        auto [x,y]=q.front();
                        q.pop();
                        for(int dir=0;dir<4;dir++){
                            int nx=x+dx[dir];
                            int ny=y+dy[dir];
                            if(nx>=0 && nx<N && ny>=0 && ny<N && !vis[nx][ny]){
                                int a=board[x][y];
                                int b=board[nx][ny];
                                int ab=abs(a-b);
                                if(L<=ab && ab<=R){
                                    vis[nx][ny]=true;
                                    q.push({nx,ny});
                                    v.push_back({nx,ny});
                                    sum+=board[nx][ny];
                                }
                            }
                        }
                    }//탐색끝
                    
                    //인구이동
                    if(v.size()>1){
                        chk=true;
                        int numm=sum/v.size();
                        for(auto p:v){
                            board[p.first][p.second]=numm;
                        }
                    }
                }
            }
        }
        if(!chk) break;
        ans++;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> L >> R;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> board[i][j];
        }
    }
    cout << bfs() << '\n';

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;  

typedef struct{
    int k;
    int r;
    int c;
    int w;
    int h;
} Block;

int N, M;
int board[52][52];
map<int, Block> mapB;

//(r-h+1 ~ r), (c ~ c+w-1)
void setP(int k, int c, int w, int h){
    int r=h;
    bool flag=false;

    //최하지점 찾기
    for(int i=h+1;i<=N;i++){
        for(int j=c;j<c+w;j++){
            if(board[i][j]){
                flag=true;
                break;
            }
        }
        if(flag) break;
        r=i;
    }

    //세팅
    for(int i=r-h+1;i<=r;i++){
        for(int j=c;j<c+w;j++){
            board[i][j]=k;
        }
    }

    //블록 저장
    Block b={k,r-h+1,c,w,h};
    mapB[k]=b;
}

void downP(){
    vector<Block> blocks;
    for(auto& b:mapB){
        blocks.push_back(b.second);
    }
    
    sort(blocks.begin(), blocks.end(),
    [](Block& a, Block& b){
        return a.r+a.h-1 > b.r+b.h-1;
    });

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            board[i][j]=0;
        }
    }

    for(auto& b:blocks){
        setP(b.k,b.c,b.w,b.h);
    }
}

void showB(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout << board[i][j] << '\t';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    //1.택배 투입
    for(int i=0;i<M;i++){
        int k,c,w,h;
        cin >> k >> h >> w >> c;
        setP(k,c,w,h);
    }

    while(!mapB.empty()){

        //2.택배 하차_좌
        int dr, dc, dh, dw, dk;
        for(auto& b:mapB){
            int r=b.second.r;
            int c=b.second.c;
            int h=b.second.h;
            int w=b.second.w;
            int k=b.second.k;
            bool flag=false;
            for(int i=r;i<r+h;i++){
                for(int j=1;j<c;j++){
                    if(board[i][j]){
                        flag=true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) continue;
            dr=r;
            dc=c;
            dh=h;
            dw=w;
            dk=k;
            break;
        }
        mapB.erase(dk);
        for(int i=dr;i<dr+dh;i++){
            for(int j=dc;j<dc+dw;j++){
                board[i][j]=0;
            }
        }
        downP();
        cout << dk << '\n';
        if(mapB.empty()) break;

        //3.택배 하차_우
        for(auto& b : mapB){
            int r = b.second.r;
            int c = b.second.c;
            int h = b.second.h;
            int w = b.second.w;
            int k = b.second.k;
            bool flag = false;

            for(int i = r; i < r+h; i++){
                for(int j = c+w; j <= N; j++){
                    if(board[i][j]){
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) continue;
            dr = r;
            dc = c;
            dh = h;
            dw = w;
            dk = k;
            break;
        }

        mapB.erase(dk);
        for(int i = dr; i < dr+dh; i++){
            for(int j = dc; j < dc+dw; j++){
                board[i][j] = 0;
            }
        }

        downP();
        cout << dk << '\n';
    }


    return 0;
}
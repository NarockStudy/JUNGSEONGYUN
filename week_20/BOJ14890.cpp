#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int board[101][101];
int ans=0;
int N,L;

bool chk(vector<int>& l){
    vector<bool> used(N,false); //경사로 사용 여부
    for(int i=0;i<N-1;i++){
        int diff=l[i]-l[i+1];
        if(diff==0) continue;
        if(abs(diff)>1) return false;
        if(diff==1){//내리막길
            for(int k=1;k<=L;k++){
                int idx=i+k;
                if(idx>=N) return false;
                if(used[idx]) return false;
                if(l[i+1]!=l[idx]) return false;
            }
            for(int k=1;k<=L;k++){
                used[i+k]=true;
            }
            //i+=(L-1); used에 의해 걸러지지만 중복방지용 
        }
        if(diff==-1){//오르막길
            for(int k=0;k<L;k++){
                int idx=i-k;
                if(idx<0) return false;
                if(used[idx]) return false;
                if(l[i]!=l[idx]) return false;
            }
            for(int k=0;k<L;k++){
                used[i-k]=true;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> L;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> board[i][j];

    for(int i=0;i<N;i++){
        vector<int> hl;
        for(int j=0;j<N;j++)    hl.push_back(board[i][j]);
        if(chk(hl)) ans++;
    }

    for(int j=0;j<N;j++){
        vector<int> vl;
        for(int i=0;i<N;i++)    vl.push_back(board[i][j]);
        if(chk(vl)) ans++;
    }
    cout << ans << '\n';

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> va;
vector<int> ijk;
int ans=0;

//완전탐색
void dfs(int kk, int idx){
    if(kk==3){
        int i,j,k;
        i=ijk[0];
        j=ijk[1];
        k=ijk[2];
        if(va[i]<va[j] && va[i]>va[k]) ans++;
        return;
    }
    if(idx>=N) return;
    for(int i=idx;i<N;i++){
        ijk.push_back(i);
        dfs(kk+1,i+1);
        ijk.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //입력
    cin >> N;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        va.push_back(a);
    }

    
    //i값 고정시키고 j,k 조합 찾기
    for(int i=0;i<N-1;i++){
        int cnt=0;
        for(int j=i+1;j<N;j++){
            if(va[i]<va[j]) cnt++;  //가능한 j count
            else ans+=cnt;          //가능한 k count
        }
    }

    //dfs(0,0);

    cout << ans;

    return 0;
}
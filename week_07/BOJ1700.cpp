#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    int ans=0;
    vector<int> v(K,0); //입력
    vector<int> n(N,0); //현재
    for(int i=0;i<K;i++)
        cin >> v[i];
    for(int i=0;i<K;i++){
        //이미 꽂혀 있는 경우
        if(find(n.begin(), n.end(), v[i])!=n.end()) continue;
        //비어있는 경우
        bool chk=false;
        for(int m=0;m<N;m++){
            if(n[m]==0){
                n[m]=v[i];
                chk=true;
                break;
            }
        }
        if(chk) continue;
        //뽑아야 하는 경우
        int maxx=0, idx=0;
        for(int j=0;j<N;j++){
            int dist=K;
            for(int l=i+1;l<K;l++){
                if(n[j]==v[l]){
                    dist=l;
                    break;
                }
            }
            if(dist==K){
                idx=j;
                break;
            }
            if(dist>maxx){
                idx=j;
                maxx=dist;
            }
        }
        n[idx]=v[i];
        ans++;
    }
    cout << ans << '\n';

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,q;
vector<int> efficiency;
vector<int> m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >>q;

    efficiency.resize(n);
    for(int i=0;i<n;i++){
        cin>>efficiency[i];
    }

    m.resize(q);
    for(int i=0;i<q;i++){
        cin>>m[i];
    }

    sort(efficiency.begin(),efficiency.end());  //이분탐색 위해 오름차순 정렬

    for(int i=0;i<q;i++){
        int idx=lower_bound(efficiency.begin(),efficiency.end(),m[i])-efficiency.begin();   //m[i] 이상인 첫 위치 = m[i]보다 작은 연비 개수
        if(idx==n||efficiency[idx]!=m[i]){  //해당 연비 없으면 0
            cout << 0 << '\n';
            continue;
        }
        int ans=idx*(n-1-idx); //작은쪽 1개 * 큰쪽 1개
        cout << ans <<'\n';
    }

    return 0;
}
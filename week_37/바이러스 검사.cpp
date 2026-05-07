#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ans=0;
    int n;
    cin >> n;
    vector<int> c(n);
    for(int i=0;i<n;i++)
        cin >> c[i];
    int l,m;
    cin >> l >> m;
    for(int i=0;i<n;i++){
        int cur=c[i];
        if(cur<=l){
            ans++;
            continue;
        }
        cur-=l; ans++;
        ans+=(cur+m-1)/m;
    }

    cout << ans;

    return 0;
}
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    unordered_map<string, int> um;
    int K, L;
    cin >> K >> L;
    for(int i=0;i<L;i++){
        string a;
        cin >> a;
        //if(um.find(a)!=um.end()) um.erase(a);
        um[a]=i;
    }
    vector<pair<string, int>> vp(um.begin(),um.end());
    sort(vp.begin(), vp.end(), [](auto& a, auto& b){return a.second<b.second;});
    //실제 수강신청 인원이 L보다 작을 수 있음 
    K=min(K, (int)vp.size());
    for(int i=0;i<K;i++){
        cout << vp[i].first << '\n';
    }

    return 0;
}
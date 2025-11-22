#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    unordered_map<string, string> um;
    int N, M;
    cin >> N >> M;
    while(N--){
        string s,p;
        cin >> s >> p;
        um[s]=p;
    }
    while(M--){
        string s;
        cin >> s;
        cout << um[s] << '\n';
    }

    return 0;
}
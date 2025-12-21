#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    vector<string> vs;
    int a=s.size();
    for(int i=0;i<a;i++){
        vs.push_back(s);
        s.erase(s.begin());
    }
    sort(vs.begin(), vs.end());
    for(auto s: vs)
        cout << s << '\n';

    return 0;
}
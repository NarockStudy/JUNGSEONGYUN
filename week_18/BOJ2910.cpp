#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, C;
    cin >> N >> C;
    vector<pair<int,int>> vin; // {cnt, num}
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        bool chk=false;
        for(auto& p: vin){
            if(p.second==x){
                chk=true;
                p.first++;
                break; //뒤까지 탐색 필요x
            }
        }
        if(!chk) vin.push_back({1,x});
    }
    stable_sort(vin.begin(), vin.end(), [](auto a, auto b){return a.first>b.first;});
    for(auto p:vin){
        for(int i=0;i<p.first;i++)
            cout << p.second << ' ';
    }

    return 0;
}
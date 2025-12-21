#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct st
{
    string s="";
    int n1=0;
    int n2=0;
    int n3=0;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<st> vst(N);
    for(int i=0;i<N;i++){
        cin >> vst[i].s >> vst[i].n1 >> vst[i].n2 >> vst[i].n3;
    }

    sort(vst.begin(),vst.end(), [](st& a, st& b){
        if(a.n1 != b.n1) return a.n1 > b.n1;
        if(a.n2 != b.n2) return a.n2 < b.n2;
        if(a.n3 != b.n3) return a.n3 > b.n3;
        return a.s < b.s;
    });

    for(auto& st: vst)
        cout << st.s << '\n';

    return 0;
}
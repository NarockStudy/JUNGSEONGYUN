#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<pair<int, string>> vp(N);
	for (int i = 0;i < N;i++) {
		cin >> vp[i].first >> vp[i].second;
	}
    // stable_sort(vp.begin(), vp.end()) 를 그대로 쓰면?
    // pair<int,string> 의 기본 비교는 사전식 비교라서
    // 1) first(나이)가 같으면
    // 2) second(이름)까지 비교해 정렬해버림.
	stable_sort(vp.begin(), vp.end(), [](auto& a, auto& b){return a.first<b.first;});
	for (int i = 0;i < N;i++)
		cout << vp[i].first << " " << vp[i].second << "\n";

	return 0;
}
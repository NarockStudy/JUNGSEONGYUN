#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<pair<int, int>> vp(N);
	for (int i = 0;i < N;i++) {
		cin >> vp[i].first >> vp[i].second;
	}

	sort(vp.begin(), vp.end());
	for (int i = 0;i < N;i++)
		cout << vp[i].first << " " << vp[i].second << "\n";

	return 0;
}
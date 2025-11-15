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
	vector<int> vec(N);
    for (int i = 0; i < N; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());
	for (const auto& i : vec)
		cout << i << '\n';

	return 0;
}
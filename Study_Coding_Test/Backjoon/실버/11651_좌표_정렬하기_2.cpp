#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<pair<int, int>> pos(N);
	for (int i = 0; i < N; i++)
		cin >> pos[i].second >> pos[i].first;

	sort(pos.begin(), pos.end());

	for (int i = 0; i < N; i++)
		cout << pos[i].second << " " << pos[i].first << "\n";

	return 0;
}
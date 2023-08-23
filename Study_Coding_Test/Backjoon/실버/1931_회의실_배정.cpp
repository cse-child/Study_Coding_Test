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
	vector<pair<int, int>> times(N);
	for (pair<int, int>& time : times)
		cin >> time.second >> time.first;

	sort(times.begin(), times.end());

	int cnt = 1;
	int end = times[0].first;
	for(int i = 1; i < N; i++)
	{
		if (end <= times[i].second)
		{
			cnt++;
			end = times[i].first;
		}
	}
	cout << cnt;

	return 0;
}
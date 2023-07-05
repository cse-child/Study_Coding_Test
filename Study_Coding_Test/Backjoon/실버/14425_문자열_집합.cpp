#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<string> S(N);
	for (string& s : S)
		cin >> s;

	sort(S.begin(), S.end());

	int cnt = 0;
	for(int i = 0; i < M; i++)
	{
		string input;
		cin >> input;

		if (binary_search(S.begin(), S.end(), input))
			cnt++;
	}

	cout << cnt;
	return 0;
}
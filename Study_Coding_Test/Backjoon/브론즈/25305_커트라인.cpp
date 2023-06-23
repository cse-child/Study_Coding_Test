#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, k;
	cin >> N >> k;

	vector<int> score(N);
	for (int& s : score)
		cin >> s;

	sort(score.begin(), score.end(), greater<int>());

	cout << score[k - 1];

	return 0;
}
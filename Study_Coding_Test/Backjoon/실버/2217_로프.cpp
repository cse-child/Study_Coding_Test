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
	vector<int> Weight(N);
	for (int& w : Weight)
		cin >> w;

	sort(Weight.begin(), Weight.end());

	int total = 0;
	for(int i = 0; i < N; i++)
	{
		int w = Weight[i] * (N - i);
		total = max(total, w);
	}
	cout << total;
	return 0;
}
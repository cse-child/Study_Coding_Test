#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	vector<int> coins(N);
	for (int& coin : coins)
		cin >> coin;

	int cnt = 0;
	for(int i = coins.size()-1; i >= 0; i--)
	{
		cnt += K / coins[i];
		K -= (coins[i] * (K / coins[i]));

		if (K <= 0) break;
	}
	cout << cnt;
	return 0;
}
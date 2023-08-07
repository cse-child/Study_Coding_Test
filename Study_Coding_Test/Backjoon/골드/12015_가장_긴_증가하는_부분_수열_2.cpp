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
	vector<int> A(N);
	for (int& a : A)
		cin >> a;

	vector<int> dp(N);
	for(int i = 0; i < N; i++)
	{
		dp[i] = 1;
		for(int j = 0; j < i; j++)
		{
			if (A[i] > A[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	sort(dp.begin(), dp.end());
	cout << dp[N-1];
	return 0;
} 
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	int dp[1000001];
	dp[1] = 0;
	dp[2] = dp[3] = 1;

	for(int i = 4; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;

		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
	}


	// N = 2 -> N-1 or N/2;  => 1
	// N = 3 -> N/3;		 => 1
	// N = 4 -> N/2 -> N = 2 => 1+1
	// N = 5 -> N-1 -> N = 4 => 1+2
	// N = 6 -> N/3 -> N = 3 => 1+1

	// N = 9 -> N/3 -> N = 3 => 1+1

	// 10 -> 5 -> 4 -> 2 -> 1, dp[10/2]
	// 10 -> 9 -> 3 -> 1, dp[10-1] => 3

	// 11 -> 10 -> 3+1 => 4
	// 12 -> 11 -> 4+1 => 5
	// 12 -> 6 -> 1+2 => 3
	cout << dp[N];
	return 0;
}
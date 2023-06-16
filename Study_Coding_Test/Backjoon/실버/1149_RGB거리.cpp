#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int dp[1001][3]; // 0:r, 1:g, 2:b
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int rgb[3];
		cin >> rgb[0] >> rgb[1] >> rgb[2];

		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[2];
	}
	cout << min(dp[N][0], min(dp[N][1], dp[N][2]));
	return 0;
}
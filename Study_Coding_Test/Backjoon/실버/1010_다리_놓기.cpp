#include <iostream>
#include <string>

using namespace std;

/* 1. nCr 풀이 방법 */
/*int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	while(T--)
	{
		int N, M;
		cin >> N >> M;

		int result = 1, temp = 1;
		// nCm 공식
		for(int i = M; i > M-N; i--)
		{
			result *= i;
			result /= temp++;
		}
		cout << result << '\n';
	}

	return 0;
}
*/


/* 2. dp 풀이방법 */

const int MAX = 30;

int dp[MAX+1][MAX+1];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// dp[1][5] = 5, dp[1][10] = 10, ... dp[1][n] = n
	// dp[2][3] = dp[2][1] + dp[1][2];
	// dp[n][m] = dp[n-1][m-1] + dp[n-1][m-2] + dp[n-1][m-3] + ... + dp[n-1][n-1]

	for(int i = 1; i <= MAX; i++)
		dp[1][i] = i;

	for(int i = 2; i <= MAX; i++)
		for (int j = 1; j <= MAX; j++)
			for (int k = j; k >= 1; k--)
				dp[i][j] = dp[i][j] + dp[i - 1][k-1];

	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;

		cout << dp[N][M] << '\n';
	}

	return 0;
}
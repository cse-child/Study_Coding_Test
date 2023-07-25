#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, K;
	cin >> N >> K;
	vector<pair<int, int>> Objects(N+1); // 무게, 가치
	for (int i = 1; i <= N; i++)
		cin >> Objects[i].first >> Objects[i].second;

	vector<vector<int>> dp(N + 1, vector<int>(K + 1));
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= K; j++)
		{
			if (j >= Objects[i].first)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - Objects[i].first] + Objects[i].second);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N][K];
	return 0;
}
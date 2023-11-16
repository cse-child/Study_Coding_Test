#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int dp[1001][32][3]; // [T][W][3]
int plum[1001][3];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T, W;
	cin >> T >> W;

	for (int i = 1; i <= T; i++)
	{
		int input;
		cin >> input;
		plum[i][input] = 1;
	}

	dp[1][0][1] = plum[1][1];
	dp[1][1][2] = plum[1][2];

	int result = max(dp[1][0][1], dp[1][1][2]);
	for(int i = 2; i <= T; i++)
	{
		for(int j = 0; j <= W; j++)
		{
			// dp[시간][이동횟수][위치]
			// 이동해서 1에 있다가 그대로 1에 있음, 이동 안하고(j-1) 2에 있다가 j 되면서 1로 옴
			dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + plum[i][1];
			// 이동 안하고 1에 있다가 j 되면서 2로 옴, 이동해서 2에있다가 그대로 2에 있음
			dp[i][j][2] = max(dp[i - 1][j - 1][1], dp[i - 1][j][2]) + plum[i][2];

			result = max(max(result, dp[i][j][1]), dp[i][j][2]);
		}
	}

	cout << result;

	return 0;
}
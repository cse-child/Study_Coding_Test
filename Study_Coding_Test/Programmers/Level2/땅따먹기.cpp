// 16Ка

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> land)
{
	vector<vector<int>> dp(land.size(), vector<int>(4));
	for (int i = 0; i < 4; i++)
		dp[0][i] = land[0][i];

	for(int i = 1; i < land.size(); i++)
	{
		for(int j = 0; j < 4; j++)
		{
			int maxNum = 0;
			for(int k = 0; k < 4; k++)
			{
				if (j == k) continue;
				maxNum = max(maxNum, dp[i - 1][k]);
			}
			dp[i][j] = maxNum + land[i][j];
		}
	}

	return *max_element(dp[land.size()-1].begin(), dp[land.size() - 1].end());
}

int main()
{
	vector<vector<int>> land = { {1,2,3,5}, {5,6,7,8}, {4,3,2,1} };
	cout << solution(land);
}
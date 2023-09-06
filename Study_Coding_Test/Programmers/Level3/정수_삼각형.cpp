#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;

	vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size()));
	dp[0][0] = triangle[0][0];

	for(int i = 1; i < triangle.size(); i++)
	{
		for(int j = 0; j < triangle[i].size(); j++)
		{
			if (j - 1 >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
			else
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
		}
	}

	int maxDP = 0;
	for (int i = 0; i < triangle.size(); i++)
		maxDP = max(maxDP, dp[triangle.size() - 1][i]);

	return maxDP;
}

int main()
{
	vector<vector<int>> triangle = { {7},{3, 8},{8, 1, 0},{2, 7, 4, 4},{4, 5, 2, 6, 5} };
	cout << solution(triangle);
}
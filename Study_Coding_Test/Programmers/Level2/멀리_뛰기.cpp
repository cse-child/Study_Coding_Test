#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[2001];

long long solution(int n) {
	dp[1] = dp[2] = 1;

	for(int i = 2; i <= n; i++)
	{
		dp[i] += (dp[i - 1] + dp[i - 2]) % 1234567;
	}

	return dp[n];
}

// 베스트 풀이..
int Jump(int num)
{
	return num < 2 ? 1 : Jump(num - 1) + Jump(num - 2);
}

int main()
{
	cout << solution(3) << endl;
	cout << Jump(4) << endl;
}
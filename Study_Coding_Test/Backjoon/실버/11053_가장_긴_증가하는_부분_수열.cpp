#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int S;
	cin >> S;
	vector<int> A(S);
	for (int& a : A)
		cin >> a;

	int dp[1001];
	//fill(begin(dp), end(dp), 1); // memset은 0또는 -1로만 초기화 가능, 다른 숫자는 비트값으로 들어감

	// 시간복잡도: O(n^2)
	for (int i = 0; i < S; i++)
	{
		dp[i] = 1;
		for(int j = 0; j < i; j++)
		{
			if (A[i] > A[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	sort(begin(dp), end(dp), greater<>());
	cout << dp[0];
	return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int dp[1001]; // 전역변수로 선언 안하면 1% 오답

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<int> arr(N);
	for (int& a : arr)
		cin >> a;

	for(int i = 0; i < N; i++)
	{
		dp[i] = 1;
		for(int j = 0; j < i; j++)
		{
			if(arr[i] < arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	sort(begin(dp), end(dp), greater<>());
	cout << dp[0];
	return 0;
}
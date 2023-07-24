#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> coin(n);
	for (int& c : coin)
		cin >> c;

	/*
	 *		1	2	3	4	5	6	7	8	9	10
	 *	1	1	1	1	1	1	1	1	1	1	1
	 *	2	0	1	1	2	2	3	3	4	4	5
	 *	5	0	0	0	0	1	1	2	2	3	4
	 *
	 *	t1	1	2	2	3	3	4	4	5	5	6
	 *	t2	1	2	2	3	4	5	6	7	8	10
	 */

	vector<int> dp(k + 1);
	dp[0] = 1;
	for(int i = 0; i < n; i++)
	{
		for (int j = coin[i]; j <= k; j++)
			dp[j] += dp[j - coin[i]];
	}
	cout << dp[k];

	return 0;
}